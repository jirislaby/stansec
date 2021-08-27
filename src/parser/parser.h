#ifndef PARSER_H
#define PARSER_H

//#include <memory>
#include <string>

#include <QMap>
#include <QString>

namespace parser {

class Parser {
public:
	Parser();
	~Parser();

	void parse(const std::string &in);

	//std::string getParseTree(const std::string &in);

	//QMap<QString, CFG *>::const_iterator cfgBegin() const { return map.begin(); }
	//QMap<QString, CFG *>::const_iterator cfgEnd() const { return map.end(); }

	//CFG *getFunction(unsigned int line) const;

	QString getDot(unsigned int line, int shrink = 0) const;
	QString getDot(const QString &fun, int shrink = 0) const;
	void dumpDots() const;

private:
	//QMap<QString, CFG *> map;
};

}

#endif // PARSER_H
