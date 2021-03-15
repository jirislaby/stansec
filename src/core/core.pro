TARGET = stansec

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    ../ui/mainwindow.cpp \
    ../ui/sourcecodeedit.cpp

HEADERS += \
    ../ui/mainwindow.h \
    ../ui/sourcecodeedit.h

FORMS += \
    ../ui/mainwindow.ui

TRANSLATIONS += \
    ../../trans/stansec_cs.ts

INCLUDEPATH += ../ui
LIBS += -L../parser -lparser -lantlr4-runtime
unix:PRE_TARGETDEPS += ../parser/libparser.a
win32:PRE_TARGETDEPS += ../parser/parser.lib

unix {
	isEmpty(PREFIX) {
		PREFIX = /usr
	}
	BINDIR = $$PREFIX/bin
	DATADIR = $$PREFIX/share

	DEFINES += DATADIR=\\\"$$DATADIR\\\"

	target.path = $$BINDIR
	INSTALLS += target
}

