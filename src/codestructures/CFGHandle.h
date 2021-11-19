#ifndef CFGHANDLE_H
#define CFGHANDLE_H

/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QPair>
#include <QString>

namespace clang {
class CFG;
class CFGBlock;
class FunctionDecl;
class Stmt;
}

namespace codestructs {

class CFGHandle : public QPair<clang::CFG *, const clang::FunctionDecl *> {
public:
	CFGHandle(clang::CFG *CFG, const clang::FunctionDecl *D) :
		QPair(CFG, D) {}

	clang::CFG *CFG() const { return first; }
	const clang::FunctionDecl *FD() const { return second; }

	QList<QString> getParamNames() const;

	const clang::Stmt *getStartNode() const;
	const clang::Stmt *getEndNode() const;

private:
	const clang::Stmt *getFirstStmt(clang::CFGBlock &blk) const;
	const clang::Stmt *getLastStmt(clang::CFGBlock &blk) const;

	CFGHandle() = delete;
};

}

#endif // CFGHANDLE_H
