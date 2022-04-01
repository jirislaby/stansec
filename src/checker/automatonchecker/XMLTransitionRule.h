#ifndef XMLTRANSITIONRULE_H
#define XMLTRANSITIONRULE_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <llvm/ADT/Optional.h>

#include <QList>
#include <QString>

#include "XMLRuleStringParser.h"

class QDomElement;

namespace checker {

class AutomatonState;
class ComposedAutomatonID;
class SimpleAutomatonID;

class XMLTransitionRule {
    // package-private section
public:
    XMLTransitionRule() = delete;
    explicit XMLTransitionRule(const QDomElement &XMLtransitionElement);
//                                       throws XMLAutomatonSyntaxErrorException {

    QString getInSymbol() const { return inSymbol; }
    QString getPatternName() const { return patternName; }
    QString getOutSymbol() const { return outSymbol; }

    llvm::Optional<AutomatonState>
    transformAutomatonState(const AutomatonState &state,
			    const SimpleAutomatonID &simpleID) const;

    QString toString() const;

private:
    bool isThisRuleApplicable(const ComposedAutomatonID &composedID,
			      const SimpleAutomatonID &simpleID) const;

    llvm::Optional<AutomatonState>
    buildResultState(const AutomatonState &state,
		     const SimpleAutomatonID &simpleID) const;

    static QList<bool> buildMatchFlags(const QStringList &automataIDs,
					 const QString &automatonID);

    static QList<int> buildMatchOutIndices(const QStringList &fromAutomataIDs,
					     const QStringList &toAutomataIDs,
					     const QString &automatonID);
				       //throws XMLAutomatonSyntaxErrorException {

    static int findAutomatonIDindex(const QStringList &automataIDs,
				    const QString &searchedID);
    //throws XMLAutomatonSyntaxErrorException {

    static bool checkMode(XMLRuleStringParser::Mode mode);
    //                                   throws XMLAutomatonSyntaxErrorException {

    static bool checkVars(const int minVars, const int maxVars,
			  const int numVars);
    //throws XMLAutomatonSyntaxErrorException {

    const QList<bool> &getMatchFlags() const { return matchFlags; }
    const QList<int> &getMatchOutIndices() const { return matchOutIndices; }

    QString patternName;
    QString inSymbol;
    QString outSymbol;
    QList<bool> matchFlags;
    QList<int> matchOutIndices;
};

}

#endif
