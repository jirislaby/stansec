#ifndef AUTOMATONSTATE_H
#define AUTOMATONSTATE_H

/**
 * @file AutomatonState.java
 * @brief Here are defined automata states for all the automata defined in XML
 *        automata definition file of automatonchecker package.
 *
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QStack>
#include <QString>

#include "AutomatonStateContextItem.h"
#include "ComposedAutomatonID.h"
#include "SimpleAutomatonID.h"

namespace checker {

/**
 * @brief This class represents automaton state for each automata class defined
 *        in XML automata definition file.
 *
 *  Automata states represents the data, which are delivered between
 *  PatternLocation instances, which is the main idea in whole automatonchecker
 *  package. So each automaton state presented in some PatternLocation tells as,
 *  that related automaton (for that state) already was in the location in that
 *  state.
 *
 * @see cz.muni.stanse.automatonchecker.PatternLocation
 */
class AutomatonState final {

public:
#if 0
    public bool equals(const Object obj) {
        return (obj == null || getClass() != obj.getClass()) ?
                    false : isEqualWith((AutomatonState)obj);
    }
#endif

    // package-private section

    AutomatonState(const QString symbol, const ComposedAutomatonID id) :
	    symbol(symbol) {
	getContext().push(AutomatonStateContextItem(id));
    }

    AutomatonState(const QString symbol, const SimpleAutomatonID id) :
	AutomatonState(symbol, ComposedAutomatonID(id)) { }

    AutomatonState(const QString symbol,
		   const QStack<AutomatonStateContextItem> &context) :
	    symbol(symbol), context(context) { }

    QString getSymbol() const { return symbol; }
    const QStack<AutomatonStateContextItem> getContext() const { return context; }

    ComposedAutomatonID getAutomatonID() const {
	return getContext().top().getAutomatonID();
    }

    const codestructs::CFGNode getCFGNode() const {
	return getContext().top().getCFGNode();
    }

#if 0
    bool isEqualWith(AutomatonState other) {
        return getSymbol().equals(other.getSymbol()) &&
               getContext().equals(other.getContext());
    }

    QString toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(symbol);
        for (AutomatonStateContextItem ctxitem : context)
            sb.append("[").append(ctxitem.getAutomatonID()).append("]");
        return sb.toString();
    }
#endif

private:
    QStack<AutomatonStateContextItem> &getContext() { return context; }

    QString symbol;
    QStack<AutomatonStateContextItem> context;
};

inline bool operator==(const AutomatonState &lhs, const AutomatonState &rhs)
{
	return lhs.getSymbol() == rhs.getSymbol() &&
			lhs.getContext() == rhs.getContext();
}

inline uint qHash(const AutomatonState &state, uint seed)
{
	return 7 * qHash(state.getSymbol(), seed) +
			qHash(state.getContext(), seed);
}

inline QDebug operator<<(QDebug d, const AutomatonState &state)
{
	d << "AutomatonState(" << state.getSymbol() << " ";
	for (auto ctxItem : state.getContext())
		d << ctxItem.getAutomatonID();
	d << ')';
	return d;
}

}

#endif
