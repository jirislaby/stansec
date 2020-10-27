QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

GRAMMARS += \
    src/parser/C.g4

SOURCES += \
    src/core/main.cpp \
    src/ui/mainwindow.cpp

HEADERS += \
    src/ui/mainwindow.h

FORMS += \
    src/ui/mainwindow.ui

TRANSLATIONS += \
    trans/stansec_cs_CZ.ts

INCLUDEPATH += /usr/include/antlr4-runtime/
LIBS += -lantlr4-runtime

QMAKE_CXXFLAGS += -Wno-attributes -Wno-unused-parameter
HEADERS += \
        src/parser/generated/CBaseListener.h \
        src/parser/generated/CBaseVisitor.h \
        src/parser/generated/CLexer.h \
        src/parser/generated/CListener.h \
        src/parser/generated/CParser.h \
        src/parser/generated/CVisitor.h

SOURCES += \
        src/parser/generated/CBaseListener.cpp \
        src/parser/generated/CBaseVisitor.cpp \
        src/parser/generated/CLexer.cpp \
        src/parser/generated/CListener.cpp \
        src/parser/generated/CParser.cpp \
        src/parser/generated/CVisitor.cpp

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

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
