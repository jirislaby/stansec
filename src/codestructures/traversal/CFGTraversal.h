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
    virtual QList<clang::Stmt *> get(const clang::Stmt *node) const = 0;
};

class ForwardCFGNodeFollowers final : CFGNodeFollowers {
    virtual QList<clang::Stmt *> get(const clang::Stmt *node) const override;
} ;

class BackwardCFGNodeFollowers final : CFGNodeFollowers {
    virtual QList<clang::Stmt *> get(const clang::Stmt *node) const override;
};

// Node followers Interprocedural ----------------------------------------------

class CFGNodeFollowersInterprocedural {
public:
    virtual QList<clang::Stmt *> get(const clang::Stmt *node) = 0;
    virtual bool isCallNode(const clang::Stmt *node);
    virtual bool isReturnNode(const clang::Stmt *node);
    virtual clang::Stmt *getCalleeNode(const clang::Stmt *node);
};

class ForwardCFGNodeFollowersInterprocedural final : CFGNodeFollowersInterprocedural {
public:
    ForwardCFGNodeFollowersInterprocedural(const CFGsNavigator &navigator) :
	navigator(navigator) { }

    virtual QList<clang::Stmt *> get(const clang::Stmt *node) override;

    virtual bool isCallNode(const clang::Stmt *node) override {
        return navigator.isCallNode(node);
    }

    virtual bool isReturnNode(const clang::Stmt *node) override {
        return navigator.isEndNode(node);
    }

    virtual clang::Stmt *getCalleeNode(const clang::Stmt *node) override {
        return navigator.getCalleeStart(node);
    }
private:
    const CFGsNavigator &navigator;
};

class BackwardCFGNodeFollowersInterprocedural final : CFGNodeFollowersInterprocedural {
public:
    BackwardCFGNodeFollowersInterprocedural(const CFGsNavigator &navigator) :
	navigator(navigator) {}

    virtual QList<clang::Stmt *> get(const clang::Stmt *node) override;

    virtual bool isCallNode(const clang::Stmt *node) override {
        return navigator.isCallNode(node);
    }

    virtual bool isReturnNode(const clang::Stmt *node) override {
        return navigator.isStartNode(node);
    }

