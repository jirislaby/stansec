/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/Analysis/CFG.h>
#include <clang/AST/Stmt.h>
#include <clang/Basic/SourceLocation.h>

#include "CFGNode.h"

using namespace codestructs;

clang::SourceLocation CFGNode::getBeginLoc() const
{
	if (isValid() && hasStmt())
		return getStmt()->getBeginLoc();
	return clang::SourceLocation();
}

void CFGNode::dumpColor() const
{
	if (!isValid())
		return;
	if (hasStmt())
		getStmt()->dumpColor();
	else
		getBlock()->dump();
}

const clang::Stmt *CFGNode::_getStmt() const
{
	return blk->Elements[blkIndex].getAs<clang::CFGStmt>()->getStmt();
}

QDebug codestructs::operator<<(QDebug d, const CFGNode &item)
{
	if (!item.isValid()) {
		d << "<invalid>";
	} else if (auto stmt = item.getStmt()) {
		d << "S:0x" + QString::number((quintptr)stmt, 16) <<
		     "(B:" + QString::number(item.getBlock()->getBlockID()) +
		     "[" + QString::number(item.getBlockIdx()) + "])";
	} else {
		auto blk = item.getBlock();
		d << "B:" + QString::number(blk->getBlockID());
	}

	return d;
}


