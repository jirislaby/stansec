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
	explicit CFGNode(const clang::CFGBlock *blk,
		int blkIndex = -1) : blk(blk), blkIndex(blkIndex) {}

	const clang::CFGBlock *getBlock() const { return blk; }
	int getBlockIdx() const { return blkIndex; }

	bool isValid() const { return ptr; }
	bool hasStmt() const { return blkIndex != -1; }

	const clang::Stmt *getStmt() const {
	    return hasStmt() ? _getStmt() : nullptr;
	}

	const void *getPointer() const { return ptr; }

	clang::SourceLocation getBeginLoc() const;
	void dumpColor() const;
private:
	const clang::Stmt *_getStmt() const;

	union {
	    const clang::CFGBlock *blk;
	    void *ptr;
	};
	int blkIndex = -1;
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
