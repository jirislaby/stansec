#ifndef CHECKERERROR_H
#define CHECKERERROR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

/**
 *  @brief Defines public class CheckerError. It represents the error
 *         found in source program (represented by set of CFGs).
 *
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QString>

#include "../codestructures/LazyInternalStructures.h"

#include "CheckerErrorTrace.h"

namespace clang {
class Stmt;
}

namespace checker {

/**
 * @brief Represents output from checkers, which is the error found in the
 *        source file (represented by a set of CFGs).
 *
 * A found error is described by short and full string descriptions, level of
 * error importance and by a list of error-traces. Each checker is under
 * obligation to report all its errors via instances of this class.
 *
 * @see cz.muni.stanse.checker#Checker
 *      cz.muni.stanse.checker#CheckerErrorTrace
 */
class CheckerError /*: public Comparable<CheckerError>*/ {

public:

    CheckerError(const QString shortDesc, const QString fullDesc,
		 const int importance, const QString checkerName,
		 const QList<CheckerErrorTrace> traces) :
	shortDesc(shortDesc), fullDesc(fullDesc), importance(importance),
	checkerName(checkerName), traces(traces) {}

    CheckerError(const QString shortDesc, const QString fullDesc,
		 const int importance, const QString checkerName,
		 const QList<const clang::Stmt *> &trace,
		 const QString startMsg,
		 const QString innerMsg, const QString endMsg,
		 const codestructs::LazyInternalStructures &internals) :
	shortDesc(shortDesc), fullDesc(fullDesc), importance(importance),
	checkerName(checkerName),
	traces({ CheckerErrorTrace(trace, startMsg, innerMsg, endMsg, internals) }) {}

#if 0
    @Override
    bool equals(Object obj) {
	return (obj == null || getClass() != obj.getClass()) ?
		    false : isEqualWith((CheckerError)obj);
    }

#endif
    QString toString() const;

    void dump() const;

#if 0
    Element xmlDump() {
	Element result = DocumentFactory.getInstance().createElement("error");
	result.addElement("short_desc").addText(getShortDesc());
	result.addElement("full_desc").addText(getFullDesc());
	result.addElement("importance").addText(
		    Integer.toString(getImportance()));
	result.addElement("checker_name").addText(getCheckerName());
	Element eTraces = result.addElement("traces").addText(getCheckerName());

	for (const CheckerErrorTrace trace: getTraces())
	    eTraces.add(trace.xmlDump());
	return result;
    }
#endif
#if 0
    @Override
    int compareTo(CheckerError other) {
        return getImportance() - other.getImportance();
    }
#endif
    CheckerErrorTraceLocation getCauseLocation() const {
	return getTraces()[0].getCauseLocation();
    }

    CheckerErrorTraceLocation getErrorLocation() const {
	return getTraces()[0].getErrorLocation();
    }
#if 0
    bool isEqualWith(const CheckerError other) {
        return getShortDesc().equals(other.getShortDesc()) &&
               getFullDesc().equals(other.getFullDesc()) &&
               getImportance() == other.getImportance() &&
               getCheckerName().equals(other.getCheckerName()) &&
               getTraces().equals(other.getTraces());
    }
#endif
    QString getShortDesc() const {
        return shortDesc;
    }

    QString getFullDesc() const {
        return fullDesc;
    }

    int getImportance() const {
        return importance;
    }

    QString getCheckerName() const {
        return checkerName;
    }

    QList<CheckerErrorTrace> getTraces() const {
	return traces;
    }

private:

    QString shortDesc;
    QString fullDesc;
    int importance;
    QString checkerName;
    QList<CheckerErrorTrace> traces;
};

}

#endif
