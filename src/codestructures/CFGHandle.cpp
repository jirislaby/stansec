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
#include "CFGNode.h"

using namespace codestructs;

QString CFGHandle::getName() const
{
	return QString::fromStdString(getFD()->getName().str());
}

QList<QString> CFGHandle::getParamNames() const
{
	QList<QString> result;

	for (auto p : getFD()->parameters())
		result.append(QString::fromStdString(p->getName().str()));

	//llvm::errs() << FD() << "\n";
	//qDebug() << result;

	return result;
}

const codestructs::CFGNode CFGHandle::getStartNode() const
{
	return codestructs::CFGNode(&getCFG()->getEntry());
}

const codestructs::CFGNode CFGHandle::getEndNode() const
{
	return codestructs::CFGNode(&getCFG()->getExit());
}
