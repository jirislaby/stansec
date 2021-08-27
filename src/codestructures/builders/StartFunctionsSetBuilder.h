#ifndef STARTFUNCTIONSSETBUILDER_H
#define STARTFUNCTIONSSETBUILDER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QSet>

//#include "../../utils/DirectedGraph.h"

namespace codestructs {

class StartFunctionsSetBuilder {
#if 0
public:
    typedef utils::DirectedGraph<CFGHandle> Graph;

    static QSet<CFGHandle> run(const Graph &callGraph) {
	auto clone = callGraph.clone();
	return runDestructive(clone);
    }

    static QSet<CFGHandle> runDestructive(Graph &callGraph) {
	QSet<CFGHandle> result;

	for (int inDegree = 0; !callGraph.vertexSet().isEmpty(); ++inDegree) {
	    const auto fnSet = getFunctionsWithInDegree(inDegree, callGraph);
	    result |= fnSet;
	    removeComponentContaining(fnSet, callGraph);
	}
	assert(callGraph.vertexSet().isEmpty());
	return result;
    }

private:

    static QSet<CFGHandle> getFunctionsWithInDegree(int inDegree,
						    const Graph &callGraph) {
	QSet<CFGHandle> result;

	for (const auto cfg : callGraph.vertexSet())
	    if (callGraph.inDegreeOf(cfg) == inDegree)
		result.insert(cfg);

	return result;
    }

    static void removeComponentContaining(const QSet<CFGHandle> fnSet,
					  Graph &callGraph) {
	auto progressQueue = fnSet.values();

	do {
	    const auto &cfg = progressQueue.takeFirst();
	    if (!callGraph.containsVertex(cfg))
		continue;
	    for (const auto e: callGraph.outgoingEdgesOf(cfg))
		progressQueue.append(callGraph.getEdgeTarget(e));
	    callGraph.removeVertex(cfg);
	} while (!progressQueue.isEmpty());
    }

#endif
    StartFunctionsSetBuilder() = delete;
};

}

#endif
