#ifndef ARGUMENTPASSINGMANAGER_H
#define ARGUMENTPASSINGMANAGER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QMap>
#include <QPair>
#include <QString>

#include "../codestructures/CFGNode.h"

#include "LazyInternalStructures.h"
#include "PassingSolver.h"

namespace clang {
class Expr;
class Stmt;
}

namespace codestructs {

class CFGHandle;
class CFGsNavigator;

class ArgumentPassingManager {
public:
    ArgumentPassingManager() = delete;

    ArgumentPassingManager(const CFGsNavigator &navigator,
			   const LazyInternalStructures::NodeToCFGDictionary &nodeToCFGdict) {
	build(navigator, nodeToCFGdict);
    }

    bool isIdentityPass(const codestructs::CFGNode &from,
			const codestructs::CFGNode &to) {
	return !getMapping().contains(qMakePair(from, to));
    }

    const clang::Expr *pass(const codestructs::CFGNode &from,
			    const clang::Expr *argument,
			    const codestructs::CFGNode &to) {
	assert(from.hasStmt());
	return PassingSolver::pass(argument, getMapping()[qMakePair(from, to)]);
    }

private:
    using Mapping = QMap<QPair<const codestructs::CFGNode, const codestructs::CFGNode>,
	PassingSolver::CallSiteToCalleeMap>;

    void build(const CFGsNavigator &navigator,
	       const LazyInternalStructures::NodeToCFGDictionary &nodeToCFGdict);

    void buildPassingsForCallSite(const clang::Stmt *caller,
				  const CFGHandle &callee);
#ifdef NEEDED
    static PassingSolver::CallSiteToCalleeMap
    buildMappingFromCallSiteToCallee(const clang::Stmt *caller,
				     const CFGHandle &callee);

    static PassingSolver::CallSiteToCalleeMap
    transposeCallSiteMapping(const PassingSolver::CallSiteToCalleeMap &map);
#endif
    Mapping getMapping() const { return mapping; }
    Mapping &getMapping() { return mapping; }

    Mapping mapping;
};

}

#endif
