/**
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <llvm/ADT/BreadthFirstIterator.h>

#include <clang/Analysis/CFG.h>
#include <clang/AST/Decl.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Lex/Lexer.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h>

#include <QDebug>
#include <QList>
#include <QFile>
#include <QMap>
#include <QPair>
#include <QString>

#include "../../utils/AliasResolver.h"

#include "../../codestructures/ArgumentPassingManager.h"
#include "../../codestructures/CFGsNavigator.h"
#include "../../codestructures/PassingSolver.h"
#include "../../codestructures/traversal/CFGTraversal.h"

#include "AutomatonStateTransferManager.h"
#include "CallSiteDetector.h"
#include "NodeLocationDictionary.h"
#include "PatternLocation.h"
#include "PatternLocationBuilder.h"
#include "PatternLocationCreator.h"
#include "XMLAutomatonDefinition.h"

using namespace checker;

void
PatternLocationBuilder::buildPatternLocations(const codestructs::LazyInternalStructures &internals,
					      const XMLAutomatonDefinition &automatonDefinition,
					      NodeLocationDictionary &NLD)
{
	QSet<SimpleAutomatonID> globalAutomataIDs;

	for (auto cfg: internals.getCFGHandles())
	    buildPatternLocationsAndStatesForOneCFG(cfg,
						    automatonDefinition,
						    internals,
						    internals.getStartFunctions().contains(cfg),
						    NLD,
						    globalAutomataIDs);

	CallSiteDetector callDetector(internals.getNavigator(),
				      NLD);

	createInterproceduralConnectionsBetweenPatternLocations(
		    NLD, internals.getNavigator(), callDetector);

	// TODO AutomatonStateTransferManager leak
	setStateTransferorToLocations(NLD.values(),
				      new AutomatonStateTransferManager(internals.getArgumentPassingManager(),
									callDetector));

	if (!globalAutomataIDs.isEmpty())
	    for (const auto &cfg: internals.getStartFunctions()) {
		addInitialAutomatonStatesForCFGLocations(
			    *NLD[cfg.getStartNode()]->second,
			    *NLD[cfg.getEndNode()]->first,
			    automatonDefinition, globalAutomataIDs, true);
	    }
}

void PatternLocationBuilder::NLDToDotFile(const NodeLocationDictionary &NLD,
					  clang::ento::AnalysisManager &AM,
					  const QString &file)
{
	QFile out(file);
	if (!out.open(QIODevice::WriteOnly | QIODevice::Text))
	    return;
	out.write(NLDToDot(NLD, AM).toLatin1());
	out.close();
}

void PatternLocationBuilder::NLDToDotFileSep(const NodeLocationDictionary &NLD,
					     const codestructs::LazyInternalStructures &LIS,
					     const QString &file_prefix)
{
	auto &AM = LIS.getAnalysisManager();

	QSet<const clang::CFG *> NLDCFGs;
	for (const auto &blk : NLD.keys()) {
		const auto parent = blk->getParent();
		if (&parent->getEntry() != blk && &parent->getExit() != blk)
		    NLDCFGs.insert(parent);
	}

	for (const auto &CFG : LIS.getCFGHandles()) {
	    if (!NLDCFGs.contains(CFG.getCFG()))
		    continue;
	    QFile out(file_prefix + "_" + CFG.getName() + ".dot");
	    qDebug() << "XXX dumping" << CFG.getName() << "to" << out.fileName();
	    if (!out.open(QIODevice::WriteOnly | QIODevice::Text))
		return;
	    out.write(NLDToDot(NLD, AM, CFG.getCFG()).toLatin1());
	    out.close();
	}
}

QString PatternLocationBuilder::nodeToSrcLine(const codestructs::CFGNode &node,
					      clang::ento::AnalysisManager &AM)
{
	if (auto stmt = node.getStmt()) {
	    auto &SM = AM.getSourceManager();
	    auto &LO = AM.getLangOpts();
	    const auto begLoc = stmt->getBeginLoc();
	    const auto PLoc = SM.getPresumedLoc(begLoc);
	    const auto srcRange = SM.getExpansionRange(begLoc);
	    const auto src = clang::Lexer::getSourceText(srcRange, SM, LO);
	    return QString('l').append(QString::number(PLoc.getLine())).
		    append('c').append(QString::number(PLoc.getColumn())).
		    append(": ").append(
				QString::fromStdString(src.str())).
				append(" (0x").
				append(QString::number((quintptr)stmt, 16)).append(')');
	} else {
	    auto blk = node.getBlock();
	    QString result('b');
	    result.append(QString::number(blk->getBlockID()));
	    const auto cfg = blk->getParent();
	    if (blk == &cfg->getEntry())
		    result.append(" (ENTRY)");
	    else  if (blk == &cfg->getExit())
		    result.append(" (EXIT)");
	    return result;
	}

	return QString();
}

QString PatternLocationBuilder::nodeToDotID(const codestructs::CFGNode &node)
{
	if (auto stmt = node.getStmt())
	    return QString('s').append(QString::number((quintptr)stmt, 16));

	return QString('b').append(QString::number((quintptr)node.getBlock(), 16));
}

QString PatternLocationBuilder::NLDToDot(const NodeLocationDictionary &NLD,
					 clang::ento::AnalysisManager &AM,
					 const clang::CFG *CFGFilter)
{
	QString dot("digraph G {\nnode [shape=box];\n");

	QSet<QPair<QString, QString> > addedArcs;

	for (const auto &blk : NLD.keys()) {
		if (CFGFilter && blk->getParent() != CFGFilter)
			continue;
		for (const auto &stmt : NLD[blk])
			NodeToDot(codestructs::CFGNode(blk, stmt.first),
				  stmt.second, AM, dot, addedArcs);
	}

	return dot.append('}');
}

void PatternLocationBuilder::NodeToDot(const codestructs::CFGNode &n,
				       const LocationPair &locPair,
				       clang::ento::AnalysisManager &AM,
				       QString &dot,
				       QSet<QPair<QString, QString> > &addedArcs)
{
	const auto &patLoc = locPair.first;
	const auto ID = nodeToDotID(n);
	const auto srcLine = nodeToSrcLine(n, AM);
	auto &LO = AM.getLangOpts();

	QStringList strList;
	for (auto &s : patLoc->getDeliveredAutomataStates()) {
	    strList << s.getSymbol() + '[' + s.getAutomatonID().toString(LO) + ']';
	}

	QString filling;
	if (!n.hasStmt())
		filling.append("style=\"filled\" fillcolor=\"lightgray\"");
	dot.append(ID).append(" [ label=\"").append(srcLine).append("\\n").
			append(strList.join(", ")).
			append("\"").append(filling).append(" ];\n");
	for (const auto &succ : patLoc->getSuccessorPatternLocations()) {
	    const auto ID2 = nodeToDotID(succ->getCFGreferenceNode());
	    auto p = qMakePair(ID, ID2);
	    if (addedArcs.contains(p))
		    continue;
	    addedArcs.insert(p);
	    dot.append(ID).append(" -> ").append(ID2).append(";\n");
	}

	strList.clear();
	for (auto &tr : patLoc->getTransitionRules())
		strList << tr.toString(LO);
	if (!strList.empty()) {
		dot.append('t').append(ID).
			append(" [ style=\"filled\" fillcolor=\"yellow\" shape=\"ellipse\" label=\"Transition Rules\\n").
			append(strList.join("\\n")).append("\"];\n");
		dot.append(ID).append(" -> t").append(ID).append(";\n");
	}

	strList.clear();
	for (auto &err : patLoc->getErrorRules())
	    strList << err.toString(LO);
	if (!strList.empty()) {
		dot.append('e').append(ID).
			append(" [ style=\"filled\" fillcolor=\"red\" shape=\"ellipse\" label=\"Error Rules\\n").
			append(strList.join("\\n")).append("\"];\n");
		dot.append(ID).append(" -> e").append(ID).append(";\n");
	}
}

void PatternLocationBuilder::dumpNLD(const NodeLocationDictionary &NLD,
				     const clang::SourceManager &SM,
				     const QString &prefix)
{
	qDebug() << "===" << __func__ << "NLD dump " << prefix;
	for (const auto &blk : NLD.keys())
		for (const auto &stmt : NLD[blk]) {
			const codestructs::CFGNode n(blk, stmt.first);
			qDebug() << "---";
			n.dumpColor();
			n.getBeginLoc().dump(SM);

			const auto &pat = stmt.second;
			dumpNLDPatLoc(pat.first, "  F");
			if (pat.first != pat.second)
			    dumpNLDPatLoc(pat.second, "  S");
		}
	qDebug() << "===" << __func__ << "END of NLD dump " << prefix;
}

void PatternLocationBuilder::dumpNLDPatLoc(const PatternLocation *patLoc, const QString &prefix)
{
	if (!patLoc) {
	    qDebug().noquote() << prefix << "NULL";
	    return;
	}

	for (auto &tr : patLoc->getTransitionRules())
	    (qDebug().noquote().nospace() << prefix << "T ").quote().space() <<
			tr;
	for (auto &err : patLoc->getErrorRules())
	    (qDebug().noquote().nospace() << prefix << "E ").quote().space() <<
			err << err.getErrorDescription();
	for (auto &s : patLoc->getDeliveredAutomataStates())
	    (qDebug().noquote().nospace() << prefix << "A ").quote().space() <<
		      s;
}

void PatternLocationBuilder::buildPatternLocationsAndStatesForOneCFG(codestructs::CFGHandle &cfg,
								     const XMLAutomatonDefinition &automatonDefinition,
								     const codestructs::LazyInternalStructures &internals,
								     const bool isStartFunction,
								     NodeLocationDictionary &NLD,
								     QSet<SimpleAutomatonID> &globalAutomataIDs)
				       //throws XMLAutomatonSyntaxErrorException
{
    PatternLocationCreator patternLocationCreator(cfg, automatonDefinition,
						  internals, NLD);
#ifdef OLD
    codestructs::CFGTraversal::traverseCFGToBreadthForward(cfg,
							   cfg.getStartNode(),
							   patternLocationCreator);
#else
    codestructs::CFGTraversal::visitBlockStmtsIdx(cfg.getCFG(),
						  patternLocationCreator);
#endif

    createIntraproceduralConnectionsBetweenPatternLocations(NLD, cfg);

    QSet<SimpleAutomatonID> locals;
    QSet<SimpleAutomatonID> floats;
    splitAutomataIDsIntoGlobalLocalAndFloation(patternLocationCreator.getAutomataIDs(),
		cfg, globalAutomataIDs, locals, floats);

    if (!locals.isEmpty())
	addInitialAutomatonStatesForCFGLocations(
	    *NLD[&cfg.getCFG()->getEntry()].first().second.second,
	    *NLD[&cfg.getCFG()->getExit()].first().second.first,
	    automatonDefinition, locals, false);

    if (isStartFunction && !floats.isEmpty())
	addInitialAutomatonStatesForCFGLocations(
	    *NLD[&cfg.getCFG()->getEntry()].first().second.second,
	    *NLD[&cfg.getCFG()->getExit()].first().second.first,
			automatonDefinition, floats, false);
}

void PatternLocationBuilder::setStateTransferorToLocations(const QList<checker::Locations> &locations,
							   AutomatonStateTransferManager *transferor)
{
	for (auto &loc : locations)
		for (auto &locPair : loc) {
			auto &item = locPair.second;
			item.first->setTransferor(transferor);
			item.second->setTransferor(transferor);
		}
}

PatternLocation *PatternLocationBuilder::connectInsideBlock(NodeLocationDictionary &NLD,
							    const clang::CFGBlock *blk,
							    checker::Locations &stmtList)
{
	auto I = stmtList.begin();
	const auto &fiStmt = *(I++);
	auto refLoc = fiStmt.second.second;

	for (auto E = stmtList.end(); I != E; ++I) {
	    auto fi = I->second.first;
	    //assert(node == fi->getCFGreferenceNode());
	    auto &succs = refLoc->getSuccessorPatternLocations();
	    if (!succs.contains(fi))
		succs.append(fi);
	    refLoc = I->second.second;
	}

	return refLoc;
}

void PatternLocationBuilder::createIntraproceduralConnectionsBetweenPatternLocations(NodeLocationDictionary &NLD,
										     const codestructs::CFGHandle &cfg)
{
	for (const auto &blk: *cfg.getCFG()) {
	    const auto blkI = NLD.find(blk);
	    if (blkI == NLD.end())
		continue;

	    auto last = connectInsideBlock(NLD, blk, *blkI);

	    auto I = llvm::bf_begin(blk);
	    ++I; // skip self
	    for (auto E = llvm::bf_end(blk); I != E; ++I) {
		    auto it = NLD.find(*I);
		    if (it == NLD.end())
			continue;

		    const auto &nodeLocationsList = *it;
		    const auto &nodeLocationsPair = nodeLocationsList.first().second;

		    if (nodeLocationsPair.second == last)
			continue;

		    auto fi = nodeLocationsPair.first;
		    //assert(node == fi->getCFGreferenceNode());
		    auto &succs = last->getSuccessorPatternLocations();
		    if (!succs.contains(fi))
			succs.append(fi);

		    I.Visited.insert((*I)->succ_begin(),
				     (*I)->succ_end());
	    }
	}
}

void PatternLocationBuilder::createInterproceduralConnectionsBetweenPatternLocations(const NodeLocationDictionary &NLD,
										     const codestructs::CFGsNavigator &navigator,
										     const CallSiteDetector &callDetector)
{
	for (const auto &callNode : callDetector.callSites()) {
	    const auto it = NLD[callNode];
	    if (!it)
		    continue;
	    const auto locationsPair = *it;
	    connectCallerCallee(locationsPair.first,
				locationsPair.second,
				NLD[navigator.getCalleeStart(callNode)]->first,
				NLD[navigator.getCalleeEnd(callNode)]->first);
	}
}

void PatternLocationBuilder::connectCallerCallee(PatternLocation *callLocation,
						 PatternLocation *returnLocation,
						 PatternLocation *calleeStartLocation,
						 PatternLocation *calleeEndLocation)
{
	callLocation->getSuccessorPatternLocations().append(calleeStartLocation);
	calleeEndLocation->getSuccessorPatternLocations().append(returnLocation);
}

void
PatternLocationBuilder::splitAutomataIDsIntoGlobalLocalAndFloation(const QSet<SimpleAutomatonID> &IDs,
								   const codestructs::CFGHandle &cfg,
								   QSet<SimpleAutomatonID> &globals,
								   QSet<SimpleAutomatonID> &locals,
								   QSet<SimpleAutomatonID> &floats)
{
    for (const auto &id : IDs) {
	if (isParameterDependentID(id, cfg.getFD())) {
	    floats.insert(id);
	} else if (isOfLocallyDeclaredVariable(id, cfg)) {
	    if (isInReturnExpression(id, cfg))
		floats.insert(id);
	    else
		locals.insert(id);
	} else {
	    globals.insert(SimpleAutomatonID(id.getVarsAssignment(), true));
	}
    }
}

bool PatternLocationBuilder::isParameterDependentID(const SimpleAutomatonID &automatonID,
						    const clang::FunctionDecl *FD) {
	for (const auto &param : FD->parameters())
		if (isParameterDependentID(automatonID, param))
			return true;
	return false;
}

bool PatternLocationBuilder::isParameterDependentID(const SimpleAutomatonID &id,
						    const clang::ParmVarDecl *param) {
	for (const auto &varsAssign : id.getVarsAssignment())
		if (codestructs::PassingSolver::stmtContainsDecl(varsAssign, param))
			return true;
	return false;
}

bool PatternLocationBuilder::isOfLocallyDeclaredVariable(const SimpleAutomatonID &id,
							 const codestructs::CFGHandle &cfg)
{
#if 0
	for (const auto &varsAssign : id.getVarsAssignment())
	    if (!cfg.isSymbolLocal(cz.muni.stanse.codestructures.PassingSolver.
				   parseRootVariableName(varsAssign)))
		return false;

	return true;
#else
	assert(0); abort();
#endif
}

bool PatternLocationBuilder::isInReturnExpression(const SimpleAutomatonID &id,
						  const codestructs::CFGHandle &cfg)
{
#if 0
	for (const CFGNode node : cfg.getEndNode().getPredecessors()) {
	    QSet<QString> dependentVars = nullptr;
	    if (node.getNodeType() != null && node.getNodeType().equals("assign")
		    && ((QString)node.getOperands().get(0).id).equals(cfg.getRetVar())) {
		CFGNode.Operand retop = node.getOperands().get(1);
		dependentVars = CFGNode.getDependentVars(retop);
	    } else if (node.getElement() != null && node.getElement().getName().equals("returnStatement")) {
		dependentVars = new QSet<QString>();
		for (Object idElem : node.getElement().selectNodes("id"))
		    dependentVars.add(((org.dom4j.Element)idElem).getText());
	    }
	    if (dependentVars != null && isInReturnExpression(id,dependentVars))
		return true;
	}

	return false;
#else
	assert(0); abort();
#endif
}

void PatternLocationBuilder::addInitialAutomatonStatesForCFGLocations(PatternLocation &startLoc,
								      PatternLocation &endLoc,
								      const XMLAutomatonDefinition &automatonDefinition,
								      const QSet<SimpleAutomatonID> &automataIDs,
								      const bool asGlobal)
{
	startLoc.setInitialAutomataStates(
		    getAutomataStates(automatonDefinition.getStartSymbol(),
				      automataIDs, asGlobal));
	endLoc.getErrorRules().append(
		    getExitErrorRules(automatonDefinition.getExitErrorRules(),
				      automataIDs, asGlobal));
}

QList<AutomatonState> PatternLocationBuilder::getAutomataStates(const QString startSymbol,
								const QSet<SimpleAutomatonID> &automataIDs,
								const bool asGlobal)
{
    QList<AutomatonState> states;

    for (const auto &id : automataIDs)
	states.append(AutomatonState(startSymbol,
				     SimpleAutomatonID(id.getVarsAssignment(),
						       asGlobal)));

    return states;
}

QList<ErrorRule> PatternLocationBuilder::getExitErrorRules(const QList<const XMLErrorRule *> &XMLrules,
							   const QSet<SimpleAutomatonID> &automataIDs,
							   const bool asGlobal)
{
    QList<ErrorRule> errorRules;

    for (auto rule : XMLrules)
	for (const auto &id : automataIDs)
	    errorRules.append(ErrorRule(rule,
					SimpleAutomatonID(id.getVarsAssignment(),
							  asGlobal)));
    return errorRules;
}

#if 0
bool isInReturnExpression(const SimpleAutomatonID id,
			  const Set<QString> dependentVars) {
    for (const QString varsAssign : id.getVarsAssignment()) {
	const QString varName = cz.muni.stanse.codestructures.PassingSolver.
		parseRootVariableName(varsAssign);
	for (QString depVar : dependentVars)
	    if (varName.equals(depVar))
		return true;
    }
    return false;
}
#endif
