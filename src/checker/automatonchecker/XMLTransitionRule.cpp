/*
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <QDomElement>
#include <QList>
#include <QString>
#include <QStringList>

#include "AutomatonState.h"
#include "AutomatonStateContextAlgo.h"
#include "XMLRuleStringParser.h"
#include "XMLTransitionRule.h"

using namespace checker;

XMLTransitionRule::XMLTransitionRule(const QDomElement &XMLtransitionElement)
{
    const auto &fromSymbol = XMLRuleStringParser::parseOneSymbolRuleString(
			    XMLtransitionElement.attribute("from"));

    if (!fromSymbol)
	    return;

    const auto &fromVars = std::get<1>(*fromSymbol);

    if (!checkMode(std::get<2>(*fromSymbol)) ||
		    !checkVars(1, -1, fromVars.size()))
	    return;
    inSymbol = std::get<0>(*fromSymbol);

    const auto toText = XMLtransitionElement.attribute("to");
    const auto &toSymbol = toText.isEmpty() ?
			    std::make_tuple(QString(), QStringList(), XMLRuleStringParser::Plus) :
			    XMLRuleStringParser::parseOneSymbolRuleString(toText);

    if (!toSymbol)
	    return;

    const auto &toVars = std::get<1>(*toSymbol);

    if (!checkMode(std::get<2>(*toSymbol)) ||
		    (!toText.isEmpty() && !checkVars(1, -1, toVars.size())))
	    return;
    outSymbol = std::get<0>(*toSymbol);

    const auto &bySymbol = XMLRuleStringParser::parseOneSymbolRuleString(
			    XMLtransitionElement.attribute("by"));

    if (!bySymbol)
	    return;

    const auto &byVars = std::get<1>(*bySymbol);

    assert(byVars.size() < 2);
    if (!checkMode(std::get<2>(*bySymbol)) ||
		!checkVars(1, 1, byVars.size()))
	    return;

    matchFlags = buildMatchFlags(fromVars, byVars.first());
    matchOutIndices = buildMatchOutIndices(fromVars,
					   toVars,
					   byVars.first());
    patternName = std::get<0>(*bySymbol);
    //qDebug() << "=== END1" << __func__ << "from" << fromVars << "byvars" << byVars;
    //qDebug() << "=== END2" << __func__ << inSymbol << patternName << outSymbol << matchFlags;
}

llvm::Optional<AutomatonState>
XMLTransitionRule::transformAutomatonState(const AutomatonState &state,
					   const SimpleAutomatonID &simpleID) const
{
    if (state.getSymbol() == getInSymbol() &&
		    isThisRuleApplicable(state.getAutomatonID(), simpleID))
	return buildResultState(state, simpleID);

    return llvm::Optional<AutomatonState>();
}

QString XMLTransitionRule::toString() const {
	QString result(getInSymbol());
	result.append('[');
	for (auto f : getMatchFlags())
		result.append(f ? 'T' : 'F');
	result.append(']');
	QStringList out;
	for (auto i : getMatchOutIndices())
		out << QString::number(i);
	result.append(" -").append(getPatternName()).append("-> ").
			append(getOutSymbol()).
			append('[').append(out.join(',')).append(']');
	return result;
}

bool XMLTransitionRule::isThisRuleApplicable(const ComposedAutomatonID &composedID,
					     const SimpleAutomatonID &simpleID) const
{
	auto &simpleIDs = composedID.getSimpleAutomataIDs();
	auto &flags = getMatchFlags();

	if (simpleIDs.size() != flags.size())
		return false;

    for (int i = 0; i < simpleIDs.size(); ++i) {
	if ((flags[i] && simpleIDs[i] != simpleID) ||
		(!flags[i] && simpleIDs[i] == simpleID))
	    return false;
    }

    return true;
}

llvm::Optional<AutomatonState>
XMLTransitionRule::buildResultState(const AutomatonState &state,
				    const SimpleAutomatonID &simpleID) const
{
    if (getOutSymbol().isEmpty())
	return llvm::Optional<AutomatonState>();

    const auto &inAutomatonID = state.getAutomatonID();
    const auto &simpleIDs = inAutomatonID.getSimpleAutomataIDs();
    const auto &indices = getMatchOutIndices();
    QList<SimpleAutomatonID> outAutomatonID;

    for (const auto &i : indices)
	outAutomatonID.append(i == -1 ? simpleID : simpleIDs[i]);

    auto context = state.getContext();
    context.pop();
    context.push(AutomatonStateContextItem(state.getCFGNode(),
					   ComposedAutomatonID(outAutomatonID)));
    return AutomatonState(getOutSymbol(), context);
}

QList<bool> XMLTransitionRule::buildMatchFlags(const QStringList &automataIDs,
						 const QString &automatonID)
{
    QList<bool> matchFlags;
    matchFlags.reserve(automataIDs.size());

    for (const auto &id : automataIDs)
	matchFlags.append(id == automatonID);

    return matchFlags;
}

QList<int> XMLTransitionRule::buildMatchOutIndices(const QStringList &fromAutomataIDs,
						     const QStringList &toAutomataIDs,
						     const QString &automatonID)
{
    QList<int> matchIndices;
    matchIndices.reserve(toAutomataIDs.size());

    for (const auto &id : toAutomataIDs)
	matchIndices.append(id == automatonID ? -1 :
		  findAutomatonIDindex(fromAutomataIDs, id));

    return matchIndices;
}

int XMLTransitionRule::findAutomatonIDindex(const QStringList &automataIDs,
					    const QString &searchedID)
{
    const int index = automataIDs.indexOf(searchedID);
    if (index != -1)
	return index;

    qWarning() << "Variable" << searchedID <<
		  "in attribute 'to' cannot be found in 'from' attribute "
		  "of the transition [possibilities are: " << automataIDs;
#ifdef EXC
    throw new XMLAutomatonSyntaxErrorException("Variable '" + searchedID +
					       "' in attribute 'to' cannot be found in 'from' attribute " +
					       "of the transition [possibilities are: " + automataIDs);
#endif
    return -1;
}

bool XMLTransitionRule::checkMode(XMLRuleStringParser::Mode mode)
{
    if (mode != XMLRuleStringParser::Plus) {
	    qWarning() << "Invalid mode of symbol. "
			  "Mode can only be nothing or symbol '+'.";
	    return false;
    }
#ifdef EXC
	throw new XMLAutomatonSyntaxErrorException(
		"Invalid mode of symbol. " +
		"Mode can only be nothing or symbol '+'.");
#endif
    return true;
}

bool XMLTransitionRule::checkVars(const int minVars, const int maxVars,
				  const int numVars)
{
    if ((minVars >= 0 && numVars < minVars) ||
		    (maxVars >= 0 && numVars > maxVars)) {
	    qWarning() << "Invalid number of variables.";
	    return false;
    }
#ifdef EXC
	throw new XMLAutomatonSyntaxErrorException(
		"Invalid number of variables.");
#endif
    return true;
}
