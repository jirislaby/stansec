find_package(Qt5 COMPONENTS Core REQUIRED)

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
    )

target_link_libraries(checker codestructures utils Qt5::Core)
