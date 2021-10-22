find_package(Qt5 COMPONENTS Core Xml REQUIRED)

add_compile_definitions(QT_NO_FOREACH)

add_library(codestructures STATIC
	ArgumentPassingManager.cpp
	ArgumentPassingManager.h
	CFGsNavigator.h
	LazyInternalStructures.cpp
	LazyInternalStructures.h
	LazyInternalStructuresInter.h
	LazyInternalStructuresIntra.h
	PassingSolver.cpp
	PassingSolver.h
	builders/StartFunctionsSetBuilder.cpp
	builders/StartFunctionsSetBuilder.h
	builders/XMLLinearizeASTElement.cpp
	builders/XMLLinearizeASTElement.h
	)

target_link_libraries(codestructures utils Qt5::Core Qt5::Xml)
