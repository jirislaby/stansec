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

#include "../utils/AliasResolver.h"

#include "CFGHandle.h"
#include "CFGNode.h"

namespace clang {
class CallGraph;
class CFG;
class TranslationUnitDecl;
namespace ento { class AnalysisManager; }
}

namespace codestructs {

class ArgumentPassingManager;
class CFGsNavigator;

class LazyInternalStructures {
public:
    using NodeToCFGDictionary = QMap<CFGNode, CFGHandle>;
    using StartFunctions = QSet<codestructs::CFGHandle>;

    LazyInternalStructures(clang::ento::AnalysisManager &mgr,
			   const clang::TranslationUnitDecl *TU) : mgr(mgr),
	    TU(TU), callGraph(nullptr), argumentPassingManager(nullptr),
	    navigator(nullptr) {
#if 0
	for (auto unit : units) {
	    if (unit.getAliases() != null)
		this.aliasResolver.addAliasMapping(unit.getAliases());
	}

	startFunctions = null;
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
    const StartFunctions getStartFunctions() const {
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

    codestructs::ArgumentPassingManager &getArgumentPassingManager() const {
	if (argumentPassingManager == nullptr)
	    const_cast<LazyInternalStructures *>(this)->setArgumentPassingManager();
	return *argumentPassingManager;
    }
#if 0
    ReturnValuePassingManager getReturnValuePassingManager() {
        if (returnValuePassingManager == null)
            setReturnValuePassingManager();
        return returnValuePassingManager;
    }
#endif
    CFGsNavigator &getNavigator() const {
	if (navigator == nullptr)
	    const_cast<LazyInternalStructures *>(this)->setNavigator();
	return *navigator;
    }

    const NodeToCFGDictionary &getNodeToCFGdictionary() const {
	if (nodeToCFGdictionary.empty())
	    const_cast<LazyInternalStructures *>(this)->setNodeToCFGdictionary();
	return nodeToCFGdictionary;
    }

    QList<codestructs::CFGHandle> getCFGHandles() const;
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

    void setStartFunctions();
    void setCallGraph();
    void setArgumentPassingManager();
    void setReturnValuePassingManager();
    virtual void setNavigator() = 0;
    void setNodeToCFGdictionary();
    void setElementToCFGdictionary();

    clang::ento::AnalysisManager &mgr;
    const clang::TranslationUnitDecl *TU;
    const QList<codestructs::CFGHandle> cfgs;
    const utils::AliasResolver aliasResolver;

    StartFunctions startFunctions;
    clang::CallGraph *callGraph;
    codestructs::ArgumentPassingManager *argumentPassingManager;
    //ReturnValuePassingManager returnValuePassingManager;
    NodeToCFGDictionary nodeToCFGdictionary;
    //ElementCFGdictionary elementToCFGdictionary;

protected:
    CFGsNavigator *navigator;
};

}

#endif
