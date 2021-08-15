#ifndef XMLERRORRULE_H
#define XMLERRORRULE_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QChar>
#include <QList>
#include <QPair>
#include <QSet>
#include <QString>
#include <QVector>

#include "XMLRuleStringParser.h"

class QDomElement;

namespace checker {

class AutomatonState;
class SimpleAutomatonID;

class XMLErrorRule {
    // package-private section
public:
    XMLErrorRule() = delete;
    explicit XMLErrorRule(const QDomElement &XMLelement);
	//throws XMLAutomatonSyntaxErrorException {

    bool checkForError(const QSet<AutomatonState> &statesCollection,
		       const SimpleAutomatonID &simpleID) const {
	return checkExcludedStates(statesCollection, simpleID) &&
		checkIncludedStates(statesCollection, simpleID);
    }

    int getErrorLevel() const { return errorLevel; }

    QString getErrorDescription() const { return description; }
    QString getErrorEntryMessage() const { return entryMessage; }
    QString getErrorBeginMessage() const { return beginMessage; }
    QString getErrorPropagMessage() const { return propagMessage; }
    QString getErrorEndMessage() const { return endMessage; }
    QString getPatternName() const { return patternName; }

    bool isExitRule() const { return getPatternName().isEmpty(); }

    QString toString() const;

private:
    using MatchFlags = QVector<QPair<QString, QVector<bool> > >;

    bool checkExcludedStates(const QSet<AutomatonState> &statesCollection,
			     const SimpleAutomatonID &simpleID) const;

    bool checkIncludedStates(const QSet<AutomatonState> &statesCollection,
			     const SimpleAutomatonID &simpleID) const;

    static bool stateMatch(const AutomatonState &state,
			   const QString &symbol, const QVector<bool> &flags,
			   const SimpleAutomatonID &simpleID);

    static MatchFlags
    buildMatchFlags(const QList<XMLRuleStringParser::XMLRule> &symbols,
		    const XMLRuleStringParser::Mode &mode,
		    const QString &locationVarName);

    static bool checkList(const QList<XMLRuleStringParser::XMLRule> &list);
				       //throws XMLAutomatonSyntaxErrorException;

    static bool checkVars(const int minVars, const int maxVars,
			  const QList<XMLRuleStringParser::XMLRule> &symbols);
				       //throws XMLAutomatonSyntaxErrorException {

    static bool checkVars(const int minVars, const int maxVars,
			  const XMLRuleStringParser::XMLRule &symbol);
				       //throws XMLAutomatonSyntaxErrorException {

    const MatchFlags getExcludedMatchFlags() const {
        return excludedMatchFlags;
    }

    const MatchFlags getIncludedMatchFlags() const {
        return includedMatchFlags;
    }

    QString matchFlagstoString(const MatchFlags &mf, const QChar &prefix) const;

    QString description;
    int errorLevel;
    QString entryMessage;
    QString beginMessage;
    QString propagMessage;
    QString endMessage;
    QString patternName;
    MatchFlags excludedMatchFlags;
    MatchFlags includedMatchFlags;
};

}

#endif
