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

#include "CFGsNavigator.h"
#include "PassingSolver.h"

namespace codestructs {

class ArgumentPassingManager {

public:
    typedef QList<QPair<QString, QString>> CallSiteToCalleeMap;

    ArgumentPassingManager() = delete;
#if 0
    ArgumentPassingManager(const CFGsNavigator &navigator,
			   const QMap<CFGNode, CFGHandle> &nodeToCFGdict) {
	build(navigator, nodeToCFGdict);
    }

    bool isIdentityPass(const CFGNode &from, const CFGNode &to) {
	assert(false);
	return false; //getMapping()[QPair(from,to)] == nullptr;
    }

    QString pass(const CFGNode &from, const QString &argument,
		 const CFGNode &to) {
	return PassingSolver::pass(argument, getMapping()[QPair(from, to)]);
    }
#endif

private:
#if 0
    void build(const CFGsNavigator &navigator,
	       const QMap<CFGNode, CFGHandle> &nodeToCFGdict);

    void buildPassingsForCallSite(const CFGNode &caller,
				  const CFGHandle &callee);

    static QList<QPair<QString, QString>>
    buildMappingFromCallSiteToCallee(const CFGNode caller,
				     const CFGHandle callee);
#endif
    static CallSiteToCalleeMap
    transposeCallSiteMapping(const CallSiteToCalleeMap &map);
#if 0
    QMap<QPair<CFGNode,CFGNode>, CallSiteToCalleeMap> getMapping() const {
	return mapping;
    }

    const QMap<QPair<CFGNode, CFGNode>, CallSiteToCalleeMap> mapping;
#endif
};

}

#endif
