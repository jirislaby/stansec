/*
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Stmt.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h>

#include <QDebug>
#include <QDomDocument>

#include "../CheckingResult.h"
#include "../CheckingSuccess.h"

#include "AutomatonCheckerCreator.h"
#include "AutomatonCheckerLogger.h"
#include "AutomatonChecker.h"
#include "CheckerErrorBuilder.h"
#include "NodeLocationDictionary.h"
#include "PatternLocationBuilder.h"

using namespace checker;
using namespace codestructs;

QString AutomatonChecker::getName()
{
    return AutomatonCheckerCreator::getNameForCheckerFactory() +
	    " of " + getXmlFile().fileName();
}

/**
 * @brief Does the source code checking itself.
 *
 * Method searches through source code to find matching patterns defined
 * in XML automata definition file. Each such matched location in the source
 * code is assigned an instance of PatternLocation class. Initial location
 * in the program is always introduced and is initialized with initial
 * states of all automata to be run on the source code.
 *
 * The computation itself is simple distribution of automata states between
 * instances of PatternLocation class (locations are linked together with
 * respect to control-flow of source code). Automata states are transformed
 * with respect to transition rules assigned to each PatternLocation and
 * then distributed to linked locations. This procedure is finished, when
 * no location was delivered automaton state, which was not processed in
 * that location.
 *
 * Error detection is the final phase of the procedure. All PatternLocations
 * are crossed and checked for error states. Each PatternLocation has
 * assigned set of error transition rules which are applied to all processed
 * states in the location. If some error transition rule can be applied to
 * processed states, then it means the source code contains error. Each
 * error rule contains description of an error it checks for. Those error
 * transition rules are defined in XML automaton definition file.
 *
 * @param units List of translations units (described in internal structures
 *              like CFGs and ASTs)
 * @return List of errors found in the source code.
 * @throws XMLAutomatonSyntaxErrorException Is thrown, when some semantic
 *              error is detected in XML automata definition.
 * @see cz.muni.stanse.checker.Checker#check(java.util.List)
 */
CheckingResult AutomatonChecker::check(const LazyInternalStructures &internals,
				       CheckerErrorReceiver &errReciver,
				       CheckerProgressMonitor &monitor)
{
    CheckingResult result = CheckingSuccess();
    AutomatonCheckerLogger automatonMonitor(monitor);
    automatonMonitor.note("Checker: " + getName());
    automatonMonitor.pushTab();
    automatonMonitor.phaseLog("parsing configuration XML file");
    auto XMLdefinition = parseXMLAutomatondefinition(loadXMLdefinition());
    if (XMLdefinition != nullptr)
	result = check(std::move(XMLdefinition), internals, errReciver,
		       automatonMonitor);
    automatonMonitor.phaseBreak("checking done in ");
    return result;
}

#if 0
Integer AutomatonChecker::makePatternId(HashMap<PatternLocation, Integer> patternids, StringBuilder sb, PatternLocation pattern) {
    if (!patternids.containsKey(pattern)) {
	sb.append("n").append(patternids.size()).append("[label=\"");
	for (AutomatonState state : pattern.getUnprocessedAutomataStates()){
	    sb.append("[").append(state.toString()).append("]");
	}
	for (AutomatonState state : pattern.getProcessedAutomataStates()){
	    sb.append("[").append(state.toString()).append("]");
	}
	sb.append(pattern.getCFGreferenceNode());
	sb.append("\"]").append(";\n");
	patternids.put(pattern, patternids.size());
	return patternids.size() - 1;
    } else
	return patternids.get(pattern);
}
#endif

