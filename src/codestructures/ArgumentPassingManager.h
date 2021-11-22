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
			   const QMap<const clang::Stmt *, CFGHandle *> &nodeToCFGdict) {
	build(navigator, nodeToCFGdict);
    }

    bool isIdentityPass(const clang::Stmt *from, const clang::Stmt *to) {
	return !getMapping().contains(qMakePair(from,to));
    }

    QString pass(const clang::Stmt *from, const QString &argument,
		 const clang::Stmt *to) {
	return PassingSolver::pass(argument, getMapping()[qMakePair(from, to)]);
    }

private:
    using CallSiteToCalleeMap = QList<QPair<QString, QString> >;
    using Mapping = QMap<QPair<const clang::Stmt *, const clang::Stmt *>, CallSiteToCalleeMap>;

    void build(const CFGsNavigator &navigator,
	       const QMap<const clang::Stmt *, CFGHandle *> &nodeToCFGdict);

    void buildPassingsForCallSite(const clang::Stmt &caller,
				  const CFGHandle &callee);

    static CallSiteToCalleeMap
    buildMappingFromCallSiteToCallee(const clang::Stmt &caller,
				     const CFGHandle &callee);

    static CallSiteToCalleeMap
    transposeCallSiteMapping(const CallSiteToCalleeMap &map);

    Mapping getMapping() const { return mapping; }
    Mapping &getMapping() { return mapping; }

    Mapping mapping;
};

}

#endif
