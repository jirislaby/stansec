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

QList<QString>
PassingSolver::makeArgumentList(const utils::XMLPatternVariablesAssignment &xmlAssignment)
{
    QList<QString> res;
#ifdef OLD
    for (auto key : varToElement)
	res.append(makeArgument(varToElement[key]));
#endif

    for (auto &val : xmlAssignment.getVarsNodeMap())
	res.append(makeArgument(val));

    return res;
}


QString PassingSolver::makeArgument(const clang::Stmt *node)
{
#if 0
	if (node.getNodeType() == null)
	    return makeArgument(node.getElement());

	QString result = new StringBuilder(parseNodeType(node.getNodeType()));
	for (CFGNode.Operand op : node.getOperands())
	{
	    result.append(' ').append(makeArgument(op));
	}
	return result.toString();
#else
	assert(0); abort();
#endif
}

QString PassingSolver::makeArgument(const clang::Expr *op)
{
	QString result;

	auto decast = op->IgnoreCasts();

	//qDebug() << __PRETTY_FUNCTION__;
	//decast->dumpColor();

	if (auto declRef = llvm::dyn_cast<clang::DeclRefExpr>(decast)) {
		auto decl = declRef->getDecl();
		if (auto nd = llvm::dyn_cast<clang::NamedDecl>(decl)) {
		    //nd->dumpColor();
		    result = QString::fromStdString(nd->getName().str());
		} else {
		    qWarning() << "no name for";
		    decl->dumpColor();
		}
	} else {
		assert(0);
		abort();
	}
#ifdef OLD
	switch (op.type) {
	case varptr:
	    result.append("& ");

	case function:
	case constant:
	case varval:
	    result.append(op.id.toString());
	    break;

	case nodeval:
	    result.append(makeArgument((CFGNode)op.id));
	    break;
	}
#endif
	return result;
}

llvm::Optional<QString>
PassingSolver::pass(const QString &argument,
		    const QList<CallMapping> &callMapping)
{
	bool wasTransformed = false;
	QString result(argument);

	for (const auto &map : callMapping) {
	    const auto paramTransformation = pass(result, map);
	    if (paramTransformation) {
		wasTransformed = true;
		result = *paramTransformation;
	    }
	}

	return wasTransformed ? result : llvm::Optional<QString>();
}

llvm::Optional<QString>
PassingSolver::pass(QString argument, const CallMapping &callMapping)
{
	const auto &fi = callMapping.first;
	const auto &se = callMapping.second;

	if (argument.isEmpty() || fi.isEmpty())
	    return llvm::Optional<QString>();

	if (argument.contains(fi))
	    return simplify(argument.replace(fi, se));

	if (fi.contains(argument) && fi[0] == '&')
	    return "* " + se;

	return llvm::Optional<QString>();
}

QString PassingSolver::parseRootVariableName(const QString &argument)
{
	for (int i = 0; i < argument.length(); ++i)
	    if (argument[i] == '_' || argument[i].isLetter()) {
		int j = i+1;
		while (j < argument.length() && argument[j] != ' ')
		    j++;
		return argument.mid(i, j - i);
	    }
	return QString();
}

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
