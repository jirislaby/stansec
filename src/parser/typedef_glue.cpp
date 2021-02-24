#include "generated/CParser.h"

bool CParser::isTypeName(const antlr4::Token *tok)
{
	const auto text = tok->getText();
	std::cout << __func__ << ": inTdef=" << inTypedef << " ID=" << text << "\n";
	return typedefs.find(text) != typedefs.end();
}

void CParser::addTypeName(const antlr4::Token *tok)
{
	if (!takeTypedef)
		return;

	const auto text = tok->getText();
	typedefs.insert(text);
	std::cout << __func__ << ": adding " << text << "\n";
}
