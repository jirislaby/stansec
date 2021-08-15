#ifndef AUTOMATONSTATECONTEXTALGO_H
#define AUTOMATONSTATECONTEXTALGO_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QStack>

#include "AutomatonStateContextItem.h"

namespace codestructs {
class CFGNode;
}

namespace checker {

class ComposedAutomatonID;

class AutomatonStateContextAlgo final {
    // package-private section
public:
    static bool canPush(const QStack<AutomatonStateContextItem> &context,
			const codestructs::CFGNode &node,
			const ComposedAutomatonID &id) {
	const AutomatonStateContextItem newItem(node, id);
	for (const auto &item : context)
	    if (item == newItem)
                return false;
        return true;
    }

private:
    AutomatonStateContextAlgo() = delete;
};

}

#endif
