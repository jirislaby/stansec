#ifndef CFGSNAVIGATOR_H
#define CFGSNAVIGATOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QSet>

namespace clang {
class Stmt;
}

namespace codestructs {

class CFGsNavigator {
public:
	virtual ~CFGsNavigator() = 0;

	bool isCallNode(const clang::Stmt *node) const;
	bool isStartNode(const clang::Stmt *node) const;
	bool isEndNode(const clang::Stmt *node) const;
	clang::Stmt *getCalleeStart(const clang::Stmt *node) const;
	clang::Stmt *getCalleeEnd(const clang::Stmt *node) const;
	QSet<clang::Stmt *> getCallersFromStart(const clang::Stmt *node) const;
	QSet<clang::Stmt *> getCallersFromEnd(const clang::Stmt *node) const;
	QSet<clang::Stmt *> callSites() const;
};

}

#endif
