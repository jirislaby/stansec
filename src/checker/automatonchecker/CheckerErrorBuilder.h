#ifndef CHECKERERRORBUILDER_H
#define CHECKERERRORBUILDER_H

/**
 * @file CheckerErrorBuilder.java
 * @brief Implements class CheckerErrorBuilder which is responsible to
 *        compute all checker errors which can be translated from automata
 *        states at PaternLocations.
 *
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby
 *
 * Licensed under GPLv2.
 */

//#include <QList>
#include <QPair>
#include <QString>

#include "../CheckingResult.h"

namespace clang {
class Stmt;
}

namespace codestructs {
class LazyInternalStructures;
}

namespace checker {

class AutomatonCheckerLogger;
class CheckerErrorReceiver;
class NodeLocationDictionary;
class PatternLocation;

/**
 * @brief Provides static method buildErrorList which compute the checker-errors
 *        from automata states at PattenLocations assigned to matching source
 *        code locacions by use of error transition rules defined in XML
 *        automata definition file.
 *
 * Class is not intended to be instantiated.
 *
 * @see cz.muni.stanse.checker.CheckerError
 * @see cz.muni.stanse.automatonchecker.AutomatonChecker
 */
class CheckerErrorBuilder final {
    // package-private section
public:
    /**
     * @brief Computes a list of all checker-errors, which can be recognized by
     *        error transition rules (defined in XML automata definition file)
     *        from automata states at PattenLocations assigned to matching
     *        source code locations.
     *
     * @param NLD Dictionary, which provides mapping from
     *                                   CFGNodes (i.e. reference to source code
     *                                   locations) to related PatternLocations.
     * @return List of checker-errors recognized from automata states at
     *         PatternLocations.
     */
    static CheckingResult
    buildErrorList(const NodeLocationDictionary &NLD,
		   const codestructs::LazyInternalStructures &internals,
		   void */*const QList<FalsePositivesDetector>*/ detectors,
		   CheckerErrorReceiver &errReceiver,
		   checker::AutomatonCheckerLogger &monitor,
		   const QString &automatonName);

private:

    static QPair<int, CheckingResult>
    buildErrorsInLocation(PatternLocation &location,
			  const NodeLocationDictionary &NLD,
			  const codestructs::LazyInternalStructures &internals,
			  void */*const QList<FalsePositivesDetector>*/ detectors,
			  CheckerErrorReceiver &errReceiver,
			  AutomatonCheckerLogger &monitor,
			  const QString &automatonName);

    static QString getNodeUnitName(const clang::Stmt *node,
				   const codestructs::LazyInternalStructures &internals);

    static QString getLocationUnitName(const PatternLocation location,
				       const codestructs::LazyInternalStructures &internals);

    CheckerErrorBuilder() = delete;
};

}

#endif
