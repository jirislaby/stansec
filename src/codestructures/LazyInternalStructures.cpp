/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/Analysis/CFG.h>
#include <clang/AST/Decl.h>

#include <clang/Analysis/CallGraph.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h>

#include "builders/NodeToCFGdictionaryBuilder.h"
#include "builders/StartFunctionsSetBuilder.h"

#include "ArgumentPassingManager.h"
#include "CFGsNavigator.h"
#include "LazyInternalStructures.h"

using namespace codestructs;

LazyInternalStructures::~LazyInternalStructures()
{
	delete argumentPassingManager;
	delete callGraph;
	delete navigator;
}

QList<CFGHandle> LazyInternalStructures::getCFGHandles() const
{
	QList<CFGHandle> result;

	for (const auto &d : TU->decls())
	    if (auto fd = llvm::dyn_cast<const clang::FunctionDecl>(d)) {
		if (!fd->isThisDeclarationADefinition() || !fd->hasBody())
		    continue;
		if (!llvm::isa<clang::NamedDecl>(d))
		    continue;
		result.append(CFGHandle(mgr.getCFG(d), fd));
	    }
	return result;
}

void LazyInternalStructures::setStartFunctions() {
	assert(startFunctions.empty());
	startFunctions = StartFunctionsSetBuilder::run(*this, *getCallGraph());
}

void LazyInternalStructures::setCallGraph()
{
	assert(!callGraph);
	callGraph = new clang::CallGraph();
	callGraph->addToCallGraph(const_cast<clang::TranslationUnitDecl *>(TU));
}

void LazyInternalStructures::setArgumentPassingManager() {
	assert(!argumentPassingManager);
	argumentPassingManager = new ArgumentPassingManager(getNavigator(),
							    getNodeToCFGdictionary());
}

void LazyInternalStructures::setReturnValuePassingManager() {
#if 0
	if (returnValuePassingManager == null)
		returnValuePassingManager =
				new ReturnValuePassingManager(getNavigator());
#else
	assert(false); abort();
#endif
}

void LazyInternalStructures::setNodeToCFGdictionary() {
	assert(nodeToCFGdictionary.empty());
	NodeToCFGdictionaryBuilder::run(getCFGHandles(), nodeToCFGdictionary);
}

void LazyInternalStructures::setElementToCFGdictionary() {
#if 0
	if (elementToCFGdictionary == null)
		elementToCFGdictionary = new ElementCFGdictionary(getCFGHandles());
#else
	assert(false); abort();
#endif
}
