/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Stmt.h>
#include <clang/Analysis/CFG.h>

#include "../CFGHandle.h"
#include "NodeToCFGdictionaryBuilder.h"

using namespace codestructs;

void NodeToCFGdictionaryBuilder::run(const QList<CFGHandle> &CFGs,
				     NodeToCFGDictionary &dict)
{
	struct CFGVisitor {
		CFGVisitor(const CFGHandle *handle, NodeToCFGDictionary &dict) :
			handle(handle), dict(dict) {}
		void operator()(clang::Stmt *stmt) { dict.insert(stmt, handle); }
		const CFGHandle *handle;
		NodeToCFGDictionary &dict;
	};

	for (const auto &cfg: CFGs) {
		CFGVisitor v(&cfg, dict);
		cfg.CFG()->VisitBlockStmts(v);
	}
}
