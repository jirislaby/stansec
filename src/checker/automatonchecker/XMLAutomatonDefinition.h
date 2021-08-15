#ifndef XMLAUTOMATONDEFINITION_H
#define XMLAUTOMATONDEFINITION_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QMap>
#include <QString>
#include <QVector>

#include "../../utils/xmlpatterns/XMLPattern.h"

#include "XMLErrorRule.h"
#include "XMLTransitionRule.h"

class QDomElement;

namespace checker {

class XMLAutomatonDefinition final {

public:
    // package-private section

    XMLAutomatonDefinition() = delete;
    explicit XMLAutomatonDefinition(const QDomElement &XMLdefinition)
				       /*throws XMLAutomatonSyntaxErrorException*/;

    QString getAutomatonName() const { return automatonName; }
    QString getAutomatonDescription() const { return automatonDesc; }
    QString getStartSymbol() const { return startSymbol; }
    const QVector<utils::XMLPattern> &getXMLpatterns() const { return XMLpatterns; }

    QList<const XMLTransitionRule *>
    getXMLtransitionRulesForPattern(const utils::XMLPattern *pattern) const {
	return patternTransitionRulesDictionary[pattern];
    }

    QList<const XMLErrorRule *>
    getXMLerrorRulesForPattern(const utils::XMLPattern *pattern) const {
	return patternErrorRulesDictionary[pattern];
    }

    QList<const XMLErrorRule *> getExitErrorRules() const;

private:
    void buildXMLPatterns(const QDomElement &XMLdefinition);
				       //throws XMLAutomatonSyntaxErrorException;

    void buildXMLTransitionRules(const QDomElement &XMLdefinition);
//                                       throws XMLAutomatonSyntaxErrorException;

    void buildXMLErrorRules(const QDomElement &XMLdefinition);
				       //throws XMLAutomatonSyntaxErrorException {

    void buildPatternTransitionRulesDictionary();
    void buildPatternErrorRulesDictionary();

    QString automatonName;
    QString automatonDesc;
    QString startSymbol;

    QVector<utils::XMLPattern> XMLpatterns;
    QVector<XMLTransitionRule> XMLtransitionRules;
    QVector<XMLErrorRule> XMLerrorRules;

    QMap<const utils::XMLPattern *, QList<const XMLTransitionRule *>> patternTransitionRulesDictionary;
    QMap<const utils::XMLPattern *, QList<const XMLErrorRule *>> patternErrorRulesDictionary;
};

}

#endif
