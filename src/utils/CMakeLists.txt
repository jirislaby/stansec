set(QT_COMPONENTS Core Xml)
find_package(Qt6 QUIET COMPONENTS ${QT_COMPONENTS})
if (NOT Qt6_FOUND)
	find_package(Qt5 REQUIRED COMPONENTS ${QT_COMPONENTS})
endif()

add_compile_definitions(QT_NO_FOREACH)

add_library(utils STATIC
	AliasResolver.h
	xmlpatterns/XMLAlgo.cpp
	xmlpatterns/XMLAlgo.h
	xmlpatterns/XMLPattern.cpp
	xmlpatterns/XMLPattern.h
	xmlpatterns/XMLPatternVariablesAssignment.cpp
	xmlpatterns/XMLPatternVariablesAssignment.h
    )

target_link_libraries(utils Qt::Core Qt::Xml)
