#ifndef PARSER_MAIN_H
#define PARSER_MAIN_H

#include <memory>
#include <string>

#include <QMap>
#include <QString>

class CFG;
class CLexer;
class CParser;
namespace antlr4 {
	class ANTLRInputStream;
	class CommonTokenStream;
}

class Parser {
public:
	Parser();
	~Parser();

	void parse(const std::string &in);

	std::string getParseTree(const std::string &in);

	QMap<QString, CFG *>::const_iterator cfgBegin() const { return map.begin(); }
	QMap<QString, CFG *>::const_iterator cfgEnd() const { return map.end(); }

	CFG *getFunction(unsigned int line) const;

	QString getDot(unsigned int line, int shrink = 0) const;
	QString getDot(const QString &fun, int shrink = 0) const;
	void dumpDots() const;

private:
	QMap<QString, CFG *> map;
	std::unique_ptr<antlr4::ANTLRInputStream> input;
	std::unique_ptr<CLexer> lexer;
	std::unique_ptr<antlr4::CommonTokenStream> tokens;
	std::unique_ptr<CParser> parser;
};

#endif
