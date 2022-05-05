/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Expr.h>

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
