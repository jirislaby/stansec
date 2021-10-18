find_package(Qt5 COMPONENTS Core Xml REQUIRED)

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

target_link_libraries(utils Qt5::Core Qt5::Xml)
