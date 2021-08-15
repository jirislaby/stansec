/*
 * Copyright (c) 2022 Jiri Slaby
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Stmt.h>
#include <clang/Analysis/CFG.h>

#include "NodeLocationDictionary.h"
#include "PatternLocation.h"
#include "../../codestructures/CFGNode.h"

using namespace checker;

NodeLocationDictionary::~NodeLocationDictionary() {
	for (auto blockLocs : *this)
		for (auto idxLoc : blockLocs) {
		    auto &x = idxLoc.second;
		    delete x.first;
		    if (x.first != x.second)
			delete x.second;
		}
}

llvm::Optional<LocationPair>
NodeLocationDictionary::value(const codestructs::CFGNode &node) const
{
	auto it = QMap::find(node.getBlock());

	if (it != end())
	    for (auto &i : *it)
		if (i.first == node.getBlockIdx())
		    return i.second;

	return llvm::Optional<LocationPair>();
}
