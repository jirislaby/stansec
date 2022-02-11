#ifndef INTRAPROCEDURALCFGSNAVIGATOR_H
#define INTRAPROCEDURALCFGSNAVIGATOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QSet>

#include "CFGsNavigator.h"
#include "CFGHandle.h"
#include "CFGNode.h"

namespace codestructs {

class IntraproceduralCFGsNavigator final : public CFGsNavigator {

public:
    IntraproceduralCFGsNavigator(const QList<CFGHandle> &CFGs) {
        buildBeginingsAndEndings(CFGs);
    }

    IntraproceduralCFGsNavigator(const IntraproceduralCFGsNavigator &source) :
	beginnings(source.getBeginnings()), endings(source.getEndings()) {}

    virtual bool isCallNode(const Node &node) const override {
        return false;
    }

    virtual bool isStartNode(const Node &node) const override {
	return getBeginnings().contains(node);
    }

    virtual bool isEndNode(const Node &node) const override {
        return getEndings().contains(node);
    }

    virtual Node getCalleeStart(const Node &node) const override {
	return Node();
    }

    virtual Node getCalleeEnd(const Node &node) const override {
	return Node();
    }

    virtual NodeList getCallersFromStart(const Node &node) const override {
	return NodeList();
    }

    virtual NodeList getCallersFromEnd(const Node &node) const override {
	return NodeList();
    }

    virtual NodeList callSites() const override {
	return NodeList();
    }

private:
    void buildBeginingsAndEndings(const QList<CFGHandle> &CFGs) {
	for (const auto &cfg: CFGs) {
	    getBeginnings().append(cfg.getStartNode());
	    getEndings().append(cfg.getEndNode());
        }
    }

    NodeList &getBeginnings() { return beginnings; }
    const NodeList getBeginnings() const { return beginnings; }
    NodeList &getEndings() { return endings; }
    const NodeList getEndings() const { return endings; }

    NodeList beginnings;
    NodeList endings;
};

}

#endif
