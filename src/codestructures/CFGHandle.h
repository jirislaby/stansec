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

class CFGHandle final {
public:
	CFGHandle(clang::CFG *CFG, const clang::FunctionDecl *FD) :
		CFG(CFG), FD(FD) { }

	clang::CFG *getCFG() const { return CFG; }
	const clang::FunctionDecl *getFD() const { return FD; }

	QString getName() const;
	QList<QString> getParamNames() const;

	const clang::Stmt *getStartNode() const;
	const clang::Stmt *getEndNode() const;

private:
	const clang::Stmt *getFirstStmt(const clang::CFGBlock &blk) const;
	const clang::Stmt *getLastStmt(const clang::CFGBlock &blk) const;

	clang::CFG *CFG;
	const clang::FunctionDecl *FD;

	CFGHandle() = delete;
};

inline bool operator==(const CFGHandle &lhs, const CFGHandle &rhs)
{
	return lhs.getCFG() == rhs.getCFG();
}

inline uint qHash(const CFGHandle &item)
{
	return ::qHash(item.getCFG());
}

}

#endif // CFGHANDLE_H
