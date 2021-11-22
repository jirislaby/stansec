#ifndef NODETOCFGDICTIONARYBUILDER_H
#define NODETOCFGDICTIONARYBUILDER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QMap>

namespace clang {
class Stmt;
}

namespace codestructs {

class CFGHandle;

class NodeToCFGdictionaryBuilder final {
public:
    using NodeToCFGDictionary = QMap<const clang::Stmt *, const CFGHandle *>;

    static void run(const QList<CFGHandle> &CFGs, NodeToCFGDictionary &dict);

private:
    NodeToCFGdictionaryBuilder() = delete;
};

}

#endif
