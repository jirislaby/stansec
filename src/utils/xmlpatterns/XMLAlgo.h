#ifndef XMLALGO_H
#define XMLALGO_H

/*
 * Copyright (c) 2008 Marek Trtik
 * Copyright (c) 2008-2009 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QIODevice>
#include <QString>

class QDomDocument;
class QDomElement;
class QDomNode;

namespace utils {

class XMLAlgo {

public:

    virtual ~XMLAlgo() = 0;

    /**
     * Check if two elements are (recursively) equal
     *
     * TODO: remove and use equality tester from dom4j pkg
     *
     * @param e1 first element
     * @param e2 second element
     */
    static bool equalElements(const QDomElement &e1, const QDomElement &e2);

    /**
     * Pretty-print XML node to a stream
     *
     * @param n node to dump
     * @param o stream to dump to
     */
    static void outputXML(const QDomNode &n, QIODevice &o);

    /**
     * Pretty-print XML node to the System.err
     *
     * @param n node to dump
     */
    static void outputXML(QDomNode &n) {
	//outputXML(n, System.err);
    }

    static QDomDocument toDocument(const QString &xml);
    static QDomElement toElement(const QString &xml);
};

}

#endif
