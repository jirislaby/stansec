#ifndef COMPOSEDAUTOMATONID_H
#define COMPOSEDAUTOMATONID_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QList>
#include <QString>

#include "SimpleAutomatonID.h"

namespace clang {
class LangOptions;
}
namespace checker {

class ComposedAutomatonID final {

public:
    // package-private section

    explicit ComposedAutomatonID(SimpleAutomatonID id) {
	getSimpleAutomataIDs().push_back(std::move(id));
    }

    explicit ComposedAutomatonID(const QList<SimpleAutomatonID> &ids) :
	    automataIDs(ids) { }

    const QList<SimpleAutomatonID> getSimpleAutomataIDs() const {
        return automataIDs;
    }

    QString toString(const clang::LangOptions &LO) const {
	    QStringList result;
	    for (const auto &s: getSimpleAutomataIDs())
		    result << s.toString(LO);
	    return result.join(", ");
    }

private:
    QList<SimpleAutomatonID> &getSimpleAutomataIDs() { return automataIDs; }

    QList<SimpleAutomatonID> automataIDs;
};

inline bool operator==(const ComposedAutomatonID &lhs,
		       const ComposedAutomatonID &rhs)
{
	return lhs.getSimpleAutomataIDs() == rhs.getSimpleAutomataIDs();
}

inline bool operator!=(const ComposedAutomatonID &lhs,
		       const ComposedAutomatonID &rhs)
{
	return !(lhs == rhs);
}

inline bool operator<(const ComposedAutomatonID &lhs,
		      const ComposedAutomatonID &rhs)
{
	return lhs.getSimpleAutomataIDs() < rhs.getSimpleAutomataIDs();
}

inline uint qHash(const ComposedAutomatonID &item, uint seed)
{
	return qHash(item.getSimpleAutomataIDs(), seed);
}

inline QDebug operator<<(QDebug d, const ComposedAutomatonID &a)
{
	d << "ComposedAutomatonID(";
	for (const auto &simple : a.getSimpleAutomataIDs())
		d << simple;
	d << ')';
	return d;
}

}

#endif
