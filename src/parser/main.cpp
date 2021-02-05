#include <cstdio>
#include <iostream>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

int main(int argc, char **argv)
{
	std::ifstream ifs;

	if (argc > 1) {
		ifs.open(argv[1]);
		if (!ifs)
			return 1;
	}

	antlr4::ANTLRInputStream input(ifs.is_open() ? ifs : std::cin);
	CLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	CParser parser(&tokens);
	auto tree = parser.compilationUnit();

	std::cout << tree->toStringTree(&parser, true) << std::endl << std::endl;

	if (ifs.is_open())
		ifs.close();

	return 0;
}
