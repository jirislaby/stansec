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

#include "builders/XMLLinearizeASTElement.h"

#include "ArgumentPassingManager.h"

#if 0
void ArgumentPassingManager::build(const CFGsNavigator &navigator,
				   const QMap<CFGNode,CFGHandle> &nodeToCFGdict) {
    for (const auto caller : navigator.callSites()) {
	const auto start = navigator.getCalleeStart(caller);
	buildPassingsForCallSite(caller, nodeToCFGdict[start]);
    }
}

    private void
    buildPassingsForCallSite(const CFGNode caller,
                             const CFGHandle callee) {
        const QList<QPair<QString,QString>> map =
            buildMappingFromCallSiteToCallee(caller, callee);
        getMapping().put(QPair.make(caller, callee.getStartNode()),map);
        getMapping().put(QPair.make(caller, callee.getEndNode()), map);

        const QList<QPair<QString,QString>> mapTransposed =
            transposeCallSiteMapping(map);
        getMapping().put(QPair.make(callee.getStartNode(), caller),mapTransposed);
        getMapping().put(QPair.make(callee.getEndNode(), caller),mapTransposed);
    }

    private static QList<QPair<QString,QString>>
    buildMappingFromCallSiteToCallee(const CFGNode caller,
                                     const CFGHandle callee) {
        const QList<QPair<QString,QString>> result =
            new QList<QPair<QString,QString>>();

        if (caller.getNodeType() != null) {
            Iterator<CFGNode.Operand> opIter = caller.getOperands().iterator();
            opIter.next();
            Iterator<QString> paramIter = callee.getParams().iterator();
            while (opIter.hasNext()) {
                assert paramIter.hasNext();
                result.add(QPair.make(PassingSolver.makeArgument(opIter.next()), paramIter.next()));
            }
            assert !paramIter.hasNext();
        } else {
            const Iterator<Element> callIter =
                XMLLinearizeASTElement.functionCall(caller.getElement()).iterator();
            const Iterator<Element> calleeIter =
                XMLLinearizeASTElement.functionDeclaration(callee.getElement()).iterator();
            for (callIter.next(), calleeIter.next(); callIter.hasNext(); )
                result.add(QPair.make(PassingSolver
                                                 .makeArgument(callIter.next()),
                                     PassingSolver
                                                 .makeArgument(calleeIter.next())));
        }
        return result;
    }

    private static QList<QPair<QString,QString>>
    transposeCallSiteMapping(const QList<QPair<QString, QString>> map) {
        const QList<QPair<QString, QString>> result =
                                         new QList<QPair<QString, QString>>();
        for (const QPair<QString,QString> item : map)
            result.add(QPair.make(item.getSecond(),item.getFirst()));
        return result;
    }

    private QMap<QPair<CFGNode,CFGNode>,QList<QPair<QString, QString>>>
    getMapping() {
        return mapping;
    }

    private const QMap<QPair<CFGNode,CFGNode>,
                          QList<QPair<QString,QString>>> mapping;
}
#endif
