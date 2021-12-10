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
#include "CFGsNavigator.h"
#include "CFGHandle.h"
#include "CFGNode.h"

using namespace codestructs;

void ArgumentPassingManager::build(const CFGsNavigator &navigator,
				   const NodeToCFGdictionaryBuilder::NodeToCFGDictionary &nodeToCFGdict)
{
    for (const auto caller : navigator.callSites()) {
	const auto start = navigator.getCalleeStart(caller);
	buildPassingsForCallSite(caller.getStmt(), *nodeToCFGdict[start]);
    }
}

void ArgumentPassingManager::buildPassingsForCallSite(const clang::Stmt *caller,
						      const CFGHandle &callee)
{
#if 0
	auto map = buildMappingFromCallSiteToCallee(caller, callee);
	getMapping().put(QPair.make(caller, callee.getStartNode()),map);
	getMapping().put(QPair.make(caller, callee.getEndNode()), map);

	const QList<QPair<QString,QString>> mapTransposed =
		transposeCallSiteMapping(map);
	getMapping().put(QPair.make(callee.getStartNode(), caller),mapTransposed);
	getMapping().put(QPair.make(callee.getEndNode(), caller),mapTransposed);
#else
	assert(0); abort();
#endif
}

#if 0
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

#endif
