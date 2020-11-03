#include <cstdio>
#include <iostream>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

int main(int argc, char **argv)
{
	antlr4::ANTLRInputStream input(std::cin);
	CLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	CParser parser(&tokens);
	auto tree = parser.compilationUnit();

	std::cout << tree->toStringTree(&parser, true) << std::endl << std::endl;

	return 0;
}