CheckingResult AutomatonChecker::check(const std::unique_ptr<XMLAutomatonDefinition> xmlAutomatonDefinition,
				       const LazyInternalStructures &internals,
				       CheckerErrorReceiver &errReceiver,
				       AutomatonCheckerLogger &monitor)
{
	monitor.phaseLog("building pattern locations");

	NodeLocationDictionary NLD;
	PatternLocationBuilder::buildPatternLocations(internals,
				       *xmlAutomatonDefinition, NLD);
	monitor.phaseLog("processing automata states");
	QList<PatternLocation *> progressQueue;
	for (const auto &cfg: internals.getCFGHandles()) {
	    auto location = NLD[&cfg.getCFG()->getEntry()].first().second.second;
	    if (location->hasUnprocessedAutomataStates())
		progressQueue.append(location);
	}
	//PatternLocationBuilder::dumpNLD(NLD, internals.getAnalysisManager().getSourceManager());
#ifdef TIMEOUT
	final TimeManager tmgr = new TimeManager();
	tmgr.measureStart();
#endif
	while (!progressQueue.isEmpty()) {
	    //dumpNodeLocationGraph(NLD.values());
	    auto currentLocation = progressQueue.first();
	    progressQueue.removeFirst();
	    //qDebug() << __func__;
	    //auto &SM = internals.getAnalysisManager().getSourceManager();
	    //auto ref = currentLocation->getCFGreferenceNode();
	    //ref->dumpColor();
	    //auto loc = ref->getBeginLoc();
	    //auto PLoc = SM.getPresumedLoc(loc);
	    //qDebug() << "line" << PLoc.getLine();
	    if (!currentLocation->hasUnprocessedAutomataStates())
		continue;
	    //qDebug() << "UNPROCS";
	    currentLocation->fireLocalAutomataStates();
	    auto successorsWereAffected = currentLocation->processUnprocessedAutomataStates();
	    if (successorsWereAffected) {
		progressQueue.append(currentLocation->getSuccessorPatternLocations());
		auto loc = currentLocation->getLocationForCallNotPassedStates();
		if (loc)
		    progressQueue.append(loc);
	    }
#ifdef TIMEOUT
	    final long time = tmgr.measureElapsedMs() / 1000L;
	    /* 60 s is hard limit, 10 s when there are many locations */
	    if (time > 60 || (time > 10 && NLD.size() > 500)) {
		monitor.pushTab();
		final String errMsg =
			"*** WARNING: fix-point computation TERMINATED " +
			"because of timeout. Location set is extremely " +
			"large: " + NLD.size();
		monitor.note(errMsg);
		monitor.popTab();
		getLocationUnitName(currentLocation,internals);
		return new CheckingFailed(errMsg,
					  getLocationUnitName(currentLocation,internals));
	    }
#endif
	}
	//PatternLocationBuilder::dumpNLD(NLD, internals.getAnalysisManager().getSourceManager());
	PatternLocationBuilder::NLDToDotFileSep(NLD, internals, "out");

	monitor.phaseLog("collecting false-positive detectors");
#ifdef FALSE_POSITIVE_DETECTORS
	auto detectors = FalsePositivesDetectorFactory::getDetectors(
		    xmlAutomatonDefinition,internals,
		    Collections.unmodifiableMap(NLD));
#endif
	monitor.phaseLog("building error traces");
	monitor.pushTab();
	auto result = CheckerErrorBuilder::buildErrorList(NLD, internals,
							  nullptr/*detectors*/,
							  errReceiver,
							  monitor, getName());
	monitor.popTab();

	return result;
}

#if 0
String AutomatonChecker::getNodeUnitName(final CFGNode node,
					 final LazyInternalStructures internals) {
    return Stanse.getUnitManager().getUnitName(
		internals.getNodeToCFGdictionary().get(node));
}

String AutomatonChecker::getLocationUnitName(final PatternLocation location,
					     final LazyInternalStructures internals) {
    return getNodeUnitName(location.getCFGreferenceNode(),internals);
}
#endif

std::unique_ptr<QDomDocument> AutomatonChecker::loadXMLdefinition()
{
	if (!xmlFile.open(QIODevice::ReadOnly)) {
		qWarning() << "Cannot open" << xmlFile.fileName() << ':' <<
			      xmlFile.errorString();
		return nullptr;
	}

	struct Closer {
		Closer(QFile &file) : file(file) {}
		~Closer() { file.close(); }
		QFile &file;
	} closer(xmlFile);

	auto result = std::make_unique<QDomDocument>("xmlDefinition");
	QString err;
	int errLine, errCol;
	if (!result->setContent(&xmlFile, &err, &errLine, &errCol)) {
		qWarning() << "Error found in XML definition file" <<
			      xmlFile.fileName() << errLine << ':' << errCol <<
			      ':' << err;
		return nullptr;
	}

	return result;
}

std::unique_ptr<XMLAutomatonDefinition>
AutomatonChecker::parseXMLAutomatondefinition(std::unique_ptr<QDomDocument> XMLdefinition)
{
	if (!XMLdefinition)
	    return nullptr;

	return std::make_unique<XMLAutomatonDefinition>(XMLdefinition->documentElement());
#if 0
	try {
	    return new XMLAutomatonDefinition(XMLdefinition.getRootElement());
	} catch (final XMLAutomatonSyntaxErrorException e) {
	    return null;
	}
#endif
}
