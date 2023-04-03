/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QMap>
#include <QSet>
#include <QStack>

#include "AutomatonStateCFGcontextAlgo.h"

using namespace checker;

const QSet<AutomatonStateCFGcontextAlgo::Context>
AutomatonStateCFGcontextAlgo::getContexts(const QSet<AutomatonState> &states)
{
    QSet<Context> result;
    QSet<AutomatonState> empty;

    for (const auto &state : filterUniqueStates(states, 0, empty))
	result.insert(getContext(state));

    return result;
}

const AutomatonStateCFGcontextAlgo::Context
AutomatonStateCFGcontextAlgo::getContext(const QStack<AutomatonStateContextItem> &context)
{
    Context result;

    for (const auto &item : context)
	if (item.getCFGNode().isValid())
	    result.push(item.getCFGNode());

    return result;
}

const QSet<AutomatonState>
AutomatonStateCFGcontextAlgo::filterStatesByContext(const QSet<AutomatonState> &states,
						    const Context &context)
{
    QSet<AutomatonState> result;

    for (const auto &state : states)
	if (firstIsSubcontextOfSecond(getContext(state), context))
	    result.insert(state);

    return result;
}

bool AutomatonStateCFGcontextAlgo::firstIsSubcontextOfSecond(const Context &contextFirst,
							     const Context &contextSecond)
{
    return contextFirst.size() <= contextSecond.size() &&
	    contextFirst.mid(0, contextFirst.size()) ==
	    contextSecond.mid(0, contextFirst.size());
}

QSet<AutomatonState>
AutomatonStateCFGcontextAlgo::filterUniqueStates(const QSet<AutomatonState> &states,
						 const int idx,
						 QSet<AutomatonState> &result)
{
    if (states.size() <= 1) {
	result |= states;
	return result;
    }

    QMap<AutomatonStateContextItem, QSet<AutomatonState>> spliter;
    for (const auto &state : states)
	if (state.getContext().size() > idx) {
	    const auto item = state.getContext()[idx];
	    if (!spliter.contains(item))
		spliter.insert(item, QSet<AutomatonState>());
	    spliter[item].insert(state);
	}

    if (spliter.isEmpty()) {
	result |= states;
	return result;
    }

    for (const auto &splitClass : spliter.values())
	filterUniqueStates(splitClass, idx+1, result);

    return result;
}
