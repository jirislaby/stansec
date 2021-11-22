/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/Analysis/CFG.h>
#include <clang/AST/Stmt.h>

#include <QList>
#include <QPair>
#include <QSet>
#include <QStack>

#include "CFGTraversal.h"
#include "CFGVisitor.h"

using namespace codestructs;

QList<const clang::Stmt *> ForwardCFGNodeFollowers::get(const clang::Stmt *node) const
{
	assert(0); abort();
	//return node.getSuccessors();
}

QList<const clang::Stmt *> BackwardCFGNodeFollowers::get(const clang::Stmt *node) const
{
	assert(0); abort();
	//return node.getPredecessors();
}


QList<const clang::Stmt *> ForwardCFGNodeFollowersInterprocedural::get(const clang::Stmt *node)
{
	assert(0); abort();
    //return node.getSuccessors();
}



QList<const clang::Stmt *> BackwardCFGNodeFollowersInterprocedural::get(const clang::Stmt *node)
{
	assert(0); abort();
	//return node.getPredecessors();
}

void CFGTraversal::traverseCFG(const clang::CFG *cfg,
			       clang::Stmt *startNode,
			       const CFGNodeFollowers &nodeFollowers,
			       CFGTraversationContainer<const clang::Stmt *> &nodesToVisit,
			       CFGVisitor &visitor)
{
    QSet<const clang::Stmt *> visitedNodes;
    nodesToVisit.insert(startNode);
    do {
	auto currentNode = nodesToVisit.remove();
	if (visitedNodes.contains(currentNode))
	    continue;
	visitedNodes.insert(currentNode);
	if (!visitor.visitInternal(currentNode/*, currentNode.getElement()*/))
	    continue;
	for (auto currentNodeFollower : nodeFollowers.get(currentNode))
	    nodesToVisit.insert(currentNodeFollower);
    } while (!nodesToVisit.isEmpty());
}
#if 0
    private static void traverseCFGPaths(const CFGHandle cfg,
                            const QList<CFGNode> path,
                            const CFGNodeFollowers nodeFollowers,
                            const CFGPathVisitor visitor,
                            const QSet<QPair<CFGNode,CFGNode>> visitedEdges) {
        if (!visitor.visitInternal(Collections.unmodifiableList(path),
                                   new QStack<CFGNode>()))
            return;

        for (CFGNode currentNodeFollower : nodeFollowers.get(path.getFirst())) {
            const QPair<CFGNode,CFGNode> edge =
                new QPair<CFGNode,CFGNode>(path.getFirst(),currentNodeFollower);
            if (visitedEdges.contains(edge)) {
		visitor.endPath(Collections.unmodifiableList(path),
			new QStack<CFGNode>());
                continue;
	    }

            path.addFirst(currentNodeFollower);
            visitedEdges.add(edge);

            traverseCFGPaths(cfg,path,nodeFollowers,visitor,visitedEdges);

            visitedEdges.remove(edge);
            path.removeFirst();
        }
    }

    private static void traverseCFGPathsInterprocedural(
                    const QList<CFGNode> path,
                    const CFGNodeFollowersInterprocedural nodeFollowers,
                    const CFGPathVisitor visitor,
                    const QStack<QSet<QPair<CFGNode,CFGNode>>> visitedStack,
                    const QStack<CFGNode> callStack) {
        const QSet<QPair<CFGNode,CFGNode>> visitedEdges = visitedStack.peek();
        if (nodeFollowers.isCallNode(path.get(0))) {
            if (path.size() < 2 || !nodeFollowers.isReturnNode(path.get(1))) {
                const QPair<CFGNode,CFGNode> edge = QPair.make(path.getFirst(),
                                  nodeFollowers.getCalleeNode(path.getFirst()));
                if (visitedEdges.contains(edge)) {
		    visitor.endPath(Collections.unmodifiableList(path), callStack);
                    return;
		}
                if (visitor.onCFGchange(path.getFirst(),edge.getSecond())) {
                    visitedStack.push(
                            new QSet<QPair<CFGNode,CFGNode>>(visitedEdges));
                    callStack.push(edge.getFirst());
                    traverseCFGPathsInterproceduralByEdge(edge,path,
                                  nodeFollowers,visitor,visitedStack,callStack);
                    return;
                }
            }
        }
        else if (!visitor.visitInternal(Collections.unmodifiableList(path),
                                        callStack))
            return;
        if (nodeFollowers.isReturnNode(path.get(0)) && !callStack.isEmpty()) {
            const QPair<CFGNode,CFGNode> edge = QPair.make(path.getFirst(),
                                                         callStack.peek());
            if (visitedEdges.contains(edge)) {
		visitor.endPath(Collections.unmodifiableList(path), callStack);
                return;
	    }
            callStack.pop();
            visitedStack.pop();
            visitor.onCFGchange(path.getFirst(),edge.getSecond());
            traverseCFGPathsInterproceduralByEdge(edge,path,nodeFollowers,
                                                visitor,visitedStack,callStack);
            return;
        }
        for (CFGNode currentNodeFollower : nodeFollowers.get(path.getFirst())) {
            const QPair<CFGNode,CFGNode> edge = QPair.make(path.getFirst(),
                                                         currentNodeFollower);
            if (visitedEdges.contains(edge)) {
		visitor.endPath(Collections.unmodifiableList(path), callStack);
                continue;
	    }
            traverseCFGPathsInterproceduralByEdge(edge,path,nodeFollowers,
                                                visitor,visitedStack,callStack);
        }
    }

    private static void traverseCFGPathsInterproceduralByEdge(
                    const QPair<CFGNode,CFGNode> edge,
                    const QList<CFGNode> path,
                    const CFGNodeFollowersInterprocedural nodeFollowers,
                    const CFGPathVisitor visitor,
                    const QStack<QSet<QPair<CFGNode,CFGNode>>> visitedStack,
                    const QStack<CFGNode> callStack) {
        const QSet<QPair<CFGNode,CFGNode>> visitedEdges = visitedStack.peek();
        path.addFirst(edge.getSecond());
        visitedEdges.add(edge);

        traverseCFGPathsInterprocedural(path,nodeFollowers,visitor,
                                        visitedStack,callStack);
        visitedEdges.remove(edge);
        path.removeFirst();
    }

#endif
