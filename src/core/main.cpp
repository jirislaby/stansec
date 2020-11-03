#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCommandLineParser parser;
    parser.addPositionalArgument("sources", "Sources to check", "[sources...]");
    parser.process(a);

    MainWindow w(parser.positionalArguments());
    w.show();
    return a.exec();
}
