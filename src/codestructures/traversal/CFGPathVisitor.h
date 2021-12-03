#ifndef CFGPATHVISITOR_H
#define CFGPATHVISITOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QStack>

namespace clang {
class Stmt;
}

namespace codestructs {

class CFGPathVisitor {
public:
    using Stmt = const clang::Stmt;
    using Path = QList<Stmt *>;
    using CallStack = QStack<Stmt *>;

    virtual bool visit(const Path &path, const CallStack &cfgContext) = 0;
    virtual void endPath(const Path &path, const CallStack &cfgContext) { }
    virtual bool onCFGchange(Stmt *from, Stmt *to) { return false; }

    virtual bool visitInternal(const Path &path, const CallStack &cfgContext) {
	return terminate ? false : visit(path, cfgContext);
    }

protected:
    virtual bool forceEnd() {
	terminate = true;
	return false;
    }

private:
    bool terminate = false;
};

}

#endif
