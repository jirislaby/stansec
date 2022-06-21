/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Expr.h>
#include <clang/AST/Stmt.h>

#include <QList>
#include <QString>

#include "../utils/xmlpatterns/XMLPatternVariablesAssignment.h"
#include "PassingSolver.h"

using namespace codestructs;

#if 0
    public static QString makeArgument(const Element elem) {
	assert elem != null;

	StringBuilder result = new StringBuilder(parseElement(elem));
	for (Element e: (List<Element>)elem.elements())
	    result.append(' ').append(makeArgument(e));
	return result.toString();
    }

    QString parseElement(const Element elem) {
	if (elem.getName() == "id") return elem.getText();
	if (elem.getName() == "member") return elem.getText();
	if (elem.getName() == "intConst") return elem.getText();
	if (elem.getName() == "stringConst") return '"'+elem.getText()+'"';
	if (elem.getName() == "addrExpression") return "&";
	if (elem.getName() == "derefExpression") return "*";
	if (elem.getName() == "dotExpression") return ".";
	if (elem.getName() == "arrowExpression") return ". *";
	if (elem.getName() == "arrayAccess") return "[]";
	if (elem.getName() == "functionCall") return "(" +
						 (elem.elements().size()  - 1) +
							  ")";
	return "";
    }

    QString parseNodeType(const QString type) {
	if (type.equals("member")) return ".";
	if (type.equals("deref")) return "*";
	return "";
    }
#endif

const clang::Expr *
PassingSolver::pass(const clang::Expr *argument,
		    const QList<CallMapping> &callMapping)
{
	bool wasTransformed = false;
	auto result = argument;

	for (const auto &map : callMapping) {
	    const auto paramTransformation = pass(result, map);
	    if (paramTransformation) {
		wasTransformed = true;
		result = paramTransformation;
	    }
	}

	return wasTransformed ? result : nullptr;
}

const clang::Expr *
PassingSolver::pass(const clang::Expr *argument, const CallMapping &callMapping)
{
	const auto &fi = callMapping.first;
	//const auto &se = callMapping.second;

	if (!argument || !fi)
	    return nullptr;
#if 0
	if (argument.contains(fi))
	    return simplify(argument.replace(fi, se));

	if (fi.contains(argument) && fi[0] == '&')
	    return "* " + se;
#else
	assert(0); abort();
#endif

	return nullptr;
}

bool PassingSolver::forEachDecl(const clang::Stmt *stmt,
				const std::function<bool(const clang::Decl *)> &CB)
{
	if (auto DRE = llvm::dyn_cast<const clang::DeclRefExpr>(stmt))
		return CB(DRE->getDecl());

	for (auto ch : stmt->children())
		if (forEachDecl(ch, CB))
			return true;

	return false;
}

const clang::Decl *PassingSolver::getFirstDecl(const clang::Stmt *stmt)
{
	const clang::Decl *retval = nullptr;

	forEachDecl(stmt, [&retval](const clang::Decl *decl) -> bool {
		retval = decl;
		return true;
	});

	return retval;
}

bool PassingSolver::stmtContainsDecl(const clang::Stmt *stmt,
				     const clang::Decl *decl)
{
	if (auto DRE = llvm::dyn_cast<const clang::DeclRefExpr>(stmt))
		return DRE->getDecl() == decl;

	for (auto ch : stmt->children())
		if (stmtContainsDecl(ch, decl))
			return true;

	return false;
}

bool PassingSolver::isSameExpr(const clang::Expr *e1, const clang::Expr *e2)
{
	if (e1 == e2)
		return true;

	e1 = e1->IgnoreParenCasts();
	e2 = e2->IgnoreParenCasts();

	if (e1->getStmtClass() != e2->getStmtClass())
		return false;

#ifdef DEBUG_SAME
	qDebug() << __func__ << e1->getStmtClassName() << "==" <<
		    e1->getStmtClassName();
	e1->dumpColor();
	e2->dumpColor();
#endif

	switch (e1->getStmtClass()) {
	case clang::Stmt::StmtClass::UnaryOperatorClass: {
		auto UO1 = llvm::cast<clang::UnaryOperator>(e1);
		auto UO2 = llvm::cast<clang::UnaryOperator>(e2);
		if (UO1->getOpcode() != UO2->getOpcode())
			return false;
		return isSameExpr(UO1->getSubExpr(), UO2->getSubExpr());
	}
	case clang::Stmt::StmtClass::DeclRefExprClass: {
		const auto *DRE1 = llvm::cast<clang::DeclRefExpr>(e1);
		const auto *DRE2 = llvm::cast<clang::DeclRefExpr>(e2);
		return DRE1->getDecl() == DRE2->getDecl();
	}
	case clang::Stmt::StmtClass::MemberExprClass:
		while (llvm::isa<clang::MemberExpr>(e1) &&
				llvm::isa<clang::MemberExpr>(e2)) {
		    auto ME1 = llvm::cast<clang::MemberExpr>(e1);
		    auto ME2 = llvm::cast<clang::MemberExpr>(e2);
		    if (!clang::declaresSameEntity(ME1->getMemberDecl(),
						   ME2->getMemberDecl()))
			return false;
		    e1 = ME1->getBase()->IgnoreParenImpCasts();
		    e2 = ME2->getBase()->IgnoreParenImpCasts();
		}

		return isSameExpr(e1, e2);
	default:
		break;
	}

#if 0
	if (!clang::Expr::isSameComparisonOperand(e1, e2)) {
		qDebug() << "\tdiff" << e1->getStmtClassName() << e2->getStmtClassName();
		e1->dumpColor();
		e2->dumpColor();
		return false;
	}
#else
	qDebug() << "UNHANDLED";
#endif

	return false;
}
