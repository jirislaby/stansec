/*
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QDomElement>
#include <QList>
#include <QMap>
#include <QString>

#include "XMLAutomatonDefinition.h"

using namespace checker;

//import org.dom4j.Element;

XMLAutomatonDefinition::XMLAutomatonDefinition(const QDomElement &XMLdefinition)
{
    auto desc = XMLdefinition.firstChildElement("description");

    automatonName = desc.attribute("name").simplified();
    automatonDesc = desc.attribute("desc").simplified();

    auto start = XMLdefinition.firstChildElement("start");
    startSymbol = start.attribute("state");

    qDebug() << "name" << automatonName << "desc" << automatonDesc.left(100) <<
		"start" << startSymbol;

    buildXMLPatterns(XMLdefinition);
    buildXMLTransitionRules(XMLdefinition);
    buildXMLErrorRules(XMLdefinition);

    buildPatternTransitionRulesDictionary();
    buildPatternErrorRulesDictionary();
}

QList<const XMLErrorRule *> XMLAutomatonDefinition::getExitErrorRules() const
{
    QList<const XMLErrorRule *> result;

    for (auto &rule : XMLerrorRules)
	if (rule.isExitRule())
	    result.append(&rule);

    return result;
}

void XMLAutomatonDefinition::buildXMLPatterns(const QDomElement &XMLdefinition)
{
    const auto patternNodes = XMLdefinition.elementsByTagName("pattern");

    if (patternNodes.isEmpty()) {
	    qDebug() << "XML document" << XMLdefinition.tagName() <<
			"error: No pattern XML node was found.";
	    return;
	/*throw new XMLAutomatonSyntaxErrorException(
		"XML document '" + XMLdefinition.getName() +
		"' error: No pattern XML node was found.");*/
    }

    for (int a = 0; a < patternNodes.length(); a++) {
	auto node = patternNodes.item(a);
	XMLpatterns.append(utils::XMLPattern(node.toElement()));
    }
}

void XMLAutomatonDefinition::buildXMLTransitionRules(const QDomElement &XMLdefinition)
{
    const auto patternNodes = XMLdefinition.elementsByTagName("transition");
    if (patternNodes.isEmpty()) {
	    qDebug() << "XML document" << XMLdefinition.tagName() <<
			"error: No transition rule XML node was found.";
	    return;
	/*throw new XMLAutomatonSyntaxErrorException(
		"XML document '" + XMLdefinition.getName() +
		"' error: No transition rule XML node was found.");*/
    }
    for (int a = 0; a < patternNodes.length(); a++) {
	auto node = patternNodes.item(a).toElement();
	assert(!node.isNull());
	XMLtransitionRules.append(XMLTransitionRule(node));
    }
}

void XMLAutomatonDefinition::buildXMLErrorRules(const QDomElement &XMLdefinition)
{
    const auto patternNodes = XMLdefinition.elementsByTagName("error");
    if (patternNodes.isEmpty()) {
	    qDebug() << "XML document" << XMLdefinition.tagName() <<
			"error: No error rule XML node was found.";
	    return;
	/*throw new XMLAutomatonSyntaxErrorException(
		"XML document '" + XMLdefinition.getName() +
		"' error: No error rule XML node was found.");*/
    }
    for (int a = 0; a < patternNodes.length(); a++) {
	auto node = patternNodes.item(a);
	XMLerrorRules.append(XMLErrorRule(node.toElement()));
    }
}

void XMLAutomatonDefinition::buildPatternTransitionRulesDictionary()
{
    for (const auto &patt : XMLpatterns) {
	QList<const XMLTransitionRule *> patternTransitions;
	for (const auto &rule : XMLtransitionRules)
	    if (rule.getPatternName() == patt.getName())
		patternTransitions.append(&rule);
	patternTransitionRulesDictionary.insert(&patt, patternTransitions);
    }
}

void XMLAutomatonDefinition::buildPatternErrorRulesDictionary()
{
    for (const auto &patt : XMLpatterns) {
	QList<const XMLErrorRule *> patternErrors;
	for (const auto &rule : XMLerrorRules)
	    if (rule.getPatternName() == patt.getName())
		patternErrors.append(&rule);
	patternErrorRulesDictionary.insert(&patt, patternErrors);
    }
}
