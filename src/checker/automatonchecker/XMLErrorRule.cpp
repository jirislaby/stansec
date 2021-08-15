/*
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <QDomElement>
#include <QList>
#include <QPair>
#include <QString>
#include <QVector>

#include "AutomatonState.h"
#include "XMLErrorRule.h"
#include "XMLRuleStringParser.h"

using namespace checker;

XMLErrorRule::XMLErrorRule(const QDomElement &XMLelement) :
    description(XMLelement.attribute("desc").simplified()),
    errorLevel(XMLelement.attribute("level").toInt()),
    entryMessage(XMLelement.attribute("entry").simplified()),
    beginMessage(XMLelement.attribute("begin").simplified()),
    propagMessage(XMLelement.attribute("propag").simplified()),
    endMessage(XMLelement.attribute("end").simplified())
{
    const auto byString = XMLelement.attribute("by");
    const auto bySymbol = byString.isEmpty() ?
			    std::make_tuple(QString(), QStringList(), XMLRuleStringParser::Plus) :
			    XMLRuleStringParser::parseOneSymbolRuleString(byString);
    if (!bySymbol)
	    return;

    if (!byString.isEmpty() && !checkVars(1, -1, *bySymbol)) {
	    qWarning() << "invalid number of variables" << byString;
	    return;
    }

    const QString locationVarName = byString.isEmpty() ? "*" : std::get<1>(*bySymbol).first();

    patternName = std::get<0>(*bySymbol);

    const auto fromString = XMLelement.attribute("from");
    const auto fromList = XMLRuleStringParser::parseRuleString(fromString);
    if (!fromList)
	    return;
    if (!checkList(*fromList)) {
	    qWarning() << "Invalid number of symbols in rule string. Minimum is 1." <<
			  fromString;
	    return;
    }
    if (!checkVars(1, -1, *fromList)) {
	    qWarning() << "invalid number of variables" << fromString;
	    return;
    }

    excludedMatchFlags = buildMatchFlags(*fromList, XMLRuleStringParser::Minus,
					 locationVarName);
    includedMatchFlags = buildMatchFlags(*fromList, XMLRuleStringParser::Plus,
					 locationVarName);
}

QString XMLErrorRule::matchFlagstoString(const MatchFlags &mf,
					 const QChar &prefix) const
{
    if (mf.isEmpty())
	    return QString();

    QString result(' ');
    result.append(prefix);
    for (auto &m : mf) {
	    result.append(m.first).append('[');
	for (auto &f : m.second)
		result.append(f ? 'T' : 'F');
	result.append(']');
    }
    return result;
}

QString XMLErrorRule::toString() const
{
    QString result;
    result.append(isExitRule() ? "EXIT" : getPatternName());
    result.append(matchFlagstoString(getExcludedMatchFlags(), '-'));
    result.append(matchFlagstoString(getIncludedMatchFlags(), '+'));
    return result;
}

bool XMLErrorRule::checkExcludedStates(const QSet<AutomatonState> &statesCollection,
				       const SimpleAutomatonID &simpleID) const
{
    for (const AutomatonState &state : statesCollection)
	for (const auto &flag : getExcludedMatchFlags())
	    if (stateMatch(state, flag.first, flag.second, simpleID))
		return false;
    return true;
}

bool XMLErrorRule::checkIncludedStates(const QSet<AutomatonState> &statesCollection,
				       const SimpleAutomatonID &simpleID) const
{
    const auto &flags = getIncludedMatchFlags();
    const int numIncluded = flags.size();

    QVector<bool> matchingFlags(numIncluded);

    for (auto state : statesCollection) {
	//            if (isExitRule() && state.getContext().size() > 1)
	//                continue;
	for (int i = 0; i < numIncluded; ++i)
	    if (stateMatch(state, flags[i].first, flags[i].second, simpleID)) {
		matchingFlags[i] = true;
		break;
	    }
    }

    return !matchingFlags.contains(false);
}

bool XMLErrorRule::stateMatch(const AutomatonState &state,
			      const QString &symbol, const QVector<bool> &flags,
			      const SimpleAutomatonID &simpleID) {
	const auto &composedID = state.getAutomatonID();
	const auto &simpleIDs = composedID.getSimpleAutomataIDs();

	if (state.getSymbol() != symbol || simpleIDs.size() != flags.size())
	    return false;

	for (int i = 0; i < flags.size(); ++i) {
	    if (simpleIDs[i].isGlobal() != simpleID.isGlobal())
		return false;
	    if ((flags[i] && simpleIDs[i] != simpleID) ||
		    (!flags[i] && simpleIDs[i] == simpleID))
		return false;
	}

	return true;
}

XMLErrorRule::MatchFlags
XMLErrorRule::buildMatchFlags(const QList<XMLRuleStringParser::XMLRule> &symbols,
			      const XMLRuleStringParser::Mode &mode,
			      const QString &locationVarName)
{
	MatchFlags result;

	for (const auto &symbol : symbols) {
	    if (std::get<2>(symbol) != mode)
		    continue;

	    const auto &vars = std::get<1>(symbol);
	    QVector<bool> flags;
	    flags.reserve(vars.size());

	    for (const auto &var : vars)
		flags.append(var == locationVarName);

	    result.append(qMakePair(std::get<0>(symbol), flags));
	}

	return result;
}

bool XMLErrorRule::checkList(const QList<XMLRuleStringParser::XMLRule> &list)
{
	return !list.isEmpty();
}

bool XMLErrorRule::checkVars(const int minVars, const int maxVars,
			     const QList<XMLRuleStringParser::XMLRule> &symbols)
{
	for (const auto &symbol : symbols)
		if (!checkVars(minVars, maxVars, symbol))
			return false;
	return true;
}

bool XMLErrorRule::checkVars(const int minVars, const int maxVars,
			     const XMLRuleStringParser::XMLRule &symbol)
{
	auto vars = std::get<1>(symbol);

	if ((minVars >= 0 && vars.size() < minVars) ||
		(maxVars >= 0 && vars.size() > maxVars) )
	    return false;

	return true;
}
