/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Stmt.h>
#include <clang/AST/Expr.h>

#include <QDebug>
#include <QDomElement>
#include <QPair>
#include <QString>

#include "../../codestructures/CFGNode.h"

#include "../AliasResolver.h"

#include "XMLPattern.h"

using namespace utils;

XMLPattern::XMLPattern(const QDomElement XMLelement) :
	patternXMLelement(XMLelement), name(XMLelement.attribute("name")),
	constructive(XMLelement.attribute("constructive", "true") != "false")
{
}

llvm::Optional<XMLPatternVariablesAssignment>
XMLPattern::matchesNode(const codestructs::CFGNode &node,
			const AliasResolver &aliasResolver) const
{
    QDomElement xmlPivot = getPatternXMLelement();
    if (xmlPivot.tagName() == "node")
	return matchesNode(node, xmlPivot, aliasResolver);
#if 0
    else if (node.getElement() != nullptr)
	return matchesXMLElement(node.getElement());
#endif
    else
	return llvm::Optional<XMLPatternVariablesAssignment>();
}

llvm::Optional<XMLPatternVariablesAssignment>
XMLPattern::matchesNode(const codestructs::CFGNode &node,
			const QDomElement &xmlPivot,
			const AliasResolver &aliasResolver) const
{
	if (auto stmt = node.getStmt())
		return matchesNode(stmt, xmlPivot, aliasResolver);

	return llvm::Optional<XMLPatternVariablesAssignment>();
}

llvm::Optional<XMLPatternVariablesAssignment>
XMLPattern::matchesNode(const clang::Stmt *node, const QDomElement &xmlPivot,
			const AliasResolver &aliasResolver) const
{
	const auto type = xmlPivot.attribute("type");
	if (type == "call") {
		if (auto call = llvm::dyn_cast<clang::CallExpr>(node)) {
			return matchesNode(call, xmlPivot, aliasResolver);
		}
	}

	return llvm::Optional<XMLPatternVariablesAssignment>();
}

QDebug operator<<(QDebug d, const QDomElement &dom)
{
	QString s;
	QTextStream ts(&s);
	dom.save(ts, 2);
	d.noquote() << s;
	return d;
}

llvm::Optional<XMLPatternVariablesAssignment>
XMLPattern::matchesNode(const clang::CallExpr *node, const QDomElement &xmlPivot,
			const AliasResolver &aliasResolver) const
{
    //node->dumpColor();
    //qDebug() << __func__ << "comparing ^^^ to\n" << xmlPivot;

    auto funElement = xmlPivot.firstChildElement("function");
    if (funElement.isNull()) {
	    qWarning() << "no function element in pattern at" << xmlPivot.lineNumber();
	    return llvm::Optional<XMLPatternVariablesAssignment>();
    }

    auto callee = llvm::dyn_cast_or_null<clang::FunctionDecl>(node->getCalleeDecl());
    if (!callee) {
	    //qDebug() << __func__ << "callee is not known, skipping";
	    return llvm::Optional<XMLPatternVariablesAssignment>();
    }
    auto calleeName = QString::fromStdString(callee->getName().str());

    //qDebug() << __func__ << "comparing name" << calleeName << "to" << funElement.text();
    if (calleeName != funElement.text())
	    return llvm::Optional<XMLPatternVariablesAssignment>();

    XMLPatternVariablesAssignment varsAssignment;

    auto xmlParams = xmlPivot.firstChildElement("params");
    if (xmlParams.isNull()) {
	    qWarning() << "no function params in pattern at" << xmlPivot.lineNumber();
	    return llvm::Optional<XMLPatternVariablesAssignment>();
    }


    auto i = xmlParams.firstChild();
    auto j = node->arg_begin();
    auto j_end = node->arg_end();
    while (!i.isNull() && j != j_end) {
	auto elem = i.toElement();
	i = i.nextSibling();
	assert(!elem.isNull());
	auto tagName = elem.tagName();

	if (tagName == "any")
		return varsAssignment;

	auto op = *j++;

	if (tagName == "ignore")
	    continue;

	if (tagName == "var") {
	    varsAssignment.put(elem.attribute("name"), op);
	    continue;
	}
	//op->dumpColor();
	//qDebug() << "comparing operand ^^^ to\n" << elem;

#if 0
	if (op.type == CFGNode.OperandType.nodeval) {
	    if (tagName != "node")
		return llvm::Optional<XMLPatternVariablesAssignment>();

	    auto nested = matchesNode((CFGNode)op.id, elem, aliasResolver);
	    if (!nested)
		return nested;
	    varsAssignment.merge(*nested);
	} else {
	    if (op.type.toString() != tagName)
		return llvm::Optional<XMLPatternVariablesAssignment>();

	    if (!aliasResolver.match(elem.getText(), op.id.toString()))
		return llvm::Optional<XMLPatternVariablesAssignment>();
	}
#else
	assert(0); abort();
#endif
    }

    /*qDebug() << "i" << i.isNull() << "j" << (j == j_end);
    if (!i.isNull())
	    qDebug() << "i tag" << i.toElement().tagName();*/

    if (!i.isNull() || j != j_end)
	return llvm::Optional<XMLPatternVariablesAssignment>();

    //qDebug() << "varsAssignment" << varsAssignment;

    return varsAssignment;
}

