/*
 * Copyright (c) 2008 Marek Trtik
 * Copyright (c) 2008-2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDomDocument>
#include <QDomNode>
#include <QString>
#include <QTextStream>

#include "XMLAlgo.h"

using namespace utils;

bool XMLAlgo::equalElements(const QDomElement &e1, const QDomElement &e2)
{
    if (e1.tagName() != e2.tagName())
	return false;
    if (e1.text() != e2.text())
	return false;

    const auto attrs = e1.attributes();
    for (int a = 0; a < attrs.length(); a++) {
	const auto attr = attrs.item(a).toAttr();
	const auto name = attr.name();
	if (name != "bl" && name != "bc" && attr.value() != e2.attribute(name))
	    return false;
    }

    auto n1 = e1.firstChild();
    auto n2 = e2.firstChild();
    for (; !n1.isNull() && !n2.isNull();
	n1 = n1.nextSibling(), n2 = n2.nextSibling()) {
	if (!equalElements(n1.toElement(), n2.toElement()))
	    return false;
    }

    if (!n1.isNull() || !n2.isNull())
	return false;

    return true;
}

/**
 * Pretty-print XML node to a stream
 *
 * @param n node to dump
 * @param o stream to dump to
 */
void XMLAlgo::outputXML(const QDomNode &n, QIODevice &o)
{
	QTextStream stream(&o);
	stream << n;
}

QDomDocument XMLAlgo::toDocument(const QString &xml)
{
	QDomDocument doc("doc");
	doc.setContent(xml);
	return doc;
}

QDomElement XMLAlgo::toElement(const QString &xml)
{
	QDomDocument doc("temp");
	doc.setContent(xml);
	return doc.documentElement();
}
