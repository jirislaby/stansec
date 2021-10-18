#ifndef PARSER_H
#define PARSER_H

/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <string>

#include <QMap>
#include <QString>
#include <QVector>

#include "../checker/CheckerCreator.h"
#include "../checker/CheckerErrorReceiver.h"
#include "../checker/CheckerProgressMonitor.h"

namespace clang {
class TranslationUnitDecl;
}

namespace parser {

class Parser {
public:
	Parser() = delete;
	Parser(checker::CheckerProgressMonitor *monitor,
	       checker::CheckerErrorReceiver &errReceiver);
	~Parser();

	void parseAndCheck(const std::string &in);
	void check(const codestructs::LazyInternalStructures &LIS,
		   const clang::TranslationUnitDecl *TU);

	//CFG *getFunction(unsigned int line) const;

	QString getDot(unsigned int line, int shrink = 0) const;
	QString getDot(const QString &fun, int shrink = 0) const;
	void dumpDots() const;

	void addChecker(checker::CheckerCreator *checker) {
		checkers.append(checker);
	}

private:
	QVector<checker::CheckerCreator *> checkers;
	checker::CheckerProgressMonitor *monitor;
	checker::CheckerErrorReceiver &errReceiver;
};

}

#endif // PARSER_H
