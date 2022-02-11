set(QT_COMPONENTS Core Xml)
find_package(Qt6 QUIET COMPONENTS ${QT_COMPONENTS})
if (NOT Qt6_FOUND)
	find_package(Qt5 REQUIRED COMPONENTS ${QT_COMPONENTS})
endif()

add_compile_definitions(QT_NO_FOREACH)

add_library(codestructures STATIC
	ArgumentPassingManager.cpp
	ArgumentPassingManager.h
	CFGHandle.cpp
	CFGHandle.h
	CFGNode.cpp
	CFGNode.h
	CFGsNavigator.h
	IntraproceduralCFGsNavigator.h
	LazyInternalStructures.cpp
	LazyInternalStructures.h
	LazyInternalStructuresInter.h
	LazyInternalStructuresIntra.h
	PassingSolver.cpp
	PassingSolver.h
	builders/NodeToCFGdictionaryBuilder.cpp
	builders/NodeToCFGdictionaryBuilder.h
	builders/StartFunctionsSetBuilder.cpp
	builders/StartFunctionsSetBuilder.h
	builders/XMLLinearizeASTElement.cpp
	builders/XMLLinearizeASTElement.h
	traversal/CFGPathVisitor.h
	traversal/CFGVisitor.h
	traversal/CFGTraversal.cpp
	traversal/CFGTraversal.h
	)

target_link_libraries(codestructures utils Qt::Core Qt::Xml)
