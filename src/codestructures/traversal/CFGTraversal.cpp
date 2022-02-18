/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <llvm/ADT/BreadthFirstIterator.h>

#include <clang/Analysis/CFG.h>
#include <clang/AST/Stmt.h>

#include <QList>
#include <QPair>
#include <QSet>
#include <QStack>

#include "CFGTraversal.h"
#include "CFGVisitor.h"

using namespace codestructs;

CFGNodeFollowers::Followers
ForwardCFGNodeFollowers::get(const Node &node) const
{
	assert(0); abort();
	//return node.getSuccessors();
}

CFGNodeFollowers::Followers
BackwardCFGNodeFollowers::get(const Node &node) const
{
	assert(0); abort();
	//return node.getPredecessors();
}


CFGNodeFollowersInterprocedural::Followers
ForwardCFGNodeFollowersInterprocedural::get(const Node &node) const
{
	assert(0); abort();
    //return node.getSuccessors();
}

CFGNodeFollowersInterprocedural::Followers
BackwardCFGNodeFollowersInterprocedural::get(const Node &node) const
{
	assert(0); abort();
	//return node.getPredecessors();
}

const clang::CFGBlock *CFGTraversal::findCFGBlock(const clang::CFG *cfg,
						  const clang::Stmt *stmt,
						  size_t *index)
{
	const clang::CFGBlock *retval = nullptr;

	const auto cb = [stmt, index, &retval](const clang::CFGBlock *blk,
			const clang::Stmt *stmt2, size_t index2) -> bool {
		if (stmt == stmt2) {
			if (index)
			    *index = index2;
			retval = blk;
			return true;
		}
		return false;
	};

	visitBlockStmtsIdx(cfg, cb);

	return retval;
}

void CFGTraversal::traverseCFGToBreadthForward(const clang::CFG *cfg,
					       CFGVisitor &visitor,
					       const Node *startNode) {
	const clang::CFGBlock *blk;
	bool seeking = false;
	if (startNode) {
		if (startNode->hasStmt()) {
			blk = findCFGBlock(cfg, startNode->getStmt());
			seeking = true;
		} else
			blk = startNode->getBlock();
	} else
	    blk = &cfg->getEntry();

	/* different CFG */
	if (!blk)
	    return;

	for (auto I = llvm::bf_begin(blk); I != llvm::bf_end(blk); ++I) {
	    if (!seeking && !visitor.visit(CFGNode(*I))) {
		I.Visited.insert((*I)->succ_begin(),
				 (*I)->succ_end());
		continue;
	    }
	    for (auto BI = (*I)->begin(), BE = (*I)->end(); BI != BE; ++BI)
		if (auto stmt = BI->getAs<clang::CFGStmt>()) {
		    if (seeking && startNode->getStmt() != stmt->getStmt())
			continue;
		    seeking = false;
		    if (!visitor.visit(CFGNode(stmt->getStmt()))) {
			I.Visited.insert((*I)->succ_begin(),
					 (*I)->succ_end());
			break;
		    }
		}
	}
}
#if 0
void CFGTraversal::traverseCFG(const clang::CFG *cfg,
			       Stmt *startNode,
			       const CFGNodeFollowers &nodeFollowers,
			       CFGTraversationContainer<Stmt *> &nodesToVisit,
			       CFGVisitor &visitor)
{
	QSet<Stmt *> visitedNodes;
	nodesToVisit.insert(startNode);
	do {
		auto currentNode = nodesToVisit.remove();
		if (visitedNodes.contains(currentNode))
	    continue;
	visitedNodes.insert(currentNode);
	if (!visitor.visit(currentNode/*, currentNode.getElement()*/))
	    continue;
	for (auto currentNodeFollower : nodeFollowers.get(currentNode))
	    nodesToVisit.insert(currentNodeFollower);
    } while (!nodesToVisit.isEmpty());
}
#endif

#ifdef NEEDED
void CFGTraversal::traverseCFGPaths(const clang::CFG *cfg, Path path, const CFGNodeFollowers &nodeFollowers, const CFGPathVisitor &visitor, VisitedEdges visitedEdges)
{
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
#endif

void CFGTraversal::traverseCFGPathsInterprocedural(Path &path,
						   const CFGNodeFollowersInterprocedural &nodeFollowers,
						   CFGPathVisitor &visitor,
						   VisitedStack visitedStack,
						   CFGPathVisitor::CallStack &callStack)
{
	auto &visitedEdges = visitedStack.top();
	if (nodeFollowers.isCallNode(path[0])) {
#ifdef INTERPROC
		if (path.size() < 2 || !nodeFollowers.isReturnNode(path[1])) {
			auto callee = nodeFollowers.getCalleeNode(path.first());
			const auto edge = qMakePair(path.first(), callee);
			if (visitedEdges.contains(edge)) {
				visitor.onEndPath(path, callStack);
				return;
			}
			if (visitor.onCFGchange(path.first(), edge.second)) {
				visitedStack.push(visitedEdges);
				callStack.push(edge.first);
				traverseCFGPathsInterproceduralByEdge(edge, path,
								      nodeFollowers,
								      visitor,
								      visitedStack,
								      callStack);
				return;
			}
		}
#else
		assert(0); abort();
#endif
	} else if (!visitor.visit(path, callStack))
		return;

	if (nodeFollowers.isReturnNode(path[0]) && !callStack.isEmpty()) {
#ifdef INTERPROC
		const auto edge = qMakePair(path.first(), callStack.top());
		if (visitedEdges.contains(edge)) {
			visitor.onEndPath(path, callStack);
			return;
		}
		callStack.pop();
		visitedStack.pop();
		visitor.onCFGchange(path.first(), edge.second);
		traverseCFGPathsInterproceduralByEdge(edge, path, nodeFollowers,
						      visitor, visitedStack,
						      callStack);
		return;
#else
		assert(0); abort();
#endif
	}

	for (const auto &currentNodeFollower : nodeFollowers.get(path.first())) {
		const auto edge = qMakePair(path.first(), currentNodeFollower);
		if (visitedEdges.contains(edge)) {
			visitor.onEndPath(path, callStack);
			continue;
		}
		traverseCFGPathsInterproceduralByEdge(edge, path, nodeFollowers,
						      visitor, visitedStack,
						      callStack);
	}
}

void CFGTraversal::traverseCFGPathsInterproceduralByEdge(const VisitedEdge &edge,
							 Path &path,
							 const CFGNodeFollowersInterprocedural &nodeFollowers,
							 CFGPathVisitor &visitor,
							 VisitedStack &visitedStack,
							 CFGPathVisitor::CallStack &callStack)
{
	auto &visitedEdges = visitedStack.top();
	path.prepend(edge.second);
	visitedEdges.insert(edge);

	traverseCFGPathsInterprocedural(path, nodeFollowers, visitor,
					visitedStack, callStack);
	visitedEdges.remove(edge);
	path.removeFirst();
}

CFGNodeFollowersInterprocedural::~CFGNodeFollowersInterprocedural()
{
}
