/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby
 *
 * Licensed under GPLv2.
 */

#include "ConnectPatternLocationToSuccessors.h"
#include "NodeLocationDictionary.h"
#include "PatternLocation.h"

bool checker::ConnectPatternLocationToSuccessors::visit(const codestructs::CFGNode &node)
{
	auto &dict = getNodeLocationsDictionary();
	auto it = dict.value(node);
	if (!it)
	    return true;

	const auto &nodeLocationsPair = *it;
	auto refloc = getReferenceLocation();

	if (nodeLocationsPair.second == refloc)
	    return true;

	auto fi = nodeLocationsPair.first;
	assert(node == fi->getCFGreferenceNode());
	auto &succs = refloc->getSuccessorPatternLocations();
	if (!succs.contains(fi))
	    succs.append(fi);

	return false;
}
