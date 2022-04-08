/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby
 *
 * Licensed under GPLv2.
 */

#include <clang/AST/Stmt.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h>

#include <QList>
#include <QPair>
#include <QStack>
#include <QString>

#include "../../codestructures/traversal/CFGTraversal.h"
#include "../../codestructures/LazyInternalStructures.h"
#include "../CheckingSuccess.h"
#include "../CheckerErrorReceiver.h"

#include "AutomatonCheckerLogger.h"
#include "AutomatonStateCFGcontextAlgo.h"
#include "AutomatonStateTransferManager.h"
#include "CallSiteCFGNavigator.h"
#include "CallSiteDetector.h"
#include "CheckerErrorBuilder.h"
#include "ErrorTracesListCreator.h"
#include "NodeLocationDictionary.h"
#include "PatternLocation.h"

using namespace checker;

CheckingResult CheckerErrorBuilder::buildErrorList(const NodeLocationDictionary &NLD,
						   const codestructs::LazyInternalStructures &internals,
						   void *detectors,
						   CheckerErrorReceiver &errReceiver,
						   AutomatonCheckerLogger &monitor,
						   const QString &automatonName)
{
	const CheckingResult *result = nullptr;
	int numErrors = 0;
#ifdef TIME
	const TimeManager tmgr = new TimeManager();
	tmgr.measureStart();
#endif
	for (const auto &stmts : NLD.values())
		for (const auto &stmt : stmts) {
			const auto &locationsPair = stmt.second;
#ifdef TIME
			if (tmgr.measureElapsedMs() > 60000L)
			    return result;
#endif
			if (locationsPair.first != nullptr) {
			    const auto locBuildResult =
				    buildErrorsInLocation(*locationsPair.first, NLD, internals,
							  detectors, errReceiver, monitor,
							  automatonName);
			    numErrors += locBuildResult.first;
			    if (dynamic_cast<const CheckingSuccess *>(result))
				result = &locBuildResult.second;
			}
		}
	if (numErrors > 0)
	    monitor.note("*** " + QString::number(numErrors) + " error(s) found");

	return result ? *result : CheckingResult();
}

class CFGPathVisitor {
public:
	CFGPathVisitor(codestructs::CFGPathVisitor &visitor) : visitor(visitor) {}

	void visitBlkReverse(codestructs::CFGPathVisitor::Path &path,
			     const clang::CFGBlock &blk) {
	    visitBlkReverse(path, blk, blk.rref_begin());
	}

	void visitBlkReverse(codestructs::CFGPathVisitor::Path &path,
			     const clang::CFGBlock &blk,
			     const clang::CFGBlock::const_reverse_ref_iterator &it);

	static void visitBlkReverse(codestructs::CFGPathVisitor &visitor,
				    const clang::CFGBlock &blk) {
		CFGPathVisitor v(visitor);
		codestructs::CFGPathVisitor::Path path;
		path.append(codestructs::CFGNode(&blk));
		v.visitBlkReverse(path, blk);
	}
private:
	using VisitedSet = QSet<const clang::CFGBlock *>;
	VisitedSet visited;
	codestructs::CFGPathVisitor &visitor;
};

void CFGPathVisitor::visitBlkReverse(codestructs::CFGPathVisitor::Path &path,
				     const clang::CFGBlock &blk,
				     const clang::CFGBlock::const_reverse_ref_iterator &it)
{
	codestructs::CFGPathVisitor::CallStack stack;

	if (visited.contains(&blk)) {
		visitor.onEndPath(path, stack);
		return;
	}
	visited.insert(&blk);

	visitor.visit(path, stack);

	qDebug() << __func__ << "====";
	blk.dump();
	qDebug() << "----";
	for (auto i = it; i != blk.rref_end(); ++i) {
	    llvm::errs() << "  ";
	    (*i).dump();
	    auto cfgStmt = **i;
	    if (cfgStmt.getKind() == clang::CFGElement::Statement) {
		    path.prepend(codestructs::CFGNode(&blk, (*i).getIndexInBlock()));
		    visitor.visit(path, stack);
	    }
	}
	qDebug() << __func__ << "==== END";
	path.prepend(codestructs::CFGNode(&blk));
	for (auto pred : blk.preds())
	    visitBlkReverse(path, *pred);
	path.removeFirst();
}

