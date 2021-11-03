#ifndef XMLPATTERN_H
#define XMLPATTERN_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <QTextStream>

#include <QDomElement>
#include <QMap>
#include <QPair>
//#include <QRegularExpression>
#include <QString>
#include <QVector>

//#include "XMLAlgo.h"
#include "XMLPatternVariablesAssignment.h"

namespace clang {
class Stmt;
}

namespace utils {

class AliasResolver;

class XMLPattern {

public:
    explicit XMLPattern(const QDomElement XMLelement);
#ifdef NEEDED
    XMLPattern(const QString xml) : XMLPattern(XMLAlgo::toElement(xml)) { }

    XMLPattern(const QString patternName, const QString xml) :
	    XMLPattern(XMLAlgo::toElement("<pattern name=\"" + patternName + "\">" +
					  xml + "</pattern>")) { }
#endif
#if 0
    bool equals(Object obj) {
        return (obj == null || getClass() != obj.getClass()) ?
                    false : isEqualWith((XMLPattern)obj);
    }

    bool isEqualWith(XMLPattern other) {
        return isConstructive() == other.isConstructive() &&
	       getName() == other.getName() &&
	       getPatternXMLelement() == other.getPatternXMLelement();
    }
#endif
    QString getName() const {
        return name;
    }

    bool isConstructive() const {
        return constructive;
    }

    QPair<bool, XMLPatternVariablesAssignment>
    matchesNode(const clang::Stmt *node,
		const AliasResolver &aliasResolver);

    QPair<bool, XMLPatternVariablesAssignment>
    matchesXMLElement(const QDomElement &XMLelement) const;

    QDomElement getPatternXMLelement() const {
	    return patternXMLelement;
    }

private:
#if 0
    QPair<bool,XMLPatternVariablesAssignment>
    matchesNode(const CFGNode &node, const QDomElement &xmlPivot,
		const AliasResolver &aliasResolver) const;
#endif
    static bool matchingElements(const QDomElement &XMLpivot,
				 const QDomElement &XMLelement,
				 const XMLPatternVariablesAssignment &varsAssignment);

    static bool onNested(const QDomElement &XMLpivot,
			 const QDomElement &XMLelement,
			 const XMLPatternVariablesAssignment &varsAssignment);

    static bool matchingAttributes(const QList<QDomAttr> &pivotATTRs,
				   const QDomElement &XMLelement);

    static bool matchingAttribute(const QString &pivotAttr,
				  const QString &elemAttr);

    static bool satisfyVarConstraints(const QString &elemName,
				      const QDomAttr &matchAttr,
				      const QDomAttr &exceptAttr);

    static bool retvalWhenItemInSet(const bool &retval,
				    const QString &item,
				    const QVector<QString> &set);

    static QPair<bool, QVector<QString>> splitAttrSymbols(QString attrString);

    QDomElement patternXMLelement;
    QString name;
    //const QMap<QString, QRegularExpression> compiledRegexes;
    bool constructive;
};

inline bool operator<(const QDomElement &lhs, const QDomElement &rhs)
{
	QString l, r;
	QTextStream s(&l);
	s << lhs;
	s.setString(&r);
	s << rhs;
	return l < r;
}

inline bool operator<(const XMLPattern &lhs, const XMLPattern &rhs)
{
	return lhs.getName() < rhs.getName() &&
			lhs.getPatternXMLelement() < rhs.getPatternXMLelement() &&
			lhs.isConstructive() < rhs.isConstructive();
}

}

#endif
