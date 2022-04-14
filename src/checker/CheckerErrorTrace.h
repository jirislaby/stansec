#ifndef CHECKERERRORTRACE_H
#define CHECKERERRORTRACE_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QList>
#include <QPair>
#include <QString>

#include "../codestructures/LazyInternalStructures.h"

#include "CheckerErrorTraceLocation.h"

//#include "LinearCode.h"

namespace clang {
class SourceManager;
class Stmt;
}

namespace checker {

class CheckerErrorTrace {

public:
    CheckerErrorTrace(const QList<CheckerErrorTraceLocation> locations,
		      const QString description) : locations(locations),
	    description(description) {}

    CheckerErrorTrace(const QList<const clang::Stmt *> &trace, const QString startMsg,
                             const QString innerMsg, const QString endMsg,
			     const codestructs::LazyInternalStructures &internals) :
	    locations(buildLocations(trace, startMsg, innerMsg, endMsg, internals)),
	    description("trace") {}

#if 0
    @Override
    bool equals(Object obj) {
        return (obj == null || getClass() != obj.getClass()) ?
                false : isEqualWith((CheckerErrorTrace)obj);
    }

#endif
    QString toString() const {
	return description + " [locations: " + QString::number(getLocations().size()) + "]";
    }

    void dump(QDebug output) const;
    void dump() const { dump(qDebug()); }
    //Element xmlDump() const;

    CheckerErrorTraceLocation getCauseLocation() {
	for (const auto &location : getLocations())
            if (!location.isContextLocation())
                return location;
	assert(0);
	abort();
    }

    CheckerErrorTraceLocation getErrorLocation() {
	return getLocations().last();
    }
#if 0
    bool isEqualWith(const CheckerErrorTrace other) {
        return getLocations().equals(other.getLocations()) &&
               getDescription().equals(other.getDescription());
    }
#endif
    QList<CheckerErrorTraceLocation> getLocations() const {
	return locations;
    }

    QString getDescription() {
        return description;
    }
#if 0
    LinearCode getLinearCode() {
	return linearCode;
    }

    void setLinearCode(const LinearCode lc) {
	linearCode = lc;
    }
#endif

private:
    static QList<CheckerErrorTraceLocation>
    buildLocations(const QList<const clang::Stmt *> &trace, const QString startMsg,
		   const QString innerMsg, const QString endMsg,
		   const codestructs::LazyInternalStructures &internals);

    static clang::PresumedLoc getPLoc(const clang::SourceManager &SM,
				      const clang::Stmt *stmt);

    QList<CheckerErrorTraceLocation> locations;
    QString description;
    //LinearCode linearCode = null;
};

}

QDebug operator<<(QDebug d, const checker::CheckerErrorTrace &item);

#endif
