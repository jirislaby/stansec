#include <cstdio>
#include <iostream>
#include <string>

#include <antlr4-runtime.h>

#include <QDebug>
#include <QFile>
#include <QProcess>

#include "CFGListener.h"
#include "CLexer.h"
#include "CParser.h"
#include "parser.h"

std::string getParseTree(antlr4::ANTLRInputStream &input)
{
    CLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    CParser parser(&tokens);
    auto tree = parser.compilationUnit();
    CFGListener cfgListener(tokens);
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&cfgListener, tree);

    auto dot = cfgListener.getDot("main");
    qDebug().noquote() << dot;

    QFile file("main.dot");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << dot;
        file.close();
        QProcess::execute("dot", QStringList() << "-Tpdf" << "-O" << "main.dot");
    }

    return tree->toStringTree(&parser, true);
}

std::string getParseTree(const std::string &in)
{
    antlr4::ANTLRInputStream input(in);
    return getParseTree(input);
}
