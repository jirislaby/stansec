#ifndef AUTOMATONSTATECFGCONTEXTALGO_H
#define AUTOMATONSTATECFGCONTEXTALGO_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QSet>
#include <QStack>

#include "AutomatonState.h"

namespace codestructs {
class CFGNode;
}

namespace checker {

class AutomatonStateCFGcontextAlgo {

    // package-private section
public:
    using Node = codestructs::CFGNode;
    using Context = QStack<Node>;

    static const QSet<Context>
    getContexts(const QSet<AutomatonState> &states);

    static const Context
    getContext(const AutomatonState &state) {
        return getContext(state.getContext());
    }

    static const Context
    getContext(const QStack<AutomatonStateContextItem> &context);

    static const QSet<AutomatonState>
    filterStatesByContext(const QSet<AutomatonState> &states,
			  const Context &context);

    static bool firstIsSubcontextOfSecond(const Context &contextFirst,
					  const Context &contextSecond);

private:
    static QSet<AutomatonState>
    filterUniqueStates(const QSet<AutomatonState> &states,
		       const int idx, QSet<AutomatonState> &result);

    AutomatonStateCFGcontextAlgo() = delete;
};

}

#endif
