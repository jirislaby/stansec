#ifndef XMLPATTERNVARIABLESASSIGNMENT_H
#define XMLPATTERNVARIABLESASSIGNMENT_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDomElement>
#include <QMap>
#include <QString>

//#include "../CFGNode.h"
//#include "Operand.h"
//#include "PassingSolver.h"

namespace utils {

/*final*/ class XMLPatternVariablesAssignment {

public:
    XMLPatternVariablesAssignment() { }

    QDomElement put(const QString &varName, const QDomElement &XMLelement) {
	return varToElement.insert(varName, XMLelement).value();
    }
#if 0
    CFGNode::Operand put(const QString varName, const CFGNode::Operand op) {
	return varToNode.insert(varName, op).value();
    }
#endif
    //bool isEqualWith(const XMLPatternVariablesAssignment other);

    //QMap<QString, QString> makeArgumentMap();

    void merge(XMLPatternVariablesAssignment other);

    //@Deprecated
    QMap<QString, QDomElement> getVarsMap() const {
	return /*Collections.unmodifiableMap(*/varToElement;
    }

private:
    QMap<QString, QDomElement> varToElement;
    //QMap<QString, CFGNode::Operand> varToNode;
};

}

#endif
