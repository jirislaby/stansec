#include <cstdio>
#include <iostream>
#include <string>

#include <antlr4-runtime.h>

#include <QDebug>

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

    qDebug().noquote() << cfgListener.getDot("main");

    return tree->toStringTree(&parser, true);
}

std::string getParseTree(const std::string &in)
{
    antlr4::ANTLRInputStream input(in);
    return getParseTree(input);
}
