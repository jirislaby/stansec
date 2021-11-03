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
#ifdef NEEDED
	bool forceEnd() {
	    return !(terminate = true);
	}

	bool visitInternal(const clang::Stmt *node/*, Element element*/) {
	    return terminate ? false : visit(node/*, element*/);
	}
private:
	bool terminate = false;
#else
	bool visitInternal(const clang::Stmt *node/*, Element element*/) {
	    return visit(node/*, element*/);
	}
#endif
};

}

#endif
