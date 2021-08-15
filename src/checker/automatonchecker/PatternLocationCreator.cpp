/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <llvm/Support/raw_ostream.h>

#include "clang/AST/Decl.h"
#include <clang/AST/Stmt.h>
#include <clang/Analysis/CFG.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h>

#include <QDebug>
#include <QList>
#include <QMap>
#include <QPair>
#include <QSet>
#include <QString>

#include "../../codestructures/traversal/CFGTraversal.h"
#include "../../codestructures/CFGsNavigator.h"
#include "../../codestructures/PassingSolver.h"
#include "../../utils/xmlpatterns/XMLPattern.h"

#include "NodeLocationDictionary.h"
#include "PatternLocationCreator.h"
#include "XMLAutomatonDefinition.h"
#include "XMLTransitionRule.h"

using namespace checker;

#if 0
void PatternLocationCreator::checkMatchingConflict(const Element element,
		    const QList<QPair<XMLPattern, SimpleAutomatonID>> matchings) {
	    if (!logger.isDebugEnabled())
		    return;

	    bool same = true;
	    const Set<QString> names = new QSet<QString>();
	    names.add(matchings.getFirst().getFirst().getName());
	    for (const QPair<XMLPattern,SimpleAutomatonID> match : matchings)
		    if (names.add(match.getFirst().getName())) {
			    same = false;
			    break;
		    }
	    if (!same) {
		    logger.debug("This code:");
		    logger.debug(element.asXML());
		    logger.debug("can be matched by more than one " +
			    "distinct rule:");
		    for (const QPair<XMLPattern,SimpleAutomatonID> match :
				    matchings) {
			    const XMLPattern pat = match.getFirst();
			    logger.debug(pat.getName() + ": " +
				    pat.getPatternXMLelement().asXML());
		    }
	    }
    }
#endif

bool PatternLocationCreator::visit(const clang::CFGBlock *blk,
				   const clang::Stmt *stmt,
				   size_t index)
{
    Matchings matchings;
    codestructs::CFGNode node(blk, index);

    for (auto &pattern : getXMLAutomatonDefinition().getXMLpatterns()){
	if (const auto res = pattern.matchesNode(node, aliasResolver)) {
	    const auto &assign = *res;
	    const bool isGlobal = isGlobalAssignment(assign);
	    matchings.append(qMakePair(&pattern, SimpleAutomatonID(assign, isGlobal)));
	}
    }

#ifdef OLD
    if (matchings.size() > 1)
	checkMatchingConflict(element, matchings);
#else
    if (matchings.size() > 1) {
	qWarning() << "following statement matched multiple times";
	node.dumpColor();
    }
#endif

    if (!matchings.isEmpty()) {
#ifdef DUMP_MATCHINGS
	qDebug() << __PRETTY_FUNCTION__ << node;
	node.dumpColor();
	for (auto m : matchings)
	    qDebug() << "  " << m.first->getName();
#endif
	const auto newLocation = createCommonPatternLocation(node, matchings).release();
	getNodeLocationDictionary()[blk].append(qMakePair(index, qMakePair(newLocation, newLocation)));
	const auto &maFi = matchings.first();
	if (maFi.first->isConstructive())
	    getAutomataIDs().insert(maFi.second);
    } else if (getNavigator().isCallNode(node)) {
	const auto callLocation = createRuleLessPatternLocation(node).release();
	const auto returnLocation = createRuleLessPatternLocation(node).release();
	getNodeLocationDictionary()[blk].append(qMakePair(index, qMakePair(callLocation, returnLocation)));
	callLocation->setLocationForCallNotPassedStates(returnLocation);
    }

    return false;
}

QList<TransitionRule>
PatternLocationCreator::createTransitionRules(const Matchings &matchings)
{
	QList<TransitionRule> transitionRules;
	auto &autoDef = getXMLAutomatonDefinition();

	for (auto &item : matchings)
	    for (auto &tRule : autoDef.getXMLtransitionRulesForPattern(item.first))
		transitionRules.append(TransitionRule(tRule, item.second));

	return transitionRules;
}

QList<ErrorRule>
PatternLocationCreator::createErrorRules(const Matchings &matchings)
{
	QList<ErrorRule> errorRules;
	auto &autoDef = getXMLAutomatonDefinition();

	for (auto &item : matchings)
	    for (auto &eRule : autoDef.getXMLerrorRulesForPattern(item.first))
		errorRules.append(ErrorRule(eRule, item.second));

	return errorRules;
}

void PatternLocationCreator::createStartEndPatternLocations()
{
	auto start = getCfg().getStartNode();
	auto startLocation = createRuleLessPatternLocation(start).release();
	getNodeLocationDictionary()[&getCfg().getCFG()->getEntry()].append(qMakePair(-1,
					   qMakePair(startLocation, startLocation)));

	auto end = getCfg().getEndNode();
	auto endLocation = createRuleLessPatternLocation(end).release();
	getNodeLocationDictionary()[&getCfg().getCFG()->getExit()].append(qMakePair(-1,
					   qMakePair(endLocation, endLocation)));
}

bool PatternLocationCreator::isGlobalAssignment(const utils::XMLPatternVariablesAssignment &assignment)
{
	const SimpleAutomatonID id(assignment, false);

	for (const auto param : getCfg().getFD()->parameters()) {
	    auto paramNamed = llvm::dyn_cast<clang::NamedDecl>(param);
	    if (!paramNamed)
		    continue;
	    auto paramName = QString::fromStdString(paramNamed->getName().str());
	    for (const auto &var : id.getVarsAssignment()) {
		if (var.contains(paramName))
		    return false;
	    }
	}

	for (const auto &var : id.getVarsAssignment()) {
	    const auto varName = codestructs::PassingSolver::parseRootVariableName(var);
	    qDebug() << __func__ << "is" << varName << "local in:";
	    getCfg().getFD()->dumpColor();
#if 0
	    if (!getCfg().isSymbolLocal(varName))
		return true;
#else
	assert(0); abort();
#endif
	}

	return false;
}
