#ifndef NODETOCFGDICTIONARYBUILDER_H
#define NODETOCFGDICTIONARYBUILDER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>

#include "../LazyInternalStructures.h"

namespace codestructs {

class CFGHandle;

class NodeToCFGdictionaryBuilder final {
public:
    static void run(const QList<CFGHandle> &CFGs,
		    LazyInternalStructures::NodeToCFGDictionary &dict);

private:
    NodeToCFGdictionaryBuilder() = delete;
};

}

#endif
