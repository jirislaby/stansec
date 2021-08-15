#ifndef ERRORRULE_H
#define ERRORRULE_H

/**
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QSet>
#include <QString>

#include "SimpleAutomatonID.h"
#include "XMLErrorRule.h"

namespace checker {

class ErrorRule final {
    // package-private section
public:
    ErrorRule(const XMLErrorRule *XMLrule,
	      const SimpleAutomatonID &automatonID) : XMLrule(XMLrule),
	automatonID(automatonID) {}

    ErrorRule(const ErrorRule &source, const SimpleAutomatonID &automatonID) :
	    XMLrule(source.getXMLrule()), automatonID(automatonID) { }

    QString getErrorDescription() const {
	return getXMLrule()->getErrorDescription();
    }

    int getErrorLevel() const {
	return getXMLrule()->getErrorLevel();
    }

    QString getErrorEntryMessage() const {
	return getXMLrule()->getErrorEntryMessage();
    }

    QString getErrorBeginMessage() const {
	return getXMLrule()->getErrorBeginMessage();
    }

    QString getErrorPropagMessage() const {
	return getXMLrule()->getErrorPropagMessage();
    }

    QString getErrorEndMessage() const {
	return getXMLrule()->getErrorEndMessage();
    }

    bool checkForError(const QSet<AutomatonState> &state) const {
	return getXMLrule()->checkForError(state, getAutomatonID());
    }

    bool isExitRule() const {
	return getXMLrule()->isExitRule();
    }

    const SimpleAutomatonID &getAutomatonID() const { return automatonID; }

    QString toString() const {
	QString result(getAutomatonID().toString());
	result.append(": ").append(getXMLrule()->toString());
	return result;
    }

private:
    const XMLErrorRule *getXMLrule() const { return XMLrule; }

    const XMLErrorRule *XMLrule;
    SimpleAutomatonID automatonID;
};

inline QDebug operator<<(QDebug d, const ErrorRule &r)
{
	d << r.toString();
	return d;
}

}

#endif
