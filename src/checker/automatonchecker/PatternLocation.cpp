/**
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Stmt.h>
#include <clang/Basic/SourceManager.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h>

#include <QList>
#include <QPair>
#include <QStack>
#include <QString>

#include "../../codestructures/LazyInternalStructures.h"

#include "AutomatonStateCFGcontextAlgo.h"
#include "AutomatonStateTransferManager.h"
#include "PatternLocation.h"

using namespace checker;

bool PatternLocation::processUnprocessedAutomataStates()
{
	assert(!getUnprocessedAutomataStates().isEmpty());
	bool successorsWereAffected = false;
	do {
	    //qDebug() << __func__ << toString() << "to_process:" << getUnprocessedAutomataStates();
	    const auto &currentState = getUnprocessedAutomataStates().takeFirst();
	    if (!getProcessedAutomataStates().contains(currentState)) {
		getProcessedAutomataStates().insert(currentState);
		transformAutomataStateToSuccessors(currentState);
		successorsWereAffected = true;
	    }
	} while (!getUnprocessedAutomataStates().isEmpty());
	return successorsWereAffected;
}

QString PatternLocation::toString() {
	auto &SM = LIS.getAnalysisManager().getSourceManager();
	auto ln = SM.getPresumedLineNumber(CFGreferenceNode.getBeginLoc());
	return "PL(line " + QString::number(ln) + ")";
}

void PatternLocation::transformAutomataStateToSuccessors(const AutomatonState &state)
{
    const auto transformedStates = transformAutomatonState(state);
    for (const auto &location : getSuccessorPatternLocations())
	for (const auto &transformedState : transformedStates) {
	    /*qDebug() << __func__ << "prop" << transformedState << "to" <<
			location->toString();*/
	    propagateStateToLocation(transformedState, location);
	}
    getDeliveredAutomataStates() |= transformedStates;
}

QSet<AutomatonState>
PatternLocation::transformAutomatonState(const AutomatonState &state)
{
    QSet<AutomatonState> transformedStates;
    bool stateWasTransformedByAtLeastOneRule = false;

    //qDebug() << __func__ << toString() << state;
    for (const auto &rule : getTransitionRules()) {
	/*qDebug() << "  " << rule.getAutomatonID();
	qDebug() << "  " << rule.getXMLrule()->getInSymbol() <<
		    rule.getXMLrule()->getPatternName() <<
		    rule.getXMLrule()->getOutSymbol();*/
	const auto &transformationResult = rule.transformAutomatonState(state);
	if (transformationResult) {
	    //qDebug() << "  HIT" << *transformationResult;
	    stateWasTransformedByAtLeastOneRule = true;
	    transformedStates.insert(*transformationResult);
	}
    }

    if (!stateWasTransformedByAtLeastOneRule)
	transformedStates.insert(state);

    return transformedStates;
}

void PatternLocation::propagateStateToLocation(const AutomatonState &state,
					       PatternLocation *location) {
    assert(getTransferor() != nullptr);
    const auto propagatedState = getTransferor()->transfer(getCFGreferenceNode(),
							   state,
							   location->getCFGreferenceNode());
    if (propagatedState)
	location->getUnprocessedAutomataStates().append(*propagatedState);
    else if (auto loc = getLocationForCallNotPassedStates())
	loc->getUnprocessedAutomataStates().append(state);
}

void PatternLocation::reduceStateSet(QSet<AutomatonState> &set)
{
#if 0
    QList<AutomatonState> stateVec;
    QList<QStack<CFGNode>> contextVec;
    for (const auto state : set) {
	stateVec.push_back(state);
	contextVec.push_back(AutomatonStateCFGcontextAlgo::getContext(state.getContext()));
    }
    assert(stateVec.size() == contextVec.size());

    for (int i = 0, n = stateVec.size(); i < n; ++i) {
	const AutomatonState stateI = stateVec[i];
	for (int j = i+1; j < n; ++j) {
	    const auto stateJ = stateVec[j];
	    if (stateI.getSymbol() != stateJ.getSymbol())
		continue;
	    if (AutomatonStateCFGcontextAlgo::firstIsSubcontextOfSecond(
			contextVec[i], contextVec[j])) {
		set.remove(stateI);
		break;
	    }
	}
    }
#else
    assert(0); abort();
#endif
}
