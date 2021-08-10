add_compile_options(-Wno-attributes -Wno-unused-parameter)
include_directories(generated codestructures)

include_directories(/usr/include/antlr4-runtime/)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(parser STATIC
    codestructures/CFGPart.cpp
    typedef_glue.cpp
    parser.cpp
    CFGListener.cpp
    codestructures/CFG.cpp
    codestructures/CFGNode.cpp
    generated/CBaseListener.cpp
    generated/CBaseVisitor.cpp
    generated/CLexer.cpp
    generated/CListener.cpp
    generated/CParser.cpp
    generated/CVisitor.cpp
    )

target_link_libraries(parser antlr4-runtime Qt5::Core)
