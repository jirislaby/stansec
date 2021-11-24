/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDomElement>
#include <QString>
#include <QVector>

#include "XMLLinearizeASTElement.h"

using namespace codestructs;

QVector<QDomElement> XMLLinearizeASTElement::functionCall(const QDomElement &elem)
{
    QVector<QDomElement> result = voidFunctionCall(elem);
#if 0
    if (result != null)
	return result;
    result = assignFunctionCall(elem);
    if (result == null)
	return null;
#else
	assert(0); abort();
#endif
    return tail(result);
}

QVector<QDomElement> XMLLinearizeASTElement::voidFunctionCall(const QDomElement &elem)
{
#if 0
    return elem.getName().equals("functionCall") ?
		new QVector<QDomElement>((List<QDomElement>)elem.elements()) : null;
#else
	assert(0); abort();
#endif
}

QVector<QDomElement> XMLLinearizeASTElement::assignFunctionCall(const QDomElement &elem)
{
#if 0
    if (elem.getName() != "assignExpression")
	return QVector<QDomElement>();
	//return nullptr;
    QList<QDomElement> children = elem.elements();
    if (children[1].getName() != "functionCall")
	return QVector<QDomElement>();
	//return nullptr;

    return cons(children[0], children[1].elements());
#else
	assert(0); abort();
#endif
}

bool XMLLinearizeASTElement::isVoidParam(const QList<QDomElement> &params)
{
	if (params.size() != 1)
	    return false;

	return utils::XMLAlgo::equalElements(params[0], voidParam);
}

QDomElement XMLLinearizeASTElement::createElement(const QString &type, const QString &data)
{
	assert(0); abort();
	//const QDomElement elem = DocumentFactory.getInstance().createElement(type);
	return QDomElement();//elem.addText(data);
}
#if 0
    public static QDomElement functionRet(const QDomElement elem) {
        return (elem.getName().equals("returnStatement") &&
                elem.elements().size() == 1) ?
		    (QDomElement)elem.elements().get(0) : null;
    }

    @SuppressWarnings("unchecked")
    public static QVector<QDomElement> functionDeclaration(const QDomElement elem) {
	QDomElement fnDecl = (QDomElement)elem.selectSingleNode(
		"./declarator[1]");
        if (fnDecl == null)
            return null;
	QDomElement id;
	while ((id = (QDomElement)fnDecl.selectSingleNode("./id")) == null) {
	    fnDecl = (QDomElement)fnDecl.selectSingleNode("./declarator");
	    if (fnDecl == null)
		throw new NullPointerException("wrong functionDeclaration");
	}
	const QVector<QDomElement> result = new QVector<QDomElement>();
        result.add(id);
        int argID = 0;
	const List<QDomElement> params =
		(List<QDomElement>)fnDecl.selectNodes("./functionDecl/*");

	if (isVoidParam(params))
	    return result;

	for (const QDomElement param: params)
            result.add(parseParameterName(param, argID++));
        return result;
    }

    /**
     * Checks whether @params are the single void keyword (i.e. no params)
     *
     * Compares @params to:
     * <parameter>
     *  <declarationSpecifiers>
     *   <typeSpecifier>
     *     <baseType>void</baseType>
     *   </typeSpecifier>
     * 	</declarationSpecifiers>
     * </parameter>
     * and returns true if it matches.
     */
    private static bool isVoidParam(const List<QDomElement> params) {
	if (params.size() != 1)
	    return false;

	return XMLAlgo.equalElements(params.get(0), voidParam);
    }

private:

    private static QDomElement parseParameterName(const QDomElement param,
                                              const int argID) {
	/* K&R style */
	if (param.getName().equals("id"))
	    return param;
	const QDomElement paramElem =
		(QDomElement)param.selectSingleNode("(.//id)[last()]");
        if (paramElem != null)
            return paramElem;
        if (param.selectSingleNode("./varArgs") != null)
            return createElement("id", "$ellipsis");
        return createElement("id", "$arg" + Integer.toString(argID));
    }
#endif
