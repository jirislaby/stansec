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

#include "CFGPathVisitor.h"

namespace clang {
class CFG;
class Stmt;
}

namespace codestructs {

class CFGsNavigator;
class CFGVisitor;

// Node followers --------------------------------------------------------------

class CFGNodeFollowers {
public:
    using Node = const clang::Stmt;
    using Followers = QList<Node *>;

    virtual Followers get(Node *node) const = 0;
};

class ForwardCFGNodeFollowers final : public CFGNodeFollowers {
    virtual Followers get(Node *node) const override;
} ;

class BackwardCFGNodeFollowers final : public CFGNodeFollowers {
    virtual Followers get(Node *node) const override;
};

// Node followers Interprocedural ----------------------------------------------

class CFGNodeFollowersInterprocedural {
public:
    using Node = const clang::Stmt;
    using Followers = QList<Node *>;

    virtual ~CFGNodeFollowersInterprocedural();
    virtual Followers get(Node *node) const = 0;
    virtual bool isCallNode(Node *node) const = 0;
    virtual bool isReturnNode(Node *node) const = 0;
    virtual Node *getCalleeNode(Node *node) const = 0;
};

class ForwardCFGNodeFollowersInterprocedural final : public CFGNodeFollowersInterprocedural {
public:
    ForwardCFGNodeFollowersInterprocedural(const CFGsNavigator &navigator) :
	navigator(navigator) { }

    virtual Followers get(Node *node) const override;

    virtual bool isCallNode(Node *node) const override {
        return navigator.isCallNode(node);
    }

    virtual bool isReturnNode(Node *node) const override {
        return navigator.isEndNode(node);
    }

    virtual Node *getCalleeNode(Node *node) const override {
        return navigator.getCalleeStart(node);
    }
private:
    const CFGsNavigator &navigator;
};

class BackwardCFGNodeFollowersInterprocedural final : public CFGNodeFollowersInterprocedural {
public:
    BackwardCFGNodeFollowersInterprocedural(const CFGsNavigator &navigator) :
	navigator(navigator) {}

    virtual QList<Node *> get(Node *node) const override;

    virtual bool isCallNode(Node *node) const override {
        return navigator.isCallNode(node);
    }

    virtual bool isReturnNode(Node *node) const override {
        return navigator.isStartNode(node);
    }

    virtual Node *getCalleeNode(Node *node) const override {
        return navigator.getCalleeEnd(node);
    }
private:
    const CFGsNavigator &navigator;
};

// Traversation container ------------------------------------------------------

template <typename T>
class CFGTraversationContainer {
public:
    virtual void insert(const T node) = 0;
    virtual T remove() = 0;
    virtual bool isEmpty() const = 0;
};


template <typename T>
class CFGTraversationQueue final : public CFGTraversationContainer<T> {
public:
    virtual void insert(const T obj) override { queue.append(obj); }
    virtual T remove() override { return queue.takeFirst(); }
    virtual bool isEmpty() const override { return queue.isEmpty(); }

private:
    QList<T> queue;
};

template <typename T>
class CFGTraversationStack final : public CFGTraversationContainer<T> {
public:
    virtual void insert(const T obj) override { stack.push(obj); }
    virtual T remove() override { return stack.pop(); }
    virtual bool isEmpty() const override { return stack.isEmpty(); }

private:
    QStack<T> stack;
};

// CFG traversal itself --------------------------------------------------------

class CFGTraversal final {

public:
    using Stmt = const clang::Stmt;
    using VisitedEdge = QPair<Stmt *, Stmt *>;
    using VisitedEdges = QSet<VisitedEdge>;
    using VisitedStack = QStack<VisitedEdges>;
    using Path = CFGPathVisitor::Path;

    static void
    traverseCFGToBreadthForward(const clang::CFG *cfg, Stmt *startNode,
				CFGVisitor &visitor) {
	CFGTraversationQueue<Stmt *> q;
	traverseCFG(cfg, startNode, ForwardCFGNodeFollowers(), q, visitor);
    }

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
					    Stmt *startNode,
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

    static void traverseCFG(const clang::CFG *cfg,
			   Stmt *startNode,
			   const CFGNodeFollowers &nodeFollowers,
			   CFGTraversationContainer<Stmt *> &nodesToVisit,
			   CFGVisitor &visitor);

#ifdef NEEDED
    static void traverseCFGPaths(const clang::CFG *cfg,
				 Path path,
				 const CFGNodeFollowers &nodeFollowers,
				 const CFGPathVisitor &visitor,
				 VisitedEdges visitedEdges) {
	if (!visitor.visitInternal(path, CFGPathVisitor::CFGContext()))
            return;

	for (auto currentNodeFollower : nodeFollowers.get(path.first())) {
	    const auto edge = qMakePair(path.first(), currentNodeFollower);
            if (visitedEdges.contains(edge)) {
		visitor.endPath(path, CFGPathVisitor::CFGContext());
                continue;
	    }

	    path.prepend(currentNodeFollower);
	    visitedEdges.insert(edge);

	    traverseCFGPaths(cfg, path, nodeFollowers, visitor, visitedEdges);

            visitedEdges.remove(edge);
            path.removeFirst();
        }
    }
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
