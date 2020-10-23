QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

GRAMMARS += \
    src/parser/GNUCa.g

SOURCES += \
    src/core/main.cpp \
    src/ui/mainwindow.cpp

HEADERS += \
    src/ui/mainwindow.h

FORMS += \
    src/ui/mainwindow.ui

TRANSLATIONS += \
    trans/stansec_cs_CZ.ts

parser.output  = \
        ${QMAKE_FILE_BASE}BaseListener.cpp \
        ${QMAKE_FILE_BASE}BaseListener.h \
        ${QMAKE_FILE_BASE}BaseVisitor.cpp \
        ${QMAKE_FILE_BASE}BaseVisitor.h \
        ${QMAKE_FILE_BASE}Lexer.cpp \
        ${QMAKE_FILE_BASE}Lexer.h \
        ${QMAKE_FILE_BASE}Listener.cpp \
        ${QMAKE_FILE_BASE}Listener.h \
        ${QMAKE_FILE_BASE}Parser.cpp \
        ${QMAKE_FILE_BASE}Parser.h \
        ${QMAKE_FILE_BASE}Visitor.cpp \
        ${QMAKE_FILE_BASE}Visitor.h
parser.commands = java -jar antlr-4.8-complete.jar -visitor -Dlanguage=Cpp ${QMAKE_FILE_NAME}
parser.input = GRAMMARS

QMAKE_EXTRA_COMPILERS += parser

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
