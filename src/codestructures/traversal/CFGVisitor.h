#ifndef CFGVISITOR_H
#define CFGVISITOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

namespace clang {
class Stmt;
}

namespace codestructs {

class CFGVisitor {
public:
	virtual bool visit(const clang::Stmt *node/*, Element element*/) = 0;

	/* for clang::CFG::VisitBlockStmts */
	void operator()(clang::Stmt *stmt) {
	    visit(stmt);
	}
};

}

#endif
