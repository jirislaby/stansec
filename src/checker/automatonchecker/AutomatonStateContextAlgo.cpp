/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QStack>

#include "AutomatonStateContextAlgo.h"

using namespace checker;


#include "CFGNode.h"

//import java.util.QStack;

/*final*/ class AutomatonStateContextAlgo {

    // package-private section

    static bool
    canPush(const QStack<AutomatonStateContextItem> context, const CFGNode node,
                                                 const ComposedAutomatonID id) {
        const AutomatonStateContextItem newItem =
            new AutomatonStateContextItem(node,id);
        for (const AutomatonStateContextItem item : context)
            if (item.equals(newItem))
                return false;
        return true;
    }

    static QStack<AutomatonStateContextItem>
    push(const QStack<AutomatonStateContextItem> context, const CFGNode node,
                                                 const ComposedAutomatonID id) {
        const QStack<AutomatonStateContextItem> result = copy(context);
        result.push(new AutomatonStateContextItem(node,id));
        return result;
    }

    static QStack<AutomatonStateContextItem>
    pop(const QStack<AutomatonStateContextItem> context) {
        const QStack<AutomatonStateContextItem> result = copy(context);
        result.pop();
        return result;
    }

    static QStack<AutomatonStateContextItem>
    swop(const QStack<AutomatonStateContextItem> context, const CFGNode node,
                                                 const ComposedAutomatonID id) {
        const QStack<AutomatonStateContextItem> result = pop(context);
        result.push(new AutomatonStateContextItem(node,id));
        return result;
    }

    static QStack<AutomatonStateContextItem>
    copy(const QStack<AutomatonStateContextItem> context) {
        const QStack<AutomatonStateContextItem> copy =
            new QStack<AutomatonStateContextItem>();
        copy.addAll(context);
        return copy;
    }

private:

    private AutomatonStateContextAlgo() {
    }
}