llvm::Optional<XMLPatternVariablesAssignment>
XMLPattern::matchesXMLElement(const QDomElement &XMLelement) const {
#if 0
    //assert XMLelement != null;
    const XMLPatternVariablesAssignment varsAssignment;
    return new Pair<Boolean,XMLPatternVariablesAssignment>(
		matchingElements(getPatternXMLelement(),XMLelement,
				 varsAssignment),
		varsAssignment);
#else
	assert(0);
	abort();
#endif
}

bool XMLPattern::matchingElements(const QDomElement &XMLpivot,
				  const QDomElement &XMLelement,
				  const XMLPatternVariablesAssignment &varsAssignment)
{
#if 0
    if (XMLpivot.getName().equals("nested")) {
	const QString elementName = XMLelement.getName();
	for (const Iterator<Attribute> j = XMLpivot.attributeIterator();
	     j.hasNext(); )
	    if (elementName.equals(j.next().getValue()))
		return false;
	return onNested(XMLpivot,XMLelement,varsAssignment);
    }
    if (XMLpivot.getName().equals("ignore"))
	return true;
    if (XMLpivot.getName().equals("var")) {
	if (!satisfyVarConstraints(XMLelement.getName(),
				   XMLpivot.attribute("match"),
				   XMLpivot.attribute("except")))
	    return false;
	varsAssignment.put(XMLpivot.attribute("name").getValue(),
			   XMLelement);
	return true;
    }

    if (!XMLpivot.getName().equals(XMLelement.getName()))
	return false;
    if (!matchingAttributes(XMLpivot.attributes(),XMLelement))
	return false;
    if (XMLpivot.isTextOnly() != XMLelement.isTextOnly())
	return false;
    if (XMLpivot.isTextOnly() &&
	    !XMLpivot.getText().equals(XMLelement.getText()))
	return false;

    const Iterator<QDomElement> i = XMLpivot.elementIterator();
    const Iterator<QDomElement> j = XMLelement.elementIterator();
    while (i.hasNext() && j.hasNext()) {
	const QDomElement pivotNext = i.next();
	if (pivotNext.getName().equals("any"))
	    return true;
	if (!matchingElements(pivotNext, j.next(), varsAssignment))
	    return false;
    }
    if (i.hasNext() || j.hasNext())
	return false;

#else
    assert(0);
    abort();
#endif
    return true;
}

bool XMLPattern::onNested(const QDomElement &XMLpivot,
			  const QDomElement &XMLelement,
			  const XMLPatternVariablesAssignment &varsAssignment)
{
#if 0
    if (matchingElements((QDomElement)XMLpivot.elementIterator().next(),
			 XMLelement, varsAssignment))
	return true;

    for (const Iterator<QDomElement> j = XMLelement.elementIterator();
	 j.hasNext(); )
	if (matchingElements(XMLpivot, j.next(), varsAssignment))
	    return true;
#else
    assert(0);
    abort();
#endif
    return false;
}

bool XMLPattern::matchingAttributes(const QList<QDomAttr> &pivotATTRs,
				    const QDomElement &XMLelement)
{
#if 0
    for (const Attribute pivotAttr: pivotATTRs) {
	const QString elem = XMLelement.attributeValue(pivotAttr.getName());
	if (elem == null || !matchingAttribute(pivotAttr.getValue(), elem))
	    return false;
    }
#else
    assert(0);
    abort();
#endif
    return true;
}

bool XMLPattern::matchingAttribute(const QString &pivotAttr,
				   const QString &elemAttr)
{
#if 0
    const QPair<bool, QString[]> parsedData = splitAttrSymbols(pivotAttr);
    return retvalWhenItemInSet(!parsedData.getFirst(),elemAttr,
			       parsedData.getSecond());
#else
    assert(0);
    abort();
#endif
}

bool XMLPattern::satisfyVarConstraints(const QString &elemName,
				       const QDomAttr &matchAttr,
				       const QDomAttr &exceptAttr)
{
#if 0
    return (matchAttr != null) ?
		retvalWhenItemInSet(true,elemName,
				    splitAttrSymbols(matchAttr.getValue()).getSecond()) :
		(exceptAttr != null) ?
		    retvalWhenItemInSet(false,elemName,
					splitAttrSymbols(exceptAttr.getValue()).getSecond()):
		    true;
#else
    assert(0);
    abort();
#endif
}

bool XMLPattern::retvalWhenItemInSet(const bool &retval, const QString &item,
				     const QVector<QString> &set)
{
    for (const auto &setItem : set)
	if (setItem == item)
	    return retval;

    return !retval;
}

QPair<bool, QVector<QString>> XMLPattern::splitAttrSymbols(QString attrString)
{
#if 0
    attrString = attrString.replace(" ","")
	    .replace("\t","");
    return (attrString.charAt(0) != '-' && attrString.charAt(0) != '{') ?
		Pair.make(false,attrString.split(" ")) :
		Pair.make(attrString.charAt(0) == '-' ? true : false,
			  attrString.substring(attrString.indexOf('{') + 1,
					       attrString.lastIndexOf('}'))
			  .split("\\}\\{"));
#else
	assert(0);
	abort();
#endif
}
