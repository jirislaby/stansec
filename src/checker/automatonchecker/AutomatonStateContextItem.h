#ifndef AUTOMATONSTATECONTEXTITEM_H
#define AUTOMATONSTATECONTEXTITEM_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include "../../codestructures/CFGNode.h"

#include "ComposedAutomatonID.h"

namespace clang {
class Stmt;
}

namespace checker {

class AutomatonStateContextItem {
    // package-private section
public:

    // only for QStack::pop to be happy
    AutomatonStateContextItem() :
	    AutomatonStateContextItem(ComposedAutomatonID(QList<SimpleAutomatonID>())) {
	    assert(0);
	    abort();
    }

    explicit AutomatonStateContextItem(ComposedAutomatonID automatonID) :
	cfgNode(), automatonID(automatonID) { }

    AutomatonStateContextItem(const codestructs::CFGNode &cfgNode,
			      const ComposedAutomatonID automatonID) :
	    cfgNode(cfgNode), automatonID(automatonID) { }

    AutomatonStateContextItem(const AutomatonStateContextItem &source,
			      const ComposedAutomatonID automatonID) :
	    cfgNode(source.getCFGNode()), automatonID(automatonID) { }

    const codestructs::CFGNode &getCFGNode() const { return cfgNode; }
    ComposedAutomatonID getAutomatonID() const { return automatonID; }

private:
    codestructs::CFGNode cfgNode;
    ComposedAutomatonID automatonID;
};

inline bool operator==(const AutomatonStateContextItem &lhs,
		       const AutomatonStateContextItem &rhs)
{
	return lhs.getCFGNode() == rhs.getCFGNode() &&
			lhs.getAutomatonID() == rhs.getAutomatonID();
}

inline bool operator<(const AutomatonStateContextItem &lhs,
		      const AutomatonStateContextItem &rhs)
{
	return lhs.getCFGNode() < rhs.getCFGNode() &&
			lhs.getAutomatonID() < rhs.getAutomatonID();
}

inline uint qHash(const AutomatonStateContextItem &item, uint seed = 0)
{
	return 7 * qHash(item.getAutomatonID(), seed);/* +
			qHash(item.getCFGNode(), seed);*/
}

}

#endif
