/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <llvm/ADT/PostOrderIterator.h>
#include <clang/Analysis/CallGraph.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h>

#include "../LazyInternalStructures.h"

#include "StartFunctionsSetBuilder.h"

using namespace codestructs;

QSet<clang::CFG *> StartFunctionsSetBuilder::run(const LazyInternalStructures &internals,
						 const clang::CallGraph &callGraph)
{
    auto &mgr = internals.getAnalysisManager();
    auto root = callGraph.getRoot();

    QSet<clang::CFG *> result;
    llvm::ReversePostOrderTraversal<const clang::CallGraph *> RPOT(&callGraph);
    for (auto I = RPOT.begin(), E = RPOT.end(); I != E; ++I) {
	auto N = *I;
	for (auto calleeRec : N->callees()) {
	    auto callee = calleeRec.Callee;
	    auto CFG = mgr.getCFG(callee->getDecl());
	    if (N == root)
		result.insert(CFG);
	    else
		assert(result.remove(CFG));
	}
    }

    return result;
}
