#ifndef CONNECTPATTERNLOCATIONTOSUCCESSORS_H
#define CONNECTPATTERNLOCATIONTOSUCCESSORS_H

/**
 * @file ConnectPatternLocationToSuccessors.h
 * @brief Implements class ConnectPatternLocationToSuccessors which is
 *        responsible for creating connections between PatternLocation instances
 *        with respect to control-flow of source code.
 *
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby
 *
 * Licensed under GPLv2.
 */

#include "../../codestructures/traversal/CFGVisitor.h"

namespace codestructs {
class CFGNode;
}

namespace checker {

class PatternLocation;
class NodeLocationDictionary;

/**
 * @brief Instances are responsible for creating connections between
 *        PatternLocation instances with respect to control-flow of source code.
 *
 * @see cz.muni.stanse.utils.CFGvisitor
 */
class ConnectPatternLocationToSuccessors final : public codestructs::CFGVisitor {

public:
    bool visit(const codestructs::CFGNode &node/*, const Element element*/) override;

    // package-private section

    ConnectPatternLocationToSuccessors(PatternLocation *location,
		    const NodeLocationDictionary &dictionary) :
	    referenceLocation(location), nodeLocationsDictionary(dictionary) { }

private:

    PatternLocation *getReferenceLocation() {
        return referenceLocation;
    }

    const NodeLocationDictionary &getNodeLocationsDictionary() {
        return nodeLocationsDictionary;
    }

    PatternLocation *referenceLocation;
    const NodeLocationDictionary &nodeLocationsDictionary;
};

}

#endif
