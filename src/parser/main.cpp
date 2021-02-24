#include <cstdio>
#include <iostream>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

#undef DUMP_TREE

static void dumpTree(CParser &parser, antlr4::ParserRuleContext *tree)
{
#ifdef DUMP_TREE
	std::cout << tree->toStringTree(&parser, true) << std::endl << std::endl;
#endif
}

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
	dumpTree(parser, parser.compilationUnit());

	if (ifs.is_open())
		ifs.close();

	return 0;
}
