/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <clang/Basic/SourceManager.h>

#include <clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h>

#include <QDebug>
#include <QString>
#include <QVector>

#include "../codestructures/LazyInternalStructures.h"

#include "CheckerErrorTrace.h"

using namespace checker;

//#include "LinearCode.h"

void CheckerErrorTrace::dump() const
{
	qDebug().noquote().nospace() << toString();
	for (const auto &location : getLocations())
	    qDebug().noquote().nospace() << location.toString();
}

#if 0
    public Element xmlDump() {
	Element result = DocumentFactory.getInstance().createElement("trace");
	result.addElement("description").addText(getDescription());
	Element locs = result.addElement("locations");
	for (const CheckerErrorTraceLocation location: getLocations())
	    locs.add(location.xmlDump());
        return result;
    }
#endif

QList<CheckerErrorTraceLocation>
CheckerErrorTrace::buildLocations(const QList<const clang::Stmt *> &trace,
				  const QString startMsg,
				  const QString innerMsg,
				  const QString endMsg,
				  const codestructs::LazyInternalStructures &internals)
{
    assert(!trace.isEmpty());

    QList<CheckerErrorTraceLocation> result;
#if 0
    // Filter out nodes that don't have an associated location.
    QList<CFGNode> filteredTrace;
    for (CFGNode node : trace) {
	if (node.hasLocation())
	    filteredTrace.add(node);
    }
    trace = filteredTrace;
#endif

    auto &SM = internals.getAnalysisManager().getSourceManager();
    result.append(CheckerErrorTraceLocation(getPLoc(SM, trace.first()), startMsg));

    for (auto node : trace.mid(1, trace.size() - 1)) {
	//if (!node.getElement().getName().equals("assert"))
	result.append(CheckerErrorTraceLocation(getPLoc(SM, node), innerMsg));
    }

    result.append(CheckerErrorTraceLocation(getPLoc(SM, trace.last()), endMsg));

    return result;
}

clang::PresumedLoc CheckerErrorTrace::getPLoc(const clang::SourceManager &SM,
					      const clang::Stmt *stmt) {
	return SM.getPresumedLoc(stmt->getBeginLoc());
}
