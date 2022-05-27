#ifndef PATTERNLOCATIONCREATOR_H
#define PATTERNLOCATIONCREATOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <memory>

#include <QList>
#include <QMap>
#include <QPair>
#include <QSet>
#include <QString>

#include "../../utils/AliasResolver.h"
//#include "../../utils/xmlpatterns/XMLPattern.h"
#include "../../codestructures/traversal/CFGVisitor.h"
#include "../../codestructures/LazyInternalStructures.h"

#include "PatternLocation.h"
#include "SimpleAutomatonID.h"

namespace clang {
class CFG;
class CFGBlock;
class Stmt;
}

namespace codestructs {
class CFGHandle;
class CFGsNavigator;
}

namespace utils {
class XMLPattern;
class XMLPatternVariablesAssignment;
}

namespace checker {

class NodeLocationDictionary;
class XMLAutomatonDefinition;

class PatternLocationCreator final : public codestructs::CFGVisitorIdx {

public:
    // package-private section

    PatternLocationCreator(const codestructs::CFGHandle &cfg,
			   const XMLAutomatonDefinition &automatonDefinition,
			   const codestructs::LazyInternalStructures &internals,
			   NodeLocationDictionary &NLD) :
	LIS(internals), automatonDefinition(automatonDefinition), NLD(NLD),
	cfg(cfg), aliasResolver(internals.getAliasResolver()) {
	createStartEndPatternLocations();
    }

    NodeLocationDictionary &getNodeLocationDictionary() const { return NLD; }
    const QSet<SimpleAutomatonID> &getAutomataIDs() const { return automataIDs; }
    QSet<SimpleAutomatonID> &getAutomataIDs() { return automataIDs; }

private:

    using Matchings = QList<QPair<const utils::XMLPattern *, SimpleAutomatonID> >;
#if 0
    void checkMatchingConflict(const clang::Stmt *node,
			       const Matchings &matchings);
#endif

    virtual bool visit(const clang::CFGBlock *blk, const clang::Stmt *stmt,
		       size_t index) override;

    std::unique_ptr<PatternLocation>
    createCommonPatternLocation(const codestructs::CFGNode &node,
				const Matchings &matchings) {
	return std::make_unique<PatternLocation>(LIS, node,
						 createTransitionRules(matchings),
						 createErrorRules(matchings));
    }

    QList<TransitionRule> createTransitionRules(const Matchings &matchings);
    QList<ErrorRule> createErrorRules(const Matchings &matchings);

    std::unique_ptr<PatternLocation>
    createRuleLessPatternLocation(const codestructs::CFGNode &node) {
	return std::make_unique<PatternLocation>(LIS, node);
    }

    void createStartEndPatternLocations();

    bool isGlobalAssignment(const utils::XMLPatternVariablesAssignment &assignment);

    const XMLAutomatonDefinition &getXMLAutomatonDefinition() const {
	return automatonDefinition;
    }

    codestructs::CFGsNavigator &getNavigator() const {
	return LIS.getNavigator();
    }

    const codestructs::CFGHandle &getCfg() const {
	return cfg;
    }

    const codestructs::LazyInternalStructures &LIS;
    const XMLAutomatonDefinition &automatonDefinition;
    NodeLocationDictionary &NLD;
    QSet<SimpleAutomatonID> automataIDs;
    const codestructs::CFGHandle &cfg;
    utils::AliasResolver aliasResolver;
    //const static Logger logger = Logger.getLogger(PatternLocationCreator.class);
};

}

#endif
