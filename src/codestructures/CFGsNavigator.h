#ifndef CFGSNAVIGATOR_H
#define CFGSNAVIGATOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>

namespace codestructs {

class CFGNode;

class CFGsNavigator {
public:
	using Node = codestructs::CFGNode;
	using NodeList = QList<Node>;

	virtual ~CFGsNavigator() {}

	virtual bool isCallNode(const Node &node) const = 0;
	virtual bool isStartNode(const Node &node) const = 0;
	virtual bool isEndNode(const Node &node) const = 0;
	virtual Node getCalleeStart(const Node &node) const = 0;
	virtual Node getCalleeEnd(const Node &node) const = 0;
	virtual NodeList getCallersFromStart(const Node &node) const = 0;
	virtual NodeList getCallersFromEnd(const Node &node) const = 0;
	virtual NodeList callSites() const = 0;
};

}

#endif
