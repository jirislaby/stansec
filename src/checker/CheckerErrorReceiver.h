#ifndef CHECKERERRORRECEIVER_H
#define CHECKERERRORRECEIVER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <functional>

#include <QList>

#include "CheckerError.h"

namespace checker {

class CheckerErrorReceiver {
public:
    typedef std::function<void(const CheckerError &error)> receiveFun;
    typedef std::function<void()> onEndFun;

    CheckerErrorReceiver() = delete;
    CheckerErrorReceiver(receiveFun receive, onEndFun onEnd = [](){}) :
	receive(receive), onEnd(onEnd) {}

    virtual void receiveAll(const QList<CheckerError> &errors) {
	for (const auto &error : errors)
	    receive(error);
    }

    receiveFun receive;
    onEndFun onEnd;
};

}

#endif
