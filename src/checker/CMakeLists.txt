set(QT_COMPONENTS Core Xml)
find_package(Qt6 QUIET COMPONENTS ${QT_COMPONENTS})
if (NOT Qt6_FOUND)
	find_package(Qt5 REQUIRED COMPONENTS ${QT_COMPONENTS})
endif()

add_compile_definitions(QT_NO_FOREACH)

add_library(checker STATIC
	CheckerCreator.h
	CheckerError.cpp
	CheckerError.h
	CheckerErrorReceiver.h
	CheckerErrorTrace.cpp
	CheckerErrorTrace.h
	CheckerErrorTraceLocation.h
	Checker.h
	CheckerProgressMonitor.h
	CheckingResult.h
	CheckingSuccess.h

	automatonchecker/AutomatonChecker.cpp
	automatonchecker/AutomatonCheckerCreator.h
	automatonchecker/AutomatonChecker.h
	automatonchecker/AutomatonCheckerLogger.h
	automatonchecker/AutomatonStateContextItem.h
	automatonchecker/AutomatonState.h
	automatonchecker/AutomatonStateCFGcontextAlgo.cpp
	automatonchecker/AutomatonStateCFGcontextAlgo.h
	automatonchecker/AutomatonStateContextAlgo.h
	automatonchecker/AutomatonStateTransferManager.cpp
	automatonchecker/AutomatonStateTransferManager.h
	automatonchecker/CallSiteCFGNavigator.h
	automatonchecker/CallSiteDetector.h
	automatonchecker/CheckerErrorBuilder.cpp
	automatonchecker/CheckerErrorBuilder.h
	automatonchecker/ComposedAutomatonID.h
	automatonchecker/ConnectPatternLocationToSuccessors.cpp
	automatonchecker/ConnectPatternLocationToSuccessors.h
	automatonchecker/ErrorRule.h
	automatonchecker/ErrorTracesListCreator.cpp
	automatonchecker/ErrorTracesListCreator.h
	automatonchecker/FalsePositivesDetector.h
	automatonchecker/NodeLocationDictionary.cpp
	automatonchecker/NodeLocationDictionary.h
	automatonchecker/PatternLocation.cpp
	automatonchecker/PatternLocation.h
	automatonchecker/PatternLocationBuilder.cpp
	automatonchecker/PatternLocationBuilder.h
	automatonchecker/PatternLocationCreator.cpp
	automatonchecker/PatternLocationCreator.h
	automatonchecker/SimpleAutomatonID.h
	automatonchecker/TransitionRule.h
	automatonchecker/XMLAutomatonDefinition.cpp
	automatonchecker/XMLAutomatonDefinition.h
	automatonchecker/XMLErrorRule.cpp
	automatonchecker/XMLErrorRule.h
	automatonchecker/XMLRuleStringParser.cpp
	automatonchecker/XMLRuleStringParser.h
	automatonchecker/XMLTransitionRule.cpp
	automatonchecker/XMLTransitionRule.h

	reachabilitychecker/ReachabilityChecker.cpp
	reachabilitychecker/ReachabilityCheckerCreator.h
	reachabilitychecker/ReachabilityChecker.h
    )

target_link_libraries(checker codestructures utils Qt::Core Qt::Xml)
