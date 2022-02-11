#ifndef INTERPROCEDURALCFGSNAVIGATOR_H
#define INTERPROCEDURALCFGSNAVIGATOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QMap>
#include <QSet>

#include "CFGNode.h"
#include "CFGsNavigator.h"

namespace codestructs {

class CFGHandle;

class InterproceduralCFGsNavigator final : public CFGsNavigator {

public:

    InterproceduralCFGsNavigator(const QList<CFGHandle> &CFGs) {
	build(CFGs);
    }

#ifdef NEEDED
    InterproceduralCFGsNavigator(const InterproceduralCFGsNavigator &source) {
        callToStart = source.getCallToStart();
        callToEnd = source.getCallToEnd();
        beginings = source.getBeginings();
        endings = source.getEndings();
    }
#endif

    virtual bool isCallNode(const CFGNode &node) const override {
	return getCallToStart().contains(node);
    }

    virtual bool isStartNode(const CFGNode &node) const override {
	return getBeginnings().contains(node);
    }

    virtual bool isEndNode(const CFGNode& node) const override {
	return getEndings().contains(node);
    }

    virtual Node getCalleeStart(const Node &node) const override {
	return getCallToStart()[node];
    }

    virtual Node getCalleeEnd(const Node &node) const override {
	return getCallToEnd()[node];
    }

    virtual NodeList getCallersFromStart(const CFGNode &node) const override {
	return getBeginnings()[node];
    }

    virtual NodeList getCallersFromEnd(const CFGNode &node) const override {
	return getEndings()[node];
    }

    virtual NodeList callSites() const override {
	return getCallToStart().keys();
    }

private:
    using NodeToNodeMap = QMap<Node, Node>;
    using NodeToNodeListMap = QMap<Node, NodeList>;

    void build(const QList<CFGHandle> &CFGs);
    void fillDictionaries(const CFGNode &callSite, const CFGHandle &callee);

    NodeToNodeMap &getCallToStart() { return callToStart; }
    NodeToNodeMap &getCallToEnd() { return callToEnd; }
    NodeToNodeListMap &getBeginnings() { return beginings; }
    NodeToNodeListMap &getEndings() { return endings; }

    const NodeToNodeMap &getCallToStart() const { return callToStart; }
    const NodeToNodeMap &getCallToEnd() const { return callToEnd; }
    const NodeToNodeListMap &getBeginnings() const { return beginings; }
    const NodeToNodeListMap &getEndings() const { return endings; }

    NodeToNodeMap callToStart;
    NodeToNodeMap callToEnd;
    NodeToNodeListMap beginings;
    NodeToNodeListMap endings;
};

}

#endif
