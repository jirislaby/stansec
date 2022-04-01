#ifndef NODELOCATIONDICTIONARY_H
#define NODELOCATIONDICTIONARY_H

/*
 * Copyright (c) 2022 Jiri Slaby
 *
 * Licensed under GPLv2.
 */

#include <llvm/ADT/Optional.h>

#include <QList>
#include <QMap>
#include <QPair>

namespace clang {
class CFGBlock;
}

namespace codestructs {
class CFGNode;
}

namespace checker {

class PatternLocation;

/*
 * LocationPair is either of:
 * 1) call:return for interprocedural cases, or
 * 2) location:location otherwise (the same location twice)
 */
using LocationPair = QPair<PatternLocation *, PatternLocation *>;
/* A vector of (index in CFGBlock + location) */
using Locations = QList<QPair<int, LocationPair>>;

class NodeLocationDictionary : public QMap<const clang::CFGBlock *, Locations> {
public:
	~NodeLocationDictionary();

	bool contains(const codestructs::CFGNode &node) const {
		return value(node).operator bool();
	}

	llvm::Optional<LocationPair> value(const codestructs::CFGNode &node) const;
	llvm::Optional<LocationPair> operator[](const codestructs::CFGNode &node) const {
		return value(node);
	}
	Locations &operator[](const clang::CFGBlock *blk) {
		return QMap::operator[](blk);
	}
	const Locations operator[](const clang::CFGBlock *blk) const {
		return QMap::operator[](blk);
	}
};

}

#endif // NODELOCATIONDICTIONARY_H
