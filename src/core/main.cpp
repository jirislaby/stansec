#include "CmdLineManager.h"
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

    MainWindow w(cmdLine.positionalArguments());
    w.show();
    return a.exec();
}
