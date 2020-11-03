#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationVersion("1");

    QTranslator translator;
    if (translator.load(QLocale(), "stansec", "_",
                        a.applicationDirPath() + "/trans"))
        a.installTranslator(&translator);

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument(a.translate("main", "sources"),
                                 a.translate("main", "Sources to check"),
                                 a.translate("main", "[sources...]"));
    parser.process(a);

    MainWindow w(parser.positionalArguments());
    w.show();
    return a.exec();
}
