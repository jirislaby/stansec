#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

int main(int argc, char **argv)
{
	antlr4::ANTLRInputStream input(std::cin);
	CLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	CParser parser(&tokens);
	antlr4::tree::ParseTree* tree = parser.translationUnit();

	std::cout << tree->toStringTree(&parser, true) << std::endl << std::endl;

	return 0;
}

