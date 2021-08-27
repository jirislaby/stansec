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
class CFG;
class TranslationUnitDecl;
namespace ento { class AnalysisManager; }
}

namespace codestructs {

class LazyInternalStructures {
public:
    LazyInternalStructures(clang::ento::AnalysisManager &mgr,
			   const clang::TranslationUnitDecl *TU) : mgr(mgr),
	    TU(TU) {
#if 0
	for (auto unit : units) {
	    if (unit.getAliases() != null)
		this.aliasResolver.addAliasMapping(unit.getAliases());
	}

	startFunctions = null;
        callGraph = null;
        navigator = null;
        argumentPassingManager = null;
        returnValuePassingManager = null;
        nodeToCFGdictionary = null;
        elementToCFGdictionary = null;
#endif
    }

    clang::ento::AnalysisManager &getAnalysisManager() const { return mgr; }

    utils::AliasResolver getAliasResolver() const {
	return aliasResolver;
    }
#if 0
    QList<Unit> getUnits() const {
        return units;
    }
#endif
#if 0
    QSet<CFGHandle> getStartFunctions() {
	if (startFunctions.empty())
	    setStartFunctions();
	return startFunctions;
    }
#endif
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

#if 0
    utils::DirectedGraph<CFGHandle> getCallGraph() {
	//if (callGraph == null)
            setCallGraph();
        return callGraph;
    }
#endif

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
	assert(false);
#if 0
	if (startFunctions.empty())
	    startFunctions = StartFunctionsSetBuilder::run(getCallGraph());
#endif
    }

    void setCallGraph() {
#if 0
	if (callGraph == null)
            callGraph = CallGraphBuilder.run(getCFGHandles(),getNavigator(),
                                             getNodeToCFGdictionary());
#endif
    }

    void setArgumentPassingManager() {
#if 0
	if (argumentPassingManager == null)
            argumentPassingManager = new ArgumentPassingManager(getNavigator(),
                                                      getNodeToCFGdictionary());
#endif
    }

    void setReturnValuePassingManager() {
#if 0
	if (returnValuePassingManager == null)
            returnValuePassingManager =
                new ReturnValuePassingManager(getNavigator());
#endif
    }

    virtual void setNavigator() = 0;

    void setNodeToCFGdictionary() {
#if 0
	if (nodeToCFGdictionary == null)
            nodeToCFGdictionary = Collections.unmodifiableMap(
                                     NodeToCFGdictionaryBuilder.run(getCFGHandles()));
#endif
    }

    void setElementToCFGdictionary() {
#if 0
	if (elementToCFGdictionary == null)
            elementToCFGdictionary = new ElementCFGdictionary(getCFGHandles());
#endif
    }

    clang::ento::AnalysisManager &mgr;
    const clang::TranslationUnitDecl *TU;
    const QList<clang::CFG *> cfgs;
    const utils::AliasResolver aliasResolver;

    //QSet<CFGHandle> startFunctions;
    //utils::DirectedGraph<CFGHandle> callGraph;
    //ArgumentPassingManager argumentPassingManager;
    //ReturnValuePassingManager returnValuePassingManager;
    //QMap<CFGNode,CFGHandle> nodeToCFGdictionary;
    //ElementCFGdictionary elementToCFGdictionary;

//protected:
    //CFGsNavigator navigator;
};

}

#endif
