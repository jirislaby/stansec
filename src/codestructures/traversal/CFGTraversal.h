#ifndef CFGTRAVERSAL_H
#define CFGTRAVERSAL_H

/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QPair>
#include <QSet>
#include <QStack>

#include "../CFGsNavigator.h"
#include "../CFGNode.h"

#include "CFGPathVisitor.h"

namespace clang {
class CFG;
class CFGBlock;
class CFGStmt;
class Stmt;
}

namespace codestructs {

class CFGsNavigator;
class CFGVisitor;

// Node followers --------------------------------------------------------------

class CFGNodeFollowers {
public:
    using Node = CFGNode;
    using Followers = QList<Node>;

    virtual Followers get(const Node &node) const = 0;
};

class ForwardCFGNodeFollowers final : public CFGNodeFollowers {
    virtual Followers get(const Node &node) const override;
} ;

class BackwardCFGNodeFollowers final : public CFGNodeFollowers {
    virtual Followers get(const Node &node) const override;
};

// Node followers Interprocedural ----------------------------------------------

class CFGNodeFollowersInterprocedural {
public:
    using Node = CFGNode;
    using Followers = QList<Node>;

    virtual ~CFGNodeFollowersInterprocedural();
    virtual Followers get(const Node &node) const = 0;
    virtual bool isCallNode(const Node &node) const = 0;
    virtual bool isReturnNode(const Node &node) const = 0;
    virtual Node getCalleeNode(const Node &node) const = 0;
};

class ForwardCFGNodeFollowersInterprocedural final : public CFGNodeFollowersInterprocedural {
public:
    ForwardCFGNodeFollowersInterprocedural(const CFGsNavigator &navigator) :
	navigator(navigator) { }

    virtual Followers get(const Node &node) const override;

    virtual bool isCallNode(const Node &node) const override {
        return navigator.isCallNode(node);
    }

    virtual bool isReturnNode(const Node &node) const override {
        return navigator.isEndNode(node);
    }

    virtual Node getCalleeNode(const Node &node) const override {
        return navigator.getCalleeStart(node);
    }
private:
    const CFGsNavigator &navigator;
};

class BackwardCFGNodeFollowersInterprocedural final : public CFGNodeFollowersInterprocedural {
public:
    BackwardCFGNodeFollowersInterprocedural(const CFGsNavigator &navigator) :
	navigator(navigator) {}

    virtual QList<Node> get(const Node &node) const override;

    virtual bool isCallNode(const Node &node) const override {
        return navigator.isCallNode(node);
    }

    virtual bool isReturnNode(const Node &node) const override {
        return navigator.isStartNode(node);
    }

    virtual Node getCalleeNode(const Node &node) const override {
        return navigator.getCalleeEnd(node);
    }
private:
    const CFGsNavigator &navigator;
};

// CFG traversal itself --------------------------------------------------------

class CFGTraversal final {

public:
    using Node = CFGNode;
    using VisitedEdge = QPair<Node, Node>;
    using VisitedEdges = QSet<VisitedEdge>;
    using VisitedStack = QStack<VisitedEdges>;
    using Path = CFGPathVisitor::Path;

    template <typename CB>
    static void visitBlockStmtsIdx(const clang::CFG *cfg,
				   CB &cb) {
	for (auto I = cfg->begin(), E = cfg->end(); I != E; ++I)
		for (auto BI = (*I)->ref_begin(), BE = (*I)->ref_end(); BI != BE; ++BI)
			if (auto s = (*BI)->getAs<clang::CFGStmt>())
				if (cb(*I, s->getStmt(), (*BI).getIndexInBlock()))
					return;
    }

    static void
    traverseCFGToBreadthForward(const clang::CFG *cfg,
				CFGVisitor &visitor,
				const Node *startNode = nullptr);

#ifdef CRAWL
    static void
    traverseCFGToBreadthBackward(const clang::CFG *cfg, Stmt *startNode,
				 CFGVisitor &visitor) {
	CFGTraversationQueue<Stmt *> q;
	traverseCFG(cfg,startNode, BackwardCFGNodeFollowers(), q, visitor);
    }

