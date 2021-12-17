/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Stmt.h>
#include <clang/Analysis/CFG.h>

#include "../CFGHandle.h"
#include "../CFGNode.h"

#include "NodeToCFGdictionaryBuilder.h"

using namespace codestructs;

void NodeToCFGdictionaryBuilder::run(const QList<CFGHandle> &CFGs,
				     LazyInternalStructures::NodeToCFGDictionary &dict)
{
	for (const auto &cfg: CFGs) {
		auto cfg2 = cfg.getCFG();
		for (auto I = cfg2->begin(), E = cfg2->end(); I != E; ++I) {
		    dict.insert(CFGNode(*I), cfg);
		    for (auto BI = (*I)->begin(), BE = (*I)->end(); BI != BE; ++BI)
			if (auto stmt = BI->getAs<clang::CFGStmt>())
				dict.insert(CFGNode(stmt->getStmt()), cfg);
		}
	}
}
