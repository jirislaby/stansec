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
	using Node = const clang::Stmt;
	using NodeSet = QSet<Node *>;

	virtual ~CFGsNavigator() {}

	virtual bool isCallNode(Node *node) const = 0;
	virtual bool isStartNode(Node *node) const = 0;
	virtual bool isEndNode(Node *node) const = 0;
	virtual Node *getCalleeStart(Node *node) const = 0;
	virtual Node *getCalleeEnd(Node *node) const = 0;
	virtual NodeSet getCallersFromStart(Node *node) const = 0;
	virtual NodeSet getCallersFromEnd(Node *node) const = 0;
	virtual NodeSet callSites() const = 0;
};

}

#endif
