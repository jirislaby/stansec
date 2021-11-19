/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Decl.h>
#include <clang/Analysis/CFG.h>

#include <QDebug>

#include "CFGHandle.h"

using namespace codestructs;

QList<QString> CFGHandle::getParamNames() const
{
	QList<QString> result;

	for (auto p : FD()->parameters())
		result.append(QString::fromStdString(p->getName().str()));

	llvm::errs() << FD() << "\n";
	qDebug() << result;

	return result;
}

const clang::Stmt *CFGHandle::getFirstStmt(clang::CFGBlock &blk) const
{
	llvm::errs() << __func__ << "\n";
	blk.dump();

	for (auto &el : blk) {
		if (auto CFGopt = el.getAs<clang::CFGStmt>()) {
			return CFGopt->getStmt();
		}
	}

	return nullptr;
}

const clang::Stmt *CFGHandle::getLastStmt(clang::CFGBlock &blk) const
{
	llvm::errs() << __func__ << "\n";
	blk.dump();

	for (auto &el : blk) {
		if (auto CFGopt = el.getAs<clang::CFGStmt>()) {
			return CFGopt->getStmt();
		}
	}

	return nullptr;
}

const clang::Stmt *CFGHandle::getStartNode() const
{
	return getFirstStmt(CFG()->back());
}

const clang::Stmt *CFGHandle::getEndNode() const
{
	return getLastStmt(CFG()->back());
}
