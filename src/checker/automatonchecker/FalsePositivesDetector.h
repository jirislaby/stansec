#ifndef FALSEPOSITIVESDETECTOR_H
#define FALSEPOSITIVESDETECTOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include "../../codestructures/traversal/CFGPathVisitor.h"

namespace checker {

class ErrorRule;

class FalsePositivesDetector {
public:
    static int getFalsePositiveImportance() { return -1; }

    static int getBugImportance(int importance) {
        assert(importance >= 0);
        return importance;
    }

    static int getBugDefaultImportance() { return 0; }

    virtual int getTraceImportance(const codestructs::CFGPathVisitor::Path &path,
				   const codestructs::CFGPathVisitor::CallStack &cfgContext,
				   const ErrorRule &rule) = 0;
};

}

#endif
