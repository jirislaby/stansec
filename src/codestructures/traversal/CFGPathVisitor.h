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

namespace codestructs {

class CFGNode;

class CFGPathVisitor {
public:
    using Stmt = codestructs::CFGNode;
    using Path = QList<Stmt>;
    using CallStack = QStack<Stmt>;

    virtual bool visit(const Path &path, const CallStack &cfgContext) = 0;
    virtual void onEndPath(const Path &path, const CallStack &cfgContext) { }
    virtual bool onCFGchange(const Stmt &from, const Stmt &to) { return false; }
};

}

#endif
