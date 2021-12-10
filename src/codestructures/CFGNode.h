#ifndef CFGNODE_H
#define CFGNODE_H

/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDebug>

namespace clang {
class CFGBlock;
class Stmt;
class SourceLocation;
}

namespace codestructs {

class CFGNode {
public:
	CFGNode() : ptr(nullptr) {}
	explicit CFGNode(const clang::Stmt *stmt) : stmt(stmt) {}
	explicit CFGNode(const clang::CFGBlock *blk) : blk(blk),
		_hasStmt(false) {}

	bool isValid() const { return ptr; }
	bool hasStmt() const { return _hasStmt; }

	const clang::Stmt *getStmt() const {
	    return hasStmt() ? stmt : nullptr;
	}

	const clang::CFGBlock *getBlock() const {
	    return hasStmt() ? nullptr : blk;
	}

	const void *getPointer() const { return ptr; }

	clang::SourceLocation getBeginLoc() const;
	void dumpColor() const;
private:
	union {
	    const clang::CFGBlock *blk;
	    const clang::Stmt *stmt;
	    void *ptr;
	};
	bool _hasStmt = true;
};

QDebug operator<<(QDebug d, const CFGNode &item);

inline bool operator==(const CFGNode &lhs, const CFGNode &rhs)
{
	return lhs.hasStmt() == rhs.hasStmt() &&
			lhs.getPointer() == rhs.getPointer();
}

inline bool operator!=(const CFGNode &lhs, const CFGNode &rhs)
{
	return !(lhs == rhs);
}

inline bool operator<(const CFGNode &lhs, const CFGNode &rhs)
{
	return /*lhs.hasStmt() < rhs.hasStmt() &&*/
			lhs.getPointer() < rhs.getPointer();
}

inline uint qHash(const CFGNode &item, uint seed = 0)
{
	return (::qHash((quintptr)item.getPointer(), seed) << 1) + item.hasStmt();
}

}

#endif // CFGNODE_H
