#ifndef TRANSITIONRULE_H
#define TRANSITIONRULE_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <llvm/ADT/Optional.h>

#include <QDebug>
#include <QString>

#include "AutomatonState.h"
#include "SimpleAutomatonID.h"
#include "XMLTransitionRule.h"

namespace clang {
class LangOptions;
}

namespace checker {

class TransitionRule final {
    // package-private section
public:
    TransitionRule(const XMLTransitionRule *XMLrule,
		   const SimpleAutomatonID &automatonID) : XMLrule(XMLrule),
	automatonID(automatonID) {}

    llvm::Optional<AutomatonState>
    transformAutomatonState(const AutomatonState &state) const {
	return getXMLrule()->transformAutomatonState(state, getAutomatonID());
    }

    const SimpleAutomatonID &getAutomatonID() const { return automatonID; }
    const XMLTransitionRule *getXMLrule() const { return XMLrule; }

    QString toString(const clang::LangOptions &LO) const {
	QString result(getAutomatonID().toString(LO));
	result.append(": ").append(getXMLrule()->toString());
	return result;
    }

private:
    const XMLTransitionRule *XMLrule;
    SimpleAutomatonID automatonID;
};

inline QDebug operator<<(QDebug d, const TransitionRule &r)
{
	d << r.getAutomatonID() << r.getXMLrule();
	return d;
}

}

#endif
