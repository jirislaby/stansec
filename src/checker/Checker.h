#ifndef CHECKER_H
#define CHECKER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QString>

#include "../codestructures/LazyInternalStructures.h"

#include "CheckingResult.h"
#include "CheckerErrorReceiver.h"
#include "CheckerProgressMonitor.h"

namespace checker {

class Checker {
public:
    virtual ~Checker() {}
    virtual QString getName() = 0;

    virtual CheckingResult
    check(const codestructs::LazyInternalStructures &internals,
	  CheckerErrorReceiver &errReceiver,
	  CheckerProgressMonitor &monitor) = 0;
    //throws CheckerException;
};

}

#endif
