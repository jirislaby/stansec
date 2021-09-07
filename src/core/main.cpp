#include "CmdLineManager.h"
#include "stansec.h"
#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QTranslator>

using namespace core;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationVersion("1");

    QTranslator translator;
    if (translator.load(QLocale(), "stansec", "_",
                        a.applicationDirPath() + "/trans"))
        a.installTranslator(&translator);

    CmdLineManager cmdLine(a);
    Stansec stansec(a, cmdLine);

    return stansec.startUI();
}
