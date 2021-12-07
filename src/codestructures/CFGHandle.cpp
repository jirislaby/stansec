/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <llvm/ADT/DepthFirstIterator.h>
#include <llvm/ADT/PostOrderIterator.h>
#include <clang/AST/Decl.h>
#include <clang/Analysis/CFG.h>

#include <QDebug>

#include "CFGHandle.h"

using namespace codestructs;

QString CFGHandle::getName() const
{
	return QString::fromStdString(FD()->getName().str());
}

QList<QString> CFGHandle::getParamNames() const
{
	QList<QString> result;

	for (auto p : FD()->parameters())
		result.append(QString::fromStdString(p->getName().str()));

	//llvm::errs() << FD() << "\n";
	//qDebug() << result;

	return result;
}

const clang::Stmt *CFGHandle::getFirstStmt(clang::CFGBlock &blk) const
{
	for (auto &el : blk)
		if (auto CFGopt = el.getAs<clang::CFGStmt>())
			return CFGopt->getStmt();

	return nullptr;
}

const clang::Stmt *CFGHandle::getLastStmt(clang::CFGBlock &blk) const
{
	for (auto &el : blk)
		if (auto CFGopt = el.getAs<clang::CFGStmt>())
			return CFGopt->getStmt();

	return nullptr;
}

const clang::Stmt *CFGHandle::getStartNode() const
{
	for (auto blk : llvm::depth_first(CFG()))
		if (auto ret = getFirstStmt(*blk))
			return ret;

	qDebug() << "completely empty CFG";
	CFG()->dump(FD()->getLangOpts(), true);
	return nullptr;
}

const clang::Stmt *CFGHandle::getEndNode() const
{
	for (auto blk : llvm::post_order(CFG()))
		if (auto ret = getFirstStmt(*blk))
			return ret;

	qDebug() << "completely empty CFG";
	CFG()->dump(FD()->getLangOpts(), true);
	return nullptr;
}
