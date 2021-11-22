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

#include "LazyInternalStructures.h"

codestructs::LazyInternalStructures::~LazyInternalStructures()
{
	delete callGraph;
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

void codestructs::LazyInternalStructures::setCallGraph()
{
	callGraph = new clang::CallGraph();
	callGraph->addToCallGraph(const_cast<clang::TranslationUnitDecl *>(TU));
}
