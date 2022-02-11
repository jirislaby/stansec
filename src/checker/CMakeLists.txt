set(QT_COMPONENTS Core)
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

	reachabilitychecker/ReachabilityChecker.cpp
	reachabilitychecker/ReachabilityCheckerCreator.h
	reachabilitychecker/ReachabilityChecker.h
    )

target_link_libraries(checker codestructures utils Qt::Core)
