#ifndef LAZYINTERNALSTRUCTURES_H
#define LAZYINTERNALSTRUCTURES_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QMap>
#include <QSet>
#include <QString>

//#include "../utils/DirectedGraph.h"
#include "../utils/AliasResolver.h"

#include "builders/StartFunctionsSetBuilder.h"
//#include "NodeToCFGdictionaryBuilder.h"

namespace clang {
class CallGraph;
class CFG;
class TranslationUnitDecl;
namespace ento { class AnalysisManager; }
}

namespace codestructs {

class LazyInternalStructures {
public:
    LazyInternalStructures(clang::ento::AnalysisManager &mgr,
			   const clang::TranslationUnitDecl *TU) : mgr(mgr),
	    TU(TU), callGraph(nullptr) {
#if 0
	for (auto unit : units) {
	    if (unit.getAliases() != null)
		this.aliasResolver.addAliasMapping(unit.getAliases());
	}

	startFunctions = null;
        navigator = null;
        argumentPassingManager = null;
        returnValuePassingManager = null;
        nodeToCFGdictionary = null;
        elementToCFGdictionary = null;
#endif
    }
    ~LazyInternalStructures();

    clang::ento::AnalysisManager &getAnalysisManager() const { return mgr; }

    utils::AliasResolver getAliasResolver() const {
	return aliasResolver;
    }
#if 0
    QList<Unit> getUnits() const {
        return units;
    }
#endif
    QSet<clang::CFG *> getStartFunctions() const {
	if (startFunctions.empty())
	    const_cast<LazyInternalStructures *>(this)->setStartFunctions();
	return startFunctions;
    }
#if 0
    QSet<const CFG *> getFunctionsOfName(const QString name) {
	QSet<const CFG *> result;
        for (const Unit unit : getUnits()) {
	    auto cfg = unit.getCFG(name);
	    if (cfg != nullptr)
		result.insert(cfg);
	}
        return result;
    }
    const clang::CFG *getFunctionMain() {
	const auto mains = getFunctionsOfName("main");
        assert(mains.size() == 1);
	return *mains.begin();
    }
#endif
    clang::CallGraph *getCallGraph() const {
	if (callGraph == nullptr)
	    const_cast<LazyInternalStructures *>(this)->setCallGraph();
	return callGraph;
    }
#if 0
    ArgumentPassingManager getArgumentPassingManager() {
        if (argumentPassingManager == null)
            setArgumentPassingManager();
        return argumentPassingManager;
    }

    ReturnValuePassingManager getReturnValuePassingManager() {
        if (returnValuePassingManager == null)
            setReturnValuePassingManager();
        return returnValuePassingManager;
    }

    CFGsNavigator getNavigator() {
        if (navigator == null)
            setNavigator();
        return navigator;
    }
#endif
#if 0
    QMap<CFGNode,CFGHandle> getNodeToCFGdictionary() {
#if 0
        if (nodeToCFGdictionary == null)
            setNodeToCFGdictionary();
#endif
	return nodeToCFGdictionary;
    }
#endif

    QList<clang::CFG *> getCFGs() const;
#if 0
    ElementCFGdictionary getElementToCFGdictionary() {
        if (elementToCFGdictionary == null)
            setElementToCFGdictionary();
        return elementToCFGdictionary;
    }
#endif
//    public synchronized void clearStartFunctions() { startFunctions = null; }
//    public synchronized void clearCallGraph() { callGraph = null; }
//    public synchronized void clearArgumentPassingManager() { argumentPassingManager = null; }
//    public synchronized void clearNavigator() { navigator = null; }
//    public synchronized void clearNodeToCFGdictionary() { nodeToCFGdictionary = null; }
//    public synchronized void clearCFGtoUnitDictionary() { cfgToUnitDictionary = null; }
//    public synchronized void clearElementToCFGdictionary() { elementToCFGdictionary = null; }
//
//    public synchronized void clear() {
//        clearStartFunctions();
//        clearCallGraph();
//        clearArgumentPassingManager();
//        clearNavigator();
//        clearNodeToCFGdictionary();
//        clearCFGtoUnitDictionary();
//        clearElementToCFGdictionary();
//    }

private:

    void setStartFunctions() {
	if (startFunctions.empty())
	    startFunctions = StartFunctionsSetBuilder::run(*this, *getCallGraph());
    }

    void setCallGraph();

    void setArgumentPassingManager() {
#if 0
	if (argumentPassingManager == null)
            argumentPassingManager = new ArgumentPassingManager(getNavigator(),
                                                      getNodeToCFGdictionary());
#else
	assert(false); abort();
#endif
    }

    void setReturnValuePassingManager() {
#if 0
	if (returnValuePassingManager == null)
            returnValuePassingManager =
                new ReturnValuePassingManager(getNavigator());
#else
	assert(false); abort();
#endif
    }

    virtual void setNavigator() = 0;

    void setNodeToCFGdictionary() {
#if 0
	if (nodeToCFGdictionary == null)
            nodeToCFGdictionary = Collections.unmodifiableMap(
                                     NodeToCFGdictionaryBuilder.run(getCFGHandles()));
#else
	assert(false); abort();
#endif
    }

    void setElementToCFGdictionary() {
#if 0
	if (elementToCFGdictionary == null)
            elementToCFGdictionary = new ElementCFGdictionary(getCFGHandles());
#else
	assert(false); abort();
#endif
    }

    clang::ento::AnalysisManager &mgr;
    const clang::TranslationUnitDecl *TU;
    const QList<clang::CFG *> cfgs;
    const utils::AliasResolver aliasResolver;

    QSet<clang::CFG *> startFunctions;
    clang::CallGraph *callGraph;
    //ArgumentPassingManager argumentPassingManager;
    //ReturnValuePassingManager returnValuePassingManager;
    //QMap<CFGNode,CFGHandle> nodeToCFGdictionary;
    //ElementCFGdictionary elementToCFGdictionary;

//protected:
    //CFGsNavigator navigator;
};

}

#endif
