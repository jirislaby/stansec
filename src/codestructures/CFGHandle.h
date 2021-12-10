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
class FunctionDecl;
}

namespace codestructs {

class CFGNode;

class CFGHandle final {
public:
	CFGHandle(clang::CFG *CFG, const clang::FunctionDecl *FD) :
		CFG(CFG), FD(FD) { }

	clang::CFG *getCFG() const { return CFG; }
	const clang::FunctionDecl *getFD() const { return FD; }

	QString getName() const;
	QList<QString> getParamNames() const;

	const codestructs::CFGNode getStartNode() const;
	const codestructs::CFGNode getEndNode() const;

private:
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
