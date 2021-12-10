#ifndef CFGSNAVIGATOR_H
#define CFGSNAVIGATOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QSet>

namespace codestructs {

class CFGNode;

class CFGsNavigator {
public:
	using Node = codestructs::CFGNode;
	using NodeSet = QSet<Node>;

	virtual ~CFGsNavigator() {}

	virtual bool isCallNode(const Node &node) const = 0;
	virtual bool isStartNode(const Node &node) const = 0;
	virtual bool isEndNode(const Node &node) const = 0;
	virtual Node getCalleeStart(const Node &node) const = 0;
	virtual Node getCalleeEnd(const Node &node) const = 0;
	virtual NodeSet getCallersFromStart(const Node &node) const = 0;
	virtual NodeSet getCallersFromEnd(const Node &node) const = 0;
	virtual NodeSet callSites() const = 0;
};

}

#endif
