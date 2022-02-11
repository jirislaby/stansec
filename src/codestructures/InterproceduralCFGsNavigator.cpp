/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/Analysis/CFG.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h>

#include <QMap>

#include "CFGHandle.h"
#include "InterproceduralCFGsNavigator.h"

using namespace codestructs;

void InterproceduralCFGsNavigator::build(const QList<CFGHandle> &CFGs)
{
	QMap<const clang::Decl *, const CFGHandle *> declHandle;

	for (const CFGHandle &cfgh : CFGs)
		declHandle.insert(cfgh.getFD(), &cfgh);

	for (const CFGHandle &cfgh : CFGs) {
		auto visitor = [this, &declHandle](clang::Stmt *stmt) {
			if (auto CE = llvm::dyn_cast<clang::CallExpr>(stmt)) {
				auto callee = CE->getDirectCallee();
				if (!callee || !declHandle.contains(callee))
					return;
				fillDictionaries(CFGNode(stmt),
						 *declHandle[callee]);
			}
		};
		cfgh.getCFG()->VisitBlockStmts(visitor);
	}
}

void InterproceduralCFGsNavigator::fillDictionaries(const CFGNode &callSite,
						    const CFGHandle &callee)
{
	getCallToStart().insert(callSite, callee.getStartNode());

	getCallToEnd().insert(callSite, callee.getEndNode());

	if (!getBeginnings().contains(callee.getStartNode()))
		getBeginnings().insert(callee.getStartNode(), NodeList());
	getBeginnings()[callee.getStartNode()].append(callSite);

	if (!getEndings().contains(callee.getEndNode()))
		getEndings().insert(callee.getEndNode(), NodeList());
	getEndings()[callee.getEndNode()].append(callSite);
}