    static void
    traverseCFGToDepthForward(const clang::CFG *cfg, Stmt *startNode,
			      CFGVisitor &visitor) {
	CFGTraversationStack<Stmt *> s;
	traverseCFG(cfg, startNode, ForwardCFGNodeFollowers(), s, visitor);
    }

    static void
    traverseCFGToDepthBackward(const clang::CFG *cfg, Stmt *startNode,
			       CFGVisitor &visitor) {
	CFGTraversationStack<Stmt *> s;
	traverseCFG(cfg, startNode, BackwardCFGNodeFollowers(), s, visitor);
    }
#endif
#ifdef NEEDED
    static void
    traverseFunctionForward(const clang::CFG *cfg, CFGVisitor &visitor) {
	Path path;
	path.insert(cfg->getStartNode());
	traverseCFGPaths(cfg, path, ForwardCFGNodeFollowers(), visitor,
			 VisitedEdges());
    }

    static void
    traverseFunctionBackward(const clang::CFG *cfg, CFGVisitor &visitor) {
	Path path;
	path.insert(cfg->getEndNode());
	traverseCFGPaths(cfg, path, BackwardCFGNodeFollowers(), visitor,
			 VisitedEdges());
    }

    static void
    traverseCFGPathsForward(const clang::CFG *cfg, Stmt *startNode,
			    CFGVisitor &visitor) {
	Path path;
	path.append(startNode);
	traverseCFGPaths(cfg, path, ForwardCFGNodeFollowers(), visitor,
			 VisitedEdges());
    }

    static void
    traverseCFGPathsBackward(const clang::CFG *cfg, Stmt *startNode,
			     CFGVisitor &visitor) {
	Path path;
	path.append(startNode);
	traverseCFGPaths(cfg, path, BackwardCFGNodeFollowers(), visitor,
			 VisitedEdges());
    }

    static void
    traverseCFGPathsForwardInterprocedural(const CFGsNavigator &navigator,
					   Stmt *startNode,
					   CFGPathVisitor &visitor,
					   CFGPathVisitor::CallStack stack = CFGPathVisitor::CallStack()) {
	Path path;
	path.append(startNode);
        traverseCFGPathsInterprocedural(path,
			  ForwardCFGNodeFollowersInterprocedural(navigator),
			  visitor, createVisitedStack(stack.size() + 1), stack);
    }
#endif

    static void
    traverseCFGPathsBackwardInterprocedural(const CFGsNavigator &navigator,
					    const Node &startNode,
					    CFGPathVisitor &visitor,
					    CFGPathVisitor::CallStack stack = CFGPathVisitor::CallStack()) {
	Path path;
	path.append(startNode);
        traverseCFGPathsInterprocedural(path,
			 BackwardCFGNodeFollowersInterprocedural(navigator),
			 visitor, createVisitedStack(stack.size() + 1), stack);
    }

private:

    static VisitedStack createVisitedStack(int size) {
	VisitedStack stack;

	stack.resize(size);

        return stack;
    }
#if 0
    static void traverseCFG(const clang::CFG *cfg,
			   Stmt *startNode,
			   const CFGNodeFollowers &nodeFollowers,
			   CFGTraversationContainer<Stmt *> &nodesToVisit,
			   CFGVisitor &visitor);
#endif

#ifdef NEEDED
    static void traverseCFGPaths(const clang::CFG *cfg,
				 Path path,
				 const CFGNodeFollowers &nodeFollowers,
				 const CFGPathVisitor &visitor,
				 VisitedEdges visitedEdges);
#endif

    static void traverseCFGPathsInterprocedural(Path &path,
		    const CFGNodeFollowersInterprocedural &nodeFollowers,
		    CFGPathVisitor &visitor,
		    VisitedStack visitedStack,
		    CFGPathVisitor::CallStack &callStack);

    static void traverseCFGPathsInterproceduralByEdge(const VisitedEdge &edge,
						      Path &path,
						      const CFGNodeFollowersInterprocedural &nodeFollowers,
						      CFGPathVisitor &visitor,
						      VisitedStack &visitedStack,
						      CFGPathVisitor::CallStack &callStack);

    CFGTraversal() = delete;
};

}

#endif
