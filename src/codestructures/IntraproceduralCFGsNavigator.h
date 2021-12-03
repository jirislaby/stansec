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

namespace codestructs {

class IntraproceduralCFGsNavigator final : public CFGsNavigator {

public:
    IntraproceduralCFGsNavigator(const QList<CFGHandle> &CFGs) {
        buildBeginingsAndEndings(CFGs);
    }

    IntraproceduralCFGsNavigator(const IntraproceduralCFGsNavigator &source) :
	beginnings(source.getBeginnings()), endings(source.getEndings()) {}

    virtual bool isCallNode(Node *node) const override {
        return false;
    }

    virtual bool isStartNode(Node *node) const override {
	return getBeginnings().contains(node);
    }

    virtual bool isEndNode(Node *node) const override {
        return getEndings().contains(node);
    }

    virtual clang::Stmt *getCalleeStart(Node *node) const override {
	return nullptr;
    }

    virtual clang::Stmt *getCalleeEnd(Node *node) const override {
	return nullptr;
    }

    virtual NodeSet getCallersFromStart(Node *node) const override {
	return NodeSet();
    }

    virtual NodeSet getCallersFromEnd(Node *node) const override {
	return NodeSet();
    }

    virtual NodeSet callSites() const override {
	return NodeSet();
    }

private:
    void buildBeginingsAndEndings(const QList<CFGHandle> &CFGs) {
	for (const auto &cfg: CFGs) {
	    getBeginnings().insert(cfg.getStartNode());
	    getEndings().insert(cfg.getEndNode());
        }
    }

    NodeSet &getBeginnings() { return beginnings; }
    const NodeSet getBeginnings() const { return beginnings; }
    NodeSet &getEndings() { return endings; }
    const NodeSet getEndings() const { return endings; }

    NodeSet beginnings;
    NodeSet endings;
};

}

#endif
