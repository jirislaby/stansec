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

class CFGsNavigator {
public:
	virtual ~CFGsNavigator() = 0;
#if 0
	bool isCallNode(const CFGNode node) const;
	bool isStartNode(const CFGNode node) const;
	bool isEndNode(const CFGNode node) const;
	CFGNode getCalleeStart(const CFGNode node) const;
	CFGNode getCalleeEnd(const CFGNode node) const;
	QSet<CFGNode> getCallersFromStart(const CFGNode node) const;
	QSet<CFGNode> getCallersFromEnd(const CFGNode node) const;
	QSet<CFGNode> callSites() const;
#endif
};

}

#endif
