#ifndef CALLSITECFGNAVIGATOR_H
#define CALLSITECFGNAVIGATOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QSet>

#include "../../codestructures/CFGsNavigator.h"

#include "CallSiteDetector.h"

namespace checker {

class CallSiteCFGNavigator final : public codestructs::CFGsNavigator {
    // package-private section
public:
    CallSiteCFGNavigator(const CFGsNavigator &navigator,
			 const CallSiteDetector &callDetector) :
	    navigator(navigator), callDetector(callDetector) {}

public:
    virtual bool isCallNode(const Node &node) const override {
	return callDetector.isCallNode(node);
    }

    virtual bool isStartNode(const Node &node) const override {
	return navigator.isStartNode(node);
    }

    virtual bool isEndNode(const Node &node) const override {
	return navigator.isEndNode(node);
    }

    virtual Node getCalleeStart(const Node &node) const override {
	return navigator.getCalleeStart(node);
    }

    virtual Node getCalleeEnd(const Node &node) const override {
	return navigator.getCalleeEnd(node);
    }

    virtual NodeList getCallersFromStart(const Node &node) const override {
	return navigator.getCallersFromStart(node);
    }

    virtual NodeList getCallersFromEnd(const Node &node) const override {
	return navigator.getCallersFromEnd(node);
    }

    virtual NodeList callSites() const override {
	return navigator.callSites();
    }

private:
    const CFGsNavigator &navigator;
    const CallSiteDetector &callDetector;
};

}

#endif
