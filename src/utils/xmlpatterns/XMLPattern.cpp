/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Stmt.h>

#include <QDebug>
#include <QDomElement>
#include <QMap>
#include <QPair>
#include <QString>

#include "XMLPattern.h"

#include "../AliasResolver.h"

using namespace utils;

XMLPattern::XMLPattern(const QDomElement XMLelement) :
	patternXMLelement(XMLelement), name(XMLelement.attribute("name")),
	constructive(XMLelement.attribute("constructive", "true") != "false")
{
}

QPair<bool, XMLPatternVariablesAssignment> XMLPattern::matchesNode(const clang::Stmt *node,
								   const AliasResolver &aliasResolver)
{
#if 0
    QDomElement xmlPivot = getPatternXMLelement();
    if (xmlPivot.getName() == "node") {
	return matchesNode(node, getPatternXMLelement(), aliasResolver);
    } else if (node.getElement() != nullptr)
	return matchesXMLElement(node.getElement());
    else
	return qMakePair(false, nullptr);
#else
	auto el = getPatternXMLelement();
	qDebug() << "unimplemented" << __PRETTY_FUNCTION__ << "comparing" <<
		    el.tagName() << el.text() << "to";
	node->dump();
	return qMakePair(false, XMLPatternVariablesAssignment());
	assert(0);
	abort();
#endif
}

#if 0
QPair<bool, XMLPatternVariablesAssignment>
XMLPattern::matchesNode(const CFGNode &node, const QDomElement &xmlPivot,
			const AliasResolver &aliasResolver) const
{
#if 0
    if (node.getNodeType() == null
	    || !node.getNodeType().equals(xmlPivot.attributeValue("type")))
	return Pair.make(false, null);

    XMLPatternVariablesAssignment varsAssignment = new XMLPatternVariablesAssignment();

    Iterator<QDomElement> i = xmlPivot.elementIterator();
    Iterator<CFGNode.Operand> j = node.getOperands().iterator();
    while (i.hasNext() && j.hasNext()) {
	QDomElement elem = i.next();

	if (elem.getName().equals("any"))
	    return Pair.make(true, varsAssignment);

	CFGNode.Operand op = j.next();

	if (elem.getName().equals("ignore"))
	    continue;

	if (elem.getName().equals("var")) {
	    varsAssignment.put(elem.attribute("name").getValue(), op);
	    continue;
	}

	if (op.type == CFGNode.OperandType.nodeval) {
	    if (!elem.getName().equals("node"))
		return Pair.make(false, null);

	    Pair<Boolean, XMLPatternVariablesAssignment> nested
		    = matchesNode((CFGNode)op.id, elem, aliasResolver);
	    if (!nested.getFirst())
		return nested;
	    varsAssignment.merge(nested.getSecond());
	} else {
	    if (!op.type.toString().equals(elem.getName()))
		return Pair.make(false, null);

	    if (!aliasResolver.match(elem.getText(), op.id.toString()))
		return Pair.make(false, null);
	}
    }

    if (i.hasNext() || j.hasNext())
	return Pair.make(false, null);

    return QPair.make(true, varsAssignment);
#else
    assert(0);
    abort();
#endif
}
#endif

QPair<bool, XMLPatternVariablesAssignment>
XMLPattern::matchesXMLElement(const QDomElement &XMLelement) const {
#if 0
    assert XMLelement != null;
    const XMLPatternVariablesAssignment varsAssignment =
	    new XMLPatternVariablesAssignment();
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
