/**
 * @brief ReachabilityChecker implementation
 *
 * Copyright (c) 2009-2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/Analysis/CFG.h>

#include <QString>

#include "../CheckingSuccess.h"
#include "ReachabilityChecker.h"
#include "ReachabilityCheckerCreator.h"

using namespace checker;
using namespace codestructs;

#if 0
QRegularExpression ReachabilityChecker::exprCompoundPattern("[eE]xpression.*\\bcompoundStatement\\b");
QRegularExpression ReachabilityChecker::retCompoundPattern("\\breturnStatement\\b.*\\bcompoundStatement\\b");
#endif

QString ReachabilityChecker::getName()
{
    return ReachabilityCheckerCreator::getNameForCheckerFactory();
}

/**
 * @brief Does the source code checking itself.
 *
 * Method searches through source code to find nodes (except start node)
 * with no predecessors.
 *
 * @return List of errors found in the source code.
 * @see cz.muni.stanse.checker.Checker#check(java.util.List)
 */
CheckingResult ReachabilityChecker::check(const LazyInternalStructures &internals,
					  CheckerErrorReceiver &errReceiver,
					  CheckerProgressMonitor &monitor)
{
    CheckingResult result = CheckingSuccess();
    monitor.write("Starting Reachability Checker");

    for (auto &cfgh: internals.getCFGHandles()) {
	auto cfg = cfgh.getCFG();
	auto start = &cfg->getEntry();
	auto end = &cfg->getExit();

	/* reverse_nodes() in clang >= 13 */
	for (auto it = cfg->rbegin(); it != cfg->rend(); ++it) {
	    auto node = *it;
	    if (node == start || node == end) {
		    continue;
	    }
	    if (!node->preds().empty())
		continue;
#if 0
	    if (!node.getOptPredecessors().isEmpty())
		continue;
#endif
#if 0
	    QString elemName = nodeElem.getName();
	    if (elemName.equals("intConst") &&
		    nodeElem.getText().equals("0"))
		continue;
#endif

	    int importance = 0;
	    QString fullDesc("The code is unreachable by any path.");
	    monitor.write("An error found");

	    if (isBreakOrReturn(node)) {
		importance += 3;
		fullDesc.append(" Superfluous break or return statement.");
	    }
#if 0
	    Element parentElem = nodeElem.getParent();
	    if (parentElem != null &&
		    parentElem.getName().equals("forStatement") &&
		    nodeElem.equals(parentElem.elements().get(2))) {
		importance += 5;
		fullDesc.append(" The third 'for' expression is never used.");
	    }
#endif
	    QList<const clang::Stmt *> trace;
	    buildTrace(trace, node);

	    auto nodeComm = "This node is unreachable";
	    errReceiver.receive(CheckerError("Unreachable code",
					     fullDesc, importance,
					     ReachabilityCheckerCreator::getNameForCheckerFactory(),
					     trace,
					     nodeComm, nodeComm, nodeComm,
					     internals));
	}
    }

    monitor.write("Reachability Checker finished");
    return result;
}

bool ReachabilityChecker::isBreakOrReturn(const clang::CFGBlock *node)
{
    if (node->empty()) {
	auto term = node->getTerminator();
	if (term.isValid() && term.isStmtBranch() &&
		llvm::isa<clang::BreakStmt>(term.getStmt()))
	    return true;
    } else if (node->size() <= 2) {
	if (auto ret = node->back().getAs<clang::CFGStmt>()) {
	    if (llvm::isa<clang::ReturnStmt>(ret->getStmt())) {
		if (node->size() == 1)
		    return true;

		if (auto f = node->front().getAs<clang::CFGStmt>())
		    if (llvm::isa<clang::IntegerLiteral>(f->getStmt()))
			return true;
	    }
	}
    }

    return false;
}

void ReachabilityChecker::buildTrace(QList<const clang::Stmt *> &trace,
				const clang::CFGBlock *node)
{
    for (const auto &entry : node->Elements) {
	if (auto S = entry.getAs<clang::CFGStmt>()) {
	    trace.append(S->getStmt());
	}
    }
    auto term = node->getTerminator();
    if (term.isValid())
	if (auto stmt = term.getStmt())
	    trace.append(stmt);
}
