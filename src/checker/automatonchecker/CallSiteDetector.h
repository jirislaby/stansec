#ifndef CALLSITEDETECTOR_H
#define CALLSITEDETECTOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QSet>

#include "../../codestructures/CFGNode.h"
#include "../../codestructures/CFGsNavigator.h"
#include "NodeLocationDictionary.h"

namespace checker {

class CallSiteDetector {

    // package-private section
public:
	CallSiteDetector() = delete;

	CallSiteDetector(const codestructs::CFGsNavigator &navigator,
			 const NodeLocationDictionary &NLD) :
	    NLD(NLD), navigator(navigator) { }

	bool isCallNode(const codestructs::CFGNode &node) const {
	    if (!getNavigator().isCallNode(node))
		return false;
	    return getNodeLocationDictionary().contains(node);
	}

	QSet<codestructs::CFGNode> callSites() const {
	    QSet<codestructs::CFGNode> result;
	    for (const auto node : getNavigator().callSites())
		if (isCallNode(node))
		    result.insert(node);
	    return result;
	}

private:
	const codestructs::CFGsNavigator &getNavigator() const {
	    return navigator;
	}

	const NodeLocationDictionary &getNodeLocationDictionary() const {
	    return NLD;
	}

	const NodeLocationDictionary &NLD;
	const codestructs::CFGsNavigator &navigator;
};

}

#endif
