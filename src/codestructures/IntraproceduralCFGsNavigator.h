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
	emptySet(source.getEmptySet()), beginnings(source.getBeginnings()),
	endings(source.getEndings()) {}

    virtual bool isCallNode(const clang::Stmt *node) const override {
        return false;
    }

    virtual bool isStartNode(const clang::Stmt *node) const override {
	return getBeginnings().contains(node);
    }

    virtual bool isEndNode(const clang::Stmt *node) const override {
        return getEndings().contains(node);
    }

    virtual clang::Stmt *getCalleeStart(const clang::Stmt *node) const override {
	return nullptr;
    }

    virtual clang::Stmt *getCalleeEnd(const clang::Stmt *node) const override {
	return nullptr;
    }

    virtual QSet<const clang::Stmt *> getCallersFromStart(const clang::Stmt *node) const override {
        return getEmptySet();
    }

    virtual QSet<const clang::Stmt *> getCallersFromEnd(const clang::Stmt *node) const override {
        return getEmptySet();
    }

    virtual QSet<const clang::Stmt *> callSites() const override {
        return getEmptySet();
    }

private:
    void buildBeginingsAndEndings(const QList<CFGHandle> &CFGs) {
	for (const auto &cfg: CFGs) {
	    getBeginnings().insert(cfg.getStartNode());
	    getEndings().insert(cfg.getEndNode());
        }
    }

    QSet<const clang::Stmt *> &getBeginnings() { return beginnings; }
    const QSet<const clang::Stmt *> getBeginnings() const { return beginnings; }
    QSet<const clang::Stmt *> &getEndings() { return endings; }
    const QSet<const clang::Stmt *> getEndings() const { return endings; }
    const QSet<const clang::Stmt *> getEmptySet() const { return emptySet; }

    QSet<const clang::Stmt *> emptySet;
    QSet<const clang::Stmt *> beginnings;
    QSet<const clang::Stmt *> endings;
};

}

#endif
