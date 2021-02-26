TEMPLATE = lib
CONFIG += staticlib

QT       += core

QMAKE_CXXFLAGS += -Wno-attributes -Wno-unused-parameter
INCLUDEPATH += generated codestructures

INCLUDEPATH += /usr/include/antlr4-runtime/
LIBS += -lantlr4-runtime

GRAMMARS += \
    C.g4

HEADERS = \
    CFGListener.h \
    codestructures/CFG.h \
    codestructures/CFGNode.h \
    codestructures/CFGPart.h \
    generated/CBaseListener.h \
    generated/CBaseVisitor.h \
    generated/CLexer.h \
    generated/CListener.h \
    generated/CParser.h \
    generated/CVisitor.h \
    parser.h

SOURCES = \
    codestructures/CFGPart.cpp \
    typedef_glue.cpp \
    parser.cpp \
    CFGListener.cpp \
    codestructures/CFG.cpp \
    codestructures/CFGNode.cpp \
    generated/CBaseListener.cpp \
    generated/CBaseVisitor.cpp \
    generated/CLexer.cpp \
    generated/CListener.cpp \
    generated/CParser.cpp \
    generated/CVisitor.cpp

#defineReplace(get_base) {
#	source = $$1
#	base = $$basename(source)
#	base_split = $$split(base, ".")
#	base_splice = $$member(base_split, 0, -2)

#	return($$join(base_splice, "."))
#}

#defineReplace(parser_output_function) {
#	base = $$get_base($$1)
#	message(base=$$base)

#	HEADERS += \
#		$$OUT_PWD/generated/$${base}BaseListener.h \
#		$$OUT_PWD/generated/$${base}BaseVisitor.h \
#		$$OUT_PWD/generated/$${base}Lexer.h \
#		$$OUT_PWD/generated/$${base}Listener.h \
#		$$OUT_PWD/generated/$${base}Parser.h \
#		$$OUT_PWD/generated/$${base}Visitor.h

#	SOURCES += \
#		$$OUT_PWD/generated/$${base}BaseListener.cpp \
#		$$OUT_PWD/generated/$${base}BaseVisitor.cpp \
#		$$OUT_PWD/generated/$${base}Lexer.cpp \
#		$$OUT_PWD/generated/$${base}Listener.cpp \
#		$$OUT_PWD/generated/$${base}Parser.cpp \
#		$$OUT_PWD/generated/$${base}Visitor.cpp

#	message(SOURCES=$$SOURCES)
#	message(HEADERS=$$HEADERS)

#	return($$OUT_PWD/generated/$${base}Parser.cpp)
#}
#defineReplace(FILE_IN_parser_output_function) {
#	base = $$get_base($$1)
#	return($$OUT_PWD/generated/$${base}Parser.cpp)
#}

#parser.output_function = parser_output_function
##parser.depend_command = cd ${QMAKE_FILE_PATH}; \
##	java -jar antlr-4.8-complete.jar -Dlanguage=Cpp -depend ${QMAKE_FILE_BASE}${QMAKE_FILE_EXT} | sed "s,.*:\ ,,"
#parser.commands = cd ${QMAKE_FILE_PATH}; \
#	java -jar antlr-4.8-complete.jar -visitor -Dlanguage=Cpp -o $$OUT_PWD/generated ${QMAKE_FILE_BASE}${QMAKE_FILE_EXT}
#parser.input = GRAMMARS
#parser.variable_out = SOURCES

#QMAKE_EXTRA_COMPILERS += parser

