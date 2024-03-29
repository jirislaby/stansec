#ifndef PARSER_H
#define PARSER_H

/*
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <string>

#include <QList>
#include <QMap>
#include <QString>

#include "../core/CheckerConfiguration.h"
#include "../checker/CheckerErrorReceiver.h"

namespace checker {
class CheckerProgressMonitor;
}

namespace parser {

class Parser {
public:
	Parser() = delete;
	Parser(checker::CheckerProgressMonitor *monitor,
	       checker::CheckerErrorReceiver &errReceiver,
	       const QList<core::CheckerConfiguration> &checkers);
	~Parser();

	checker::CheckerProgressMonitor *getMonitor() const { return monitor; }

	void parseAndCheck(const std::string &fileName, const std::string &in);
	void check(const codestructs::LazyInternalStructures &LIS);

	//CFG *getFunction(unsigned int line) const;

	QString getDot(unsigned int line, int shrink = 0) const;
	QString getDot(const QString &fun, int shrink = 0) const;
	void dumpDots() const;

private:
	QList<core::CheckerConfiguration> checkers;
	checker::CheckerProgressMonitor *monitor;
	checker::CheckerErrorReceiver &errReceiver;
};

}

#endif // PARSER_H
