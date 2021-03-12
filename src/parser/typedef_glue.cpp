#include "generated/CParser.h"

#undef DEBUG_LOCK
#undef DEBUG_ISTYPENAME
#undef DEBUG_ADDTYPENAME
#undef DUMP_TYPES

void CParser::typedefLock()
{
	if (inTypedef) {
#ifdef DEBUG_LOCK
		auto ctx = getContext();
		std::cout << __func__ << " mutex=" << typedefMutex << " for '" << ctx->getText() << "'\n";
#endif
		typedefMutex++;
	}
}

void CParser::typedefUnlock(bool stop)
{
	if (inTypedef) {
#ifdef DEBUG_LOCK
		auto ctx = getContext();
		std::cout << __func__ << " mutex=" << typedefMutex << " for '" << ctx->getText() << "'\n";
#endif
		typedefMutex--;
	}
	if (stop)
		inTypedef = false;
}

bool CParser::isTypeName(const antlr4::Token *tok)
{
	const auto text = tok->getText();
	auto ret = typedefs.find(text) != typedefs.end();

#ifdef DEBUG_ISTYPENAME
	std::cout << __func__ << ": inTdef=" << inTypedef << " ID=" << text << " => " << ret << "\n";
#endif

	return ret;
}

void CParser::addTypeName(const antlr4::Token *tok)
{
	if (typedefMutex != 0)
		return;

	const auto text = tok->getText();
	typedefs.insert(text);
#ifdef DEBUG_ADDTYPENAME
	std::cout << __func__ << ": adding " << text << " from line " << tok->getLine() << "\n";
#endif
}

void CParser::dumpTypes()
{
#ifdef DUMP_TYPES
	std::cout << "Dumping types:\n" <<
		"===========================\n";
	for (const auto type: typedefs)
		std::cout << "\t" << type << "\n";
	std::cout << "===========================\n";
#endif
}
