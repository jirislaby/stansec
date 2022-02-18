#ifndef CFGVISITOR_H
#define CFGVISITOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include "../CFGNode.h"

namespace clang {
class CFGBlock;
class Stmt;
}

namespace codestructs {

class CFGVisitor {
public:
	virtual bool visit(const CFGNode &node/*, Element element*/) = 0;
};

class CFGVisitorIdx {
public:
	bool operator()(const clang::CFGBlock *blk, const clang::Stmt *stmt,
			size_t index) {
		return visit(blk, stmt, index);
	}
private:
	virtual bool visit(const clang::CFGBlock *blk, const clang::Stmt *stmt,
			   size_t index) = 0;
};

}

#endif
