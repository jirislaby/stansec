#ifndef XMLPATTERNVARIABLESASSIGNMENT_H
#define XMLPATTERNVARIABLESASSIGNMENT_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QDomElement>
#include <QMap>
#include <QString>

namespace clang {
class Expr;
}

namespace utils {

class XMLPatternVariablesAssignment final {
public:
    using VarToNode = QMap<QString, const clang::Expr *>;

    XMLPatternVariablesAssignment() { }
#ifdef OLD
    void put(const QString &varName, const QDomElement &XMLelement) {
	varToElement.insert(varName, XMLelement);
    }
#endif
    void put(const QString &varName, const clang::Expr *op) {
	varToNode.insert(varName, op);
    }
#if 0
    CFGNode::Operand put(const QString varName, const CFGNode::Operand op) {
	return varToNode.insert(varName, op).value();
    }
#endif
    //bool isEqualWith(const XMLPatternVariablesAssignment other);

    void merge(const XMLPatternVariablesAssignment &other) {
#if OLD
	varToElement.insert(other.varToElement);
#endif
	varToNode.insert(other.varToNode);
    }

#ifdef OLD
    QT_DEPRECATED
    const QMap<QString, QDomElement> getVarsMap() const {
	return varToElement;
    }
#endif
    const VarToNode &getVarsNodeMap() const { return varToNode; }

private:
    //QMap<QString, QDomElement> varToElement;
    VarToNode varToNode;
};

inline QDebug operator<<(QDebug d, const XMLPatternVariablesAssignment &xml)
{
	d << xml.getVarsNodeMap();
	return d;
}

}

#endif
