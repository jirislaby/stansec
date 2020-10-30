#include <cstdio>
#include <iostream>
#include <string>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"
#include "main.h"

std::string getParseTree(antlr4::ANTLRInputStream &input)
{
    CLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    CParser parser(&tokens);
    antlr4::tree::ParseTree* tree = parser.translationUnit();

    return tree->toStringTree(&parser, true);
}

std::string getParseTree(std::istream &in)
{
    antlr4::ANTLRInputStream input(in);
    return getParseTree(input);
}

std::string getParseTree(const std::string &in)
{
    antlr4::ANTLRInputStream input(in);
    return getParseTree(input);
}

int __attribute__((weak)) main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    std::cout << getParseTree(std::cin) << std::endl << std::endl;

	return 0;
}

