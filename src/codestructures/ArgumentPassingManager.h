#ifndef ARGUMENTPASSINGMANAGER_H
#define ARGUMENTPASSINGMANAGER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <llvm/ADT/Optional.h>

#include <QList>
#include <QMap>
#include <QPair>
#include <QString>

#include "../codestructures/CFGNode.h"

#include "LazyInternalStructures.h"
#include "PassingSolver.h"

namespace clang {
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

    llvm::Optional<QString> pass(const clang::Stmt *from,
				 const QString &argument,
				 const codestructs::CFGNode &to) {
	return PassingSolver::pass(argument, getMapping()[qMakePair(CFGNode(from), to)]);
    }

private:
    using CallSiteToCalleeMap = QList<QPair<QString, QString> >;
    using Mapping = QMap<QPair<const codestructs::CFGNode, const codestructs::CFGNode>, CallSiteToCalleeMap>;

    void build(const CFGsNavigator &navigator,
	       const LazyInternalStructures::NodeToCFGDictionary &nodeToCFGdict);

    void buildPassingsForCallSite(const clang::Stmt *caller,
				  const CFGHandle &callee);

    static CallSiteToCalleeMap
    buildMappingFromCallSiteToCallee(const clang::Stmt *caller,
				     const CFGHandle &callee);

    static CallSiteToCalleeMap
    transposeCallSiteMapping(const CallSiteToCalleeMap &map);

    Mapping getMapping() const { return mapping; }
    Mapping &getMapping() { return mapping; }

    Mapping mapping;
};

}

#endif
