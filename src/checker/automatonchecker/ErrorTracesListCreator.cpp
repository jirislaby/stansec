/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Stmt.h>

#include <QString>

#include "../../codestructures/CFGsNavigator.h"

#include "AutomatonCheckerLogger.h"
#include "AutomatonStateCFGcontextAlgo.h"
#include "ErrorTracesListCreator.h"
#include "FalsePositivesDetector.h"
#include "NodeLocationDictionary.h"
#include "PatternLocation.h"

using namespace checker;

void ErrorTracesListCreator::onEndPath(const Path &path, const CallStack &callStack)
{
	const int importance = getTraceImportance(path, callStack);

	if (importance != FalsePositivesDetector::getFalsePositiveImportance()) {
	    getErrorTracesList().append(buildErrorTrace(
		    "The *incomplete* trace starts here",
		    getRule().getErrorPropagMessage(),
		    getRule().getErrorEndMessage(),
		    path, callStack));
	    updateTotalImportance(importance);
	    resetNumRejectedMeasure();
	} else
	    incrementNumRejectedMeasure(path.size());
}

bool ErrorTracesListCreator::visit(const Path &path,
				   const CallStack &cfgContext)
{
	if (getErrorTracesList().size() >= 20 || path.size() > 100 ||
		isLimitOfRejectedMeasureExceeded())
	    return false;

	const auto node = path.first();

	if (getStartNode() == node && path.size() == 1)
	    return true;

	auto &NLD = getNodeLocationDictionary();
	const auto locationPair = NLD[node];

	if (!locationPair)
	    return true;

	const auto location = locationPair->second;

	if (!getRule().checkForError(
		AutomatonStateCFGcontextAlgo::filterStatesByContext(
			  location->getDeliveredAutomataStates(), cfgContext))) {
	    incrementNumRejectedMeasure(path.size());
	    return false;
	}

	if (!getRule().checkForError(
		AutomatonStateCFGcontextAlgo::filterStatesByContext(
			   location->getProcessedAutomataStates(),cfgContext))) {
	    const int importance = getTraceImportance(path, cfgContext);
	    if (importance != FalsePositivesDetector::getFalsePositiveImportance()) {
		getErrorTracesList().append(buildErrorTrace(
			getRule().getErrorBeginMessage(),
			getRule().getErrorPropagMessage(),
			getRule().getErrorEndMessage(),
			path, cfgContext));
		updateTotalImportance(importance);
		resetNumRejectedMeasure();
	    } else
		incrementNumRejectedMeasure(path.size());

	    return false;
	}

	if (cfgContext.isEmpty() &&
		getInternals().getNavigator().isStartNode(node)) {
	    const int importance = getTraceImportance(path,cfgContext);
	    if (importance != FalsePositivesDetector::getFalsePositiveImportance()) {
		getErrorTracesList().append(buildErrorTrace(
			getRule().getErrorEntryMessage(),
			getRule().getErrorPropagMessage(),
			getRule().getErrorEndMessage(),
			path, cfgContext));
		updateTotalImportance(importance);
		resetNumRejectedMeasure();
	    } else
		incrementNumRejectedMeasure(path.size());

	    return false;
	}

	return true;
}

bool ErrorTracesListCreator::onCFGchange(const Stmt &from, const Stmt &to)
{
#if 0
	const SimpleAutomatonID transformedID =
	    getTransferor().transfer(from,getRule().getAutomatonID(),to);
	if (transformedID == null)
	    return false;
	updateRule(transformedID);
	return true;
#else
	assert(0); abort();
#endif
}

int ErrorTracesListCreator::getTraceImportance(const Path &path,
					       const CallStack &cfgContext)
{
	int importance = FalsePositivesDetector::getBugDefaultImportance();
#ifdef FALSEDETECT
	for (const auto detector : detectors) {
	    const int currImportance = detector.getTraceImportance(path,
								   cfgContext,
								   getRule());
	    if (currImportance == FalsePositivesDetector::getFalsePositiveImportance())
		return currImportance;
	    importance = std::max(importance, currImportance);
	}
#endif
	return importance;
}

CheckerErrorTrace ErrorTracesListCreator::buildErrorTrace(const QString &beginMsg,
							  const QString &innerMsg,
							  const QString &endMsg,
							  const Path &path,
							  const CallStack &context)
{
	QList<CheckerErrorTraceLocation> trace;

	for (const auto node : context) {
#if 0
	    if (node->hasLocation()) {
		trace.append(CheckerErrorTraceLocation(getNodeUnitName(node),
			  node.getLine(), node.getColumn(),
			  "<context>When called from here."));
	    }
#else
	    Q_UNUSED(node);
#endif
	}
#if 0
	if (path[0].hasLocation()) {
	    trace.append(CheckerErrorTraceLocation(getNodeUnitName(path[0]),
			 path[0].getLine(),path[0].getColumn(),
		    beginMsg));
	} else {
#else
	{
	    trace.append(CheckerErrorTraceLocation("", -1, -1, beginMsg));
	}
#endif

#if 0
	if (path.size() > 1) {
	    for (auto item : path.mid(1, path.size() - 2)) {
		if (item->isVisible() && item->hasLocation()) {
		    trace.append(CheckerErrorTraceLocation(getNodeUnitName(item),
							   item->getLine(),
							   item->getColumn(),
							   innerMsg));
		}
	    }
	}

	if (path[path.size() - 1]->hasLocation()) {
	    trace.append(CheckerErrorTraceLocation(
			getNodeUnitName(path[path.size() - 1]),
			path[path.size() - 1]->getLine(),
			path[path.size() - 1]->getColumn(),
			endMsg + getRule().getAutomatonID().getVarsAssignment().toString()));
	} else {
	    trace.append(CheckerErrorTraceLocation("", -1, -1,
			endMsg + getRule().getAutomatonID().getVarsAssignment()
					  .toString()));
	}
#endif

	const CheckerErrorTrace eTrace(trace, "error-trace [" + QString::number(getErrorTracesList().size() + 1) + "]");
#ifdef LINEAR
	eTrace.setLinearCode(new LinearCode(context, path));
#endif
	return eTrace;
}

void ErrorTracesListCreator::incrementNumRejectedMeasure(const int pathLen)
{
	numRejectedMeasure += pathLen;
	if (isLimitOfRejectedMeasureExceeded()) {
	    setFailMessage("*** FAILED: budget limit for error traces "
			   "search exceeded. Search was early terminated!");
	    getMonitor().note(getFailMessage());
	}
}

#if 0
    private QString getNodeUnitName(const CFGNode node) {
        return node.getFile().getPath();
    }

	private void updateTotalImportance(const int traceImportance) {
		if (totalImportance <= traceImportance)
			totalImportance = traceImportance;
	}

    private bool isLimitOfRejectedMeasureExceeded() {
        return numRejectedMeasure > 1000;
    }

#endif

