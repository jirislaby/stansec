#ifndef ERRORTRACESLISTCREATOR_H
#define ERRORTRACESLISTCREATOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QString>

#include "../../codestructures/traversal/CFGPathVisitor.h"

#include "../CheckerErrorTrace.h"

#include "ErrorRule.h"
#include "FalsePositivesDetector.h"

namespace codestructs {
class LazyInternalStructures;
}

namespace checker {

class AutomatonCheckerLogger;
class AutomatonStateTransferManager;
class NodeLocationDictionary;

class ErrorTracesListCreator final : public codestructs::CFGPathVisitor {
    // package-private section
public:
    ErrorTracesListCreator(const ErrorRule &rule,
			   const AutomatonStateTransferManager &transferor,
			   const NodeLocationDictionary &NLD,
			   const codestructs::CFGNode &startNode,
			   const codestructs::LazyInternalStructures &internals,
			   /*const QList<FalsePositivesDetector>*/void *detectors,
			   AutomatonCheckerLogger &monitor) :
	rule(rule), transferor(transferor), NLD(NLD), startNode(startNode),
	internals(internals), detectors(detectors), monitor(monitor) {}

    //QList<CheckerErrorTrace> getErrorTracesList() const { return errorTracesList; }
    QList<CheckerErrorTrace> &getErrorTracesList() { return errorTracesList; }
    int getTotalImportance() const { return totalImportance; }
    QString getFailMessage() const { return failMsg; }

    virtual void onEndPath(const Path &path,
			 const CallStack &callStack) override;

    virtual bool visit(const Path &path,
		       const CallStack &cfgContext) override;

    virtual bool onCFGchange(const Stmt &from, const Stmt &to) override;

    AutomatonCheckerLogger &getMonitor() { return monitor; }

private:

    int getTraceImportance(const Path &path,
			   const CallStack &cfgContext);

    CheckerErrorTrace buildErrorTrace(const QString &beginMsg,
				      const QString &innerMsg,
				      const QString &endMsg,
				      const Path &path,
				      const CallStack &context);

    ErrorRule getRule() { return rule; }

    void updateRule(SimpleAutomatonID &id) {
	rule = ErrorRule(getRule(), id);
    }

    const NodeLocationDictionary &getNodeLocationDictionary() { return NLD; }

    codestructs::CFGNode getStartNode() { return startNode; }
    const AutomatonStateTransferManager &getTransferor() { return transferor; }
    const codestructs::LazyInternalStructures &getInternals() { return internals; }

    QString getNodeUnitName(const Stmt &node);

    void updateTotalImportance(const int traceImportance) {
	if (totalImportance <= traceImportance)
	    totalImportance = traceImportance;
    }

    bool isLimitOfRejectedMeasureExceeded() {
        return numRejectedMeasure > 1000;
    }

    void incrementNumRejectedMeasure(const int pathLen);

    void resetNumRejectedMeasure() {
        numRejectedMeasure = 0;
    }

    void setFailMessage(const QString &msg) {
        failMsg = msg;
    }

    ErrorRule rule;
    const AutomatonStateTransferManager &transferor;
    const NodeLocationDictionary &NLD;
    Stmt startNode;
    const codestructs::LazyInternalStructures &internals;
    QList<CheckerErrorTrace> errorTracesList;
    /*const QList<FalsePositivesDetector>*/void *detectors;
    AutomatonCheckerLogger &monitor;
    int totalImportance = FalsePositivesDetector::getBugDefaultImportance();
    QString failMsg;
    int numRejectedMeasure = 0;
};

}

#endif
