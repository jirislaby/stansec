#ifndef REACHABILITYCHECKER_H
#define REACHABILITYCHECKER_H

/**
 * @brief ReachabilityChecker implementation
 *
 * Copyright (c) 2009-2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QRegularExpression>
#include <QString>

#include "../../codestructures/LazyInternalStructures.h"

#include "../Checker.h"
#include "../CheckingResult.h"

namespace clang {
class CFGBlock;
class Stmt;
}

namespace checker {

/**
 * @brief Static checker which is able to detect unrechable code.
 *
 * @see cz.muni.stanse.checker.Checker
 */
class ReachabilityChecker : public Checker {
public:

    ReachabilityChecker() { }
    virtual ~ReachabilityChecker() override { }

    /**
     * @brief Uniquely identifies the checker by the string identifier.
     *
     * @return QString which uniquely identifies the checker.
     * @see cz.muni.stanse.checker.Checker#getName()
     */
    virtual QString getName() override;

    /**
     * @brief Does the source code checking itself.
     *
     * Method searches through source code to find nodes (except start node)
     * with no predecessors.
     *
     * @return List of errors found in the source code.
     * @see cz.muni.stanse.checker.Checker#check(java.util.List)
     */
    virtual CheckingResult check(const codestructs::LazyInternalStructures &internals,
				 CheckerErrorReceiver &errReceiver,
				 CheckerProgressMonitor &monitor) override;


private:
    static bool isBreakOrReturn(const clang::CFGBlock *blk);
    static void buildTrace(QList<const clang::Stmt *> &trace,
		      const clang::CFGBlock *node);
};

}

#endif
