#ifndef PATTERNLOCATIONBUILDER_H
#define PATTERNLOCATIONBUILDER_H

/**
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QString>

#include "../../codestructures/CFGNode.h"

#include "NodeLocationDictionary.h"
#include "SimpleAutomatonID.h"

namespace clang {
class CFG;
class Stmt;
class SourceManager;

namespace ento {
class AnalysisManager;
}
}

namespace codestructs {
class CFGHandle;
class CFGsNavigator;
class LazyInternalStructures;
}

namespace checker {

class AutomatonState;
class AutomatonStateTransferManager;
class CallSiteDetector;
class ErrorRule;
class PatternLocation;
class XMLAutomatonDefinition;
class XMLErrorRule;

class PatternLocationBuilder final {

    // package-private section
public:

    static void buildPatternLocations(const codestructs::LazyInternalStructures &internals,
				      const XMLAutomatonDefinition &automatonDefinition,
				      NodeLocationDictionary &NLD);
				       //throws XMLAutomatonSyntaxErrorException

    static void NLDToDotFile(const NodeLocationDictionary &NLD,
			     clang::ento::AnalysisManager &AM,
			     const QString &file);
    static QString NLDToDot(const NodeLocationDictionary &NLD,
			    clang::ento::AnalysisManager &AM);
    static void dumpNLD(const NodeLocationDictionary &NLD,
			const clang::SourceManager &SM,
			const QString &prefix = QString());
    static void dumpNLDPatLoc(const PatternLocation *patLoc,
			      const QString &prefix = "  ");


private:

    PatternLocationBuilder() = delete;

    static void
    buildPatternLocationsAndStatesForOneCFG(codestructs::CFGHandle &cfg,
					    const XMLAutomatonDefinition &automatonDefinition,
					    const codestructs::LazyInternalStructures &internals,
					    const bool isStartFunction,
					    NodeLocationDictionary &NLD,
					    QSet<SimpleAutomatonID> &globalAutomataIDs);
				       //throws XMLAutomatonSyntaxErrorException

    static void setStateTransferorToLocations(const QList<Locations> &locations,
					      checker::AutomatonStateTransferManager *transferor);
    static void createIntraproceduralConnectionsBetweenPatternLocations(NodeLocationDictionary &nodeLocationDictionary,
									const codestructs::CFGHandle &cfg);
    static PatternLocation *connectInsideBlock(NodeLocationDictionary &NLD,
					       const clang::CFGBlock *blk,
					       Locations &stmtList);

    static void createInterproceduralConnectionsBetweenPatternLocations(const NodeLocationDictionary &nodeLocationDictionary,
		    const codestructs::CFGsNavigator &navigator,
		    const CallSiteDetector &callDetector);

    static void connectCallerCallee(PatternLocation *callLocation,
				    PatternLocation *returnLocation,
				    PatternLocation *calleeStartLocation,
				    PatternLocation *calleeEndLocation);

    static void splitAutomataIDsIntoGlobalLocalAndFloation(const QSet<SimpleAutomatonID> &IDs,
							   const codestructs::CFGHandle &cfg,
							   QSet<SimpleAutomatonID> &globals,
							   QSet<SimpleAutomatonID> &locals,
							   QSet<SimpleAutomatonID> &floats);

    static bool
    isParameterDependentID(const SimpleAutomatonID &automatonID,
			   const QList<QString> &params) {
	for (const auto &param : params)
	    if (isParameterDependentID(automatonID, param))
                return true;
        return false;
    }

    static bool isParameterDependentID(const SimpleAutomatonID &id,
				       const QString &paramName) {
	for (const auto &varsAssign : id.getVarsAssignment())
            if (varsAssign.contains(paramName))
                return true;
        return false;
    }

    static bool isOfLocallyDeclaredVariable(const SimpleAutomatonID &id,
					    const codestructs::CFGHandle &cfg);
    static bool isInReturnExpression(const SimpleAutomatonID &id,
				     const codestructs::CFGHandle &cfg);
    static bool isInReturnExpression(const SimpleAutomatonID &id,
				     const QSet<QString> &dependentVars);

    static void addInitialAutomatonStatesForCFGLocations(PatternLocation &startLoc,
		    PatternLocation &endLoc,
		    const XMLAutomatonDefinition &automatonDefinition,
		    const QSet<SimpleAutomatonID> &automataIDs,
		    const bool asGlobal);

    static QList<AutomatonState>
    getAutomataStates(const QString startSymbol,
		      const QSet<SimpleAutomatonID> &automataIDs,
		      const bool asGlobal);

    static QList<ErrorRule>
    getExitErrorRules(const QList<const XMLErrorRule *> &XMLrules,
		      const QSet<SimpleAutomatonID> &automataIDs,
		      const bool asGlobal);

    static QString nodeToDotID(const codestructs::CFGNode &node);
    static QString nodeToSrcLine(const codestructs::CFGNode &node,
				 clang::ento::AnalysisManager &AM);
    static void NodeToDot(const codestructs::CFGNode &node,
			  const LocationPair &locPair,
			  clang::ento::AnalysisManager &AM, QString &dot,
			  QSet<QPair<QString, QString> > &addedArcs);
};

}

#endif