    virtual clang::Stmt *getCalleeNode(const clang::Stmt *node) override {
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
    virtual void insert(const T obj) override { queue.add(obj); }
    virtual T remove() override { return queue.remove(); }
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

    template<typename T> //<T extends CFGvisitor>
    static
    T traverseCFGToBreadthForward(const clang::CFG *cfg,
				  const clang::Stmt *startNode, const T visitor) {
	traverseCFG(cfg, startNode,
		    ForwardCFGNodeFollowers(),
		    CFGTraversationQueue<clang::Stmt *>(),
                    visitor);
        return visitor;
    }
#ifdef NEEDED
    template<typename T> //<T extends CFGvisitor>
    static
    T traverseCFGToBreadthBackward(const clang::CFG *cfg,
				   const clang::Stmt *startNode, const T visitor) {
        traverseCFG(cfg,startNode,
                    new BackwardCFGNodeFollowers(),
		    new CFGTraversationQueue<clang::Stmt *>(),
                    visitor);
        return visitor;
    }

    template<typename T> //<T extends CFGvisitor>
    static
    T traverseCFGToDepthForward(const clang::CFG *cfg,
				const clang::Stmt * startNode, const T visitor) {
        traverseCFG(cfg,startNode,
                    new ForwardCFGNodeFollowers(),
		    new CFGTraversationStack<clang::Stmt *>(),
                    visitor);
        return visitor;
    }

    template<typename T> //<T extends CFGvisitor>
    static
    T traverseCFGToDepthBackward(const clang::CFG *cfg,
				 const clang::Stmt * startNode, const T visitor) {
        traverseCFG(cfg,startNode,
                    new BackwardCFGNodeFollowers(),
		    new CFGTraversationStack<clang::Stmt *>(),
                    visitor);
        return visitor;
    }

    template<typename T> //<T extends CFGPathVisitor>
    static
    T traverseFunctionForward(const clang::CFG *cfg, const T &visitor) {
	QList<clang::Stmt *> path;
	path.insert(cfg->getStartNode());
	traverseCFGPaths(cfg, path,
			 ForwardCFGNodeFollowers(),
			 visitor,new QSet<QPair<clang::Stmt *,clang::Stmt *>>());
        return visitor;
    }

    template<typename T> //<T extends CFGPathVisitor>
    static
    T traverseFunctionBackward(const clang::CFG *cfg, const T &visitor) {
	QList<clang::Stmt *> path;
	path.insert(cfg->getEndNode());
        traverseCFGPaths(cfg,path,
			 BackwardCFGNodeFollowers(),
			 visitor,new QSet<QPair<clang::Stmt *,clang::Stmt *>>());
        return visitor;
    }

    template<typename T> //<T extends CFGPathVisitor>
    static
    T traverseCFGPathsForward(const clang::CFG *cfg,
			      clang::Stmt *startNode,
			      const T &visitor) {
	QList<clang::Stmt *> path;
	path.append(startNode);
        traverseCFGPaths(cfg,path,
			 ForwardCFGNodeFollowers(),
			 visitor,new QSet<QPair<clang::Stmt *,clang::Stmt *>>());
        return visitor;
    }

    template<typename T> //<T extends CFGPathVisitor>
    static
    T traverseCFGPathsBackward(const clang::CFG *cfg,
			       clang::Stmt *startNode,
			       const T &visitor) {
	QList<clang::Stmt *> path;
	path.append(startNode);
	traverseCFGPaths(cfg, path,
                         new BackwardCFGNodeFollowers(),
			 visitor,new QSet<QPair<clang::Stmt *,clang::Stmt *>>());
        return visitor;
    }

    template<typename T> //<T extends CFGPathVisitor>
    static
    T traverseCFGPathsForwardInterprocedural(const CFGsNavigator &navigator,
					     const clang::Stmt *startNode,
					     const T &visitor) {
        return traverseCFGPathsForwardInterprocedural(navigator,startNode,
						  visitor,new QStack<clang::Stmt *>());
    }

    template<typename T> //<T extends CFGPathVisitor>
    static
    T traverseCFGPathsForwardInterprocedural(const CFGsNavigator &navigator,
					     clang::Stmt *startNode,
					     const T &visitor,
					     const QStack<clang::Stmt *> stack) {
	QList<clang::Stmt *> path;
	path.append(startNode);
        traverseCFGPathsInterprocedural(path,
			  ForwardCFGNodeFollowersInterprocedural(navigator),
                          visitor,createVisitedStack(stack.size()+1),stack);
        return visitor;
    }

    template<typename T> //<T extends CFGPathVisitor>
    static
    T traverseCFGPathsBackwardInterprocedural(const CFGsNavigator &navigator,
					      const clang::Stmt *startNode,
					      const T &visitor) {
        return traverseCFGPathsBackwardInterprocedural(navigator,startNode,
						  visitor,new QStack<clang::Stmt *>());
    }

    template<typename T> //<T extends CFGPathVisitor>
    static
    T traverseCFGPathsBackwardInterprocedural(const CFGsNavigator &navigator,
					      clang::Stmt *startNode,
					      const T &visitor,
					      const QStack<clang::Stmt *> stack) {
	QList<clang::Stmt *> path;
	path.append(startNode);
        traverseCFGPathsInterprocedural(path,
			 BackwardCFGNodeFollowersInterprocedural(navigator),
                         visitor,createVisitedStack(stack.size()+1),stack);
        return visitor;
    }
#endif

private:

#ifdef NEEDED
    static QStack<QSet<QPair<clang::Stmt *,clang::Stmt *>>>
    createVisitedStack(int size) {
	QStack<QSet<QPair<clang::Stmt *,clang::Stmt *>>> stack;
        for (int i = 0; i < size; ++i)
	    stack.push(QSet<QPair<clang::Stmt *,clang::Stmt *>>());
        return stack;
    }
#endif

    static void traverseCFG(const clang::CFG *cfg,
			   clang::Stmt *startNode,
			   const CFGNodeFollowers &nodeFollowers,
			   CFGTraversationContainer<clang::Stmt *> &nodesToVisit,
			   CFGVisitor &visitor);

#if 0
    static void traverseCFGPaths(const clang::CFG *cfg,
			    const QList<clang::Stmt *> path,
                            const CFGNodeFollowers nodeFollowers,
			    const CFGPathVisitor &visitor,
			    const QSet<QPair<clang::Stmt *,clang::Stmt *>> visitedEdges) {
        if (!visitor.visitInternal(Collections.unmodifiableList(path),
				   new QStack<clang::Stmt *>()))
            return;

	for (clang::Stmt * currentNodeFollower : nodeFollowers.get(path.getFirst())) {
	    const QPair<clang::Stmt *,clang::Stmt *> edge =
		new QPair<clang::Stmt *,clang::Stmt *>(path.getFirst(),currentNodeFollower);
            if (visitedEdges.contains(edge)) {
		visitor.endPath(Collections.unmodifiableList(path),
			new QStack<clang::Stmt *>());
                continue;
	    }

            path.addFirst(currentNodeFollower);
            visitedEdges.add(edge);

            traverseCFGPaths(cfg,path,nodeFollowers,visitor,visitedEdges);

            visitedEdges.remove(edge);
            path.removeFirst();
        }
    }

    static void traverseCFGPathsInterprocedural(
		    const QList<clang::Stmt *> path,
                    const CFGNodeFollowersInterprocedural nodeFollowers,
                    const CFGPathVisitor visitor,
		    const QStack<QSet<QPair<clang::Stmt *,clang::Stmt *>>> visitedStack,
		    const QStack<clang::Stmt *> callStack) {
	const QSet<QPair<clang::Stmt *,clang::Stmt *>> visitedEdges = visitedStack.peek();
        if (nodeFollowers.isCallNode(path.get(0))) {
            if (path.size() < 2 || !nodeFollowers.isReturnNode(path.get(1))) {
		const QPair<clang::Stmt *,clang::Stmt *> edge = QPair.make(path.getFirst(),
                                  nodeFollowers.getCalleeNode(path.getFirst()));
                if (visitedEdges.contains(edge)) {
		    visitor.endPath(Collections.unmodifiableList(path), callStack);
                    return;
		}
                if (visitor.onCFGchange(path.getFirst(),edge.getSecond())) {
                    visitedStack.push(
			    new QSet<QPair<clang::Stmt *,clang::Stmt *>>(visitedEdges));
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
	    const QPair<clang::Stmt *,clang::Stmt *> edge = QPair.make(path.getFirst(),
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
	for (clang::Stmt * currentNodeFollower : nodeFollowers.get(path.getFirst())) {
	    const QPair<clang::Stmt *,clang::Stmt *> edge = QPair.make(path.getFirst(),
                                                         currentNodeFollower);
            if (visitedEdges.contains(edge)) {
		visitor.endPath(Collections.unmodifiableList(path), callStack);
                continue;
	    }
            traverseCFGPathsInterproceduralByEdge(edge,path,nodeFollowers,
                                                visitor,visitedStack,callStack);
        }
    }

    static void traverseCFGPathsInterproceduralByEdge(
		    const QPair<clang::Stmt *,clang::Stmt *> edge,
		    const QList<clang::Stmt *> path,
                    const CFGNodeFollowersInterprocedural nodeFollowers,
                    const CFGPathVisitor visitor,
		    const QStack<QSet<QPair<clang::Stmt *,clang::Stmt *>>> visitedStack,
		    const QStack<clang::Stmt *> callStack) {
	const QSet<QPair<clang::Stmt *,clang::Stmt *>> visitedEdges = visitedStack.peek();
        path.addFirst(edge.getSecond());
        visitedEdges.add(edge);

        traverseCFGPathsInterprocedural(path,nodeFollowers,visitor,
                                        visitedStack,callStack);
        visitedEdges.remove(edge);
        path.removeFirst();
    }
#endif
    CFGTraversal() = delete;
};

}

#endif