QPair<int, CheckingResult>
CheckerErrorBuilder::buildErrorsInLocation(PatternLocation &location,
					   const NodeLocationDictionary &NLD,
					   const codestructs::LazyInternalStructures &internals,
					   void *detectors,
					   CheckerErrorReceiver &errReceiver,
					   AutomatonCheckerLogger &monitor,
					   const QString &automatonName)
{
    const CallSiteDetector callDetector(internals.getNavigator(), NLD);
    const AutomatonStateTransferManager transferor(internals.getArgumentPassingManager(),
						   callDetector);
    const CallSiteCFGNavigator callNavigator(internals.getNavigator(),
					     callDetector);

    //qDebug() << __func__ << location.toString();

    if (location.getProcessedAutomataStates().size() > 100 ||
	    location.getDeliveredAutomataStates().size() > 100)
	location.reduceStateSets();

    CheckingResult result = CheckingSuccess();
    int numErrors = 0;
#ifdef TIME
    const TimeManager tmgr = new TimeManager();
    tmgr.measureStart();
#endif
    for (const auto &rule : location.getErrorRules()) {
	    /*qDebug() << "  err" << rule.getErrorDescription() << rule.getAutomatonID();
	    for (auto &s : location.getProcessedAutomataStates()) {
		qDebug() << "    state" << s;
	    }*/

	for (const auto &cfgContext : AutomatonStateCFGcontextAlgo::getContexts(
		 location.getProcessedAutomataStates())) {
#ifdef TIME
	    if (tmgr.measureElapsedMs() > 10000L)
		return QPair.make(numErrors,result);
#endif
	    //qDebug() << "    " << cfgContext;

	    if (!rule.checkForError(AutomatonStateCFGcontextAlgo::filterStatesByContext(
					    location.getProcessedAutomataStates(),
					    cfgContext)))
		    continue;

	    ErrorTracesListCreator creator(rule, transferor, NLD,
					   location.getCFGreferenceNode(),
					   internals, detectors, monitor);

	    qWarning() << "error" << rule.getErrorDescription() << "at:";
	    auto &refNode = location.getCFGreferenceNode();
	    auto &dict = internals.getNodeToCFGdictionary();
	    auto it = dict.find(refNode);
	    assert(it != dict.end());
	    auto &SM = internals.getAnalysisManager().getSourceManager();
	    const clang::CFGBlock *blk = refNode.getBlock();
	    size_t idx = -1;
	    if (auto stmt = refNode.getStmt()) {
		    stmt->getBeginLoc().dump(SM);
		    idx = refNode.getBlockIdx();
	    } else {
		    auto &dict = internals.getNodeToCFGdictionary();
		    auto it = dict.find(refNode);
		    assert(it != dict.end());
		    auto &cfg = *it;
		    auto loc = (blk == &cfg.getCFG()->getExit()) ?
			    cfg.getFD()->getEndLoc() :
			    cfg.getFD()->getBeginLoc();
		    qDebug() << "block" << blk->getBlockID();
		    loc.dump(SM);
		    idx = blk->size() - 1;
	    }
	    Q_UNUSED(idx);

	    CFGPathVisitor::visitBlkReverse(creator, *blk);
#ifdef OLD
	    codestructs::CFGTraversal::traverseCFGPathsBackwardInterprocedural(
			callNavigator, location.getCFGreferenceNode(),
			creator, cfgContext);
#endif

	    const auto traces = creator.getErrorTracesList();
	    qWarning() << traces;

#if 0
	    if (result instanceof CheckingSuccess &&
		    creator.getFailMessage() != nullptr)
		result = new CheckingFailed(creator.getFailMessage(),
					    getLocationUnitName(location,internals));

	    // Next condition eliminates cyclic dependances of two
	    // (different) error locations. These locations have same
	    // error rule and their checkForError() methods return
	    // true (so  they are both error locations). But their
	    // cyclic dependency disallows to find starting nodes of
	    // their error traces -> both error traces returned will
	    // be empty.
	    if (traces.isEmpty())
		continue;

	    int min_size = INT_MAX;
	    CheckerErrorTrace min_trace = nullptr;
	    for (const CheckerErrorTrace trace : traces) {
		if (trace.getLocations().size() >= min_size)
		    continue;
		min_size = trace.getLocations().size();
		min_trace = trace;
	    }

	    const auto shortDesc = rule.getErrorDescription();
	    QString fullDesc("{");
	    fullDesc.append(automatonName).append("} in function '").
		    append(internals.getNodeToCFGdictionary()[location.getCFGreferenceNode()]
		    .getFunctionName()).append("' ").
		    append(shortDesc).append(" [traces: ").
		    append(traces.size()).append(']');
	    errReceiver.receive(
			CheckerError(shortDesc, fullDesc,
				     rule.getErrorLevel() +
				     creator.getTotalImportance(),
				     automatonName,
				     Make.linkedList(min_trace)));
	    ++numErrors;
	    monitor.note("*** error found: " + shortDesc + " at line " +
			 location.getCFGreferenceNode().getLine());
#elif !defined(ABORT_ON_BUILDING_ERRORS)
	    qDebug() << __func__ << "unimplemented";
	    ++numErrors;
#else
	assert(0); abort();
#endif
	}
    }

    return qMakePair(numErrors, result);
}

#if 0
    private static QString getNodeUnitName(const CFGNode node,
                                       const LazyInternalStructures internals) {
        return Stanse.getUnitManager().getUnitName(
                    internals.getNodeToCFGdictionary().get(node));
    }

    private static QString getLocationUnitName(const PatternLocation location,
                                       const LazyInternalStructures internals) {
        return getNodeUnitName(location.getCFGreferenceNode(),internals);
    }

#endif
