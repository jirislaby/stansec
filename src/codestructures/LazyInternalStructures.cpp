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

#include "ArgumentPassingManager.h"
#include "LazyInternalStructures.h"

codestructs::LazyInternalStructures::~LazyInternalStructures()
{
	delete callGraph;
	delete argumentPassingManager;
}

QList<codestructs::CFGHandle> codestructs::LazyInternalStructures::getCFGHandles() const
{
	QList<codestructs::CFGHandle> result;

	for (const auto &d : TU->decls())
	    if (auto fd = dynamic_cast<const clang::FunctionDecl *>(d)) {
		if (!fd->isThisDeclarationADefinition())
		    continue;
		if (dynamic_cast<const clang::NamedDecl *>(d)) {
		    result.append(codestructs::CFGHandle(mgr.getCFG(d), fd));
		}
	    }
	return result;
}

void codestructs::LazyInternalStructures::setStartFunctions() {
	assert(startFunctions.empty());
	startFunctions = StartFunctionsSetBuilder::run(*this, *getCallGraph());
}

void codestructs::LazyInternalStructures::setCallGraph()
{
	assert(!callGraph);
	callGraph = new clang::CallGraph();
	callGraph->addToCallGraph(const_cast<clang::TranslationUnitDecl *>(TU));
}

void codestructs::LazyInternalStructures::setArgumentPassingManager() {
	assert(!argumentPassingManager);
	argumentPassingManager = new codestructs::ArgumentPassingManager(getNavigator(),
							    getNodeToCFGdictionary());
}

void codestructs::LazyInternalStructures::setReturnValuePassingManager() {
#if 0
	if (returnValuePassingManager == null)
		returnValuePassingManager =
				new ReturnValuePassingManager(getNavigator());
#else
	assert(false); abort();
#endif
}

void codestructs::LazyInternalStructures::setNodeToCFGdictionary() {
	assert(nodeToCFGdictionary.empty());
	NodeToCFGdictionaryBuilder::run(getCFGHandles(), nodeToCFGdictionary);
}

void codestructs::LazyInternalStructures::setElementToCFGdictionary() {
#if 0
	if (elementToCFGdictionary == null)
		elementToCFGdictionary = new ElementCFGdictionary(getCFGHandles());
#else
	assert(false); abort();
#endif
}
