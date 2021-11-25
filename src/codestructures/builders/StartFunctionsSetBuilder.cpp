/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */
#include <llvm/ADT/PostOrderIterator.h>

#include <clang/AST/Decl.h>
#include <clang/Analysis/CallGraph.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h>

#include "../LazyInternalStructures.h"

#include "StartFunctionsSetBuilder.h"

using namespace codestructs;

QSet<CFGHandle> StartFunctionsSetBuilder::run(const LazyInternalStructures &internals,
					      const clang::CallGraph &callGraph)
{
    auto &mgr = internals.getAnalysisManager();
    auto root = callGraph.getRoot();

    QSet<CFGHandle> result;

    llvm::ReversePostOrderTraversal<const clang::CallGraph *> RPOT(&callGraph);
    for (auto I = RPOT.begin(), E = RPOT.end(); I != E; ++I) {
	auto N = *I;
	for (auto calleeRec : N->callees()) {
	    auto callee = calleeRec.Callee;
	    const auto calleeFDecl = dynamic_cast<const clang::FunctionDecl *>(callee->getDecl());
	    assert(calleeFDecl);
	    auto CFG = mgr.getCFG(calleeFDecl);
	    CFGHandle handle(CFG, calleeFDecl);
	    if (N == root)
		result.insert(handle);
	    else
		result.remove(handle);
	}
    }

    return result;
}
