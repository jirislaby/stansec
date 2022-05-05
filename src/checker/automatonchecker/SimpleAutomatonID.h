#ifndef SIMPLEAUTOMATONID_H
#define SIMPLEAUTOMATONID_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QString>
#include <QStringList>

#include "../../codestructures/PassingSolver.h"

namespace utils {
class XMLPatternVariablesAssignment;
}

namespace checker {

class SimpleAutomatonID final {
public:
#if 0
    public bool equals(Object obj) {
        return (obj == null || getClass() != obj.getClass()) ?
                false : isEqualWith((SimpleAutomatonID)obj);
    }
#endif

    // package-private section

    SimpleAutomatonID(const utils::XMLPatternVariablesAssignment &assignment,
		      const bool isGlobal) :
	varsAssignment(buildVarsCollection(assignment)), _isGlobal(isGlobal) {}

    SimpleAutomatonID(const QStringList &varsAssignment, const bool isGlobal) :
	    varsAssignment(varsAssignment), _isGlobal(isGlobal) {}

    const QStringList getVarsAssignment() const { return varsAssignment; }

    bool isGlobal() const { return _isGlobal; }

    QString toString() const {
	QString result;
	if (isGlobal())
		result.append('G');
	result.append(getVarsAssignment().join(','));
	return result;
    }

#if 0
    bool isEqualWith(const SimpleAutomatonID other) {
        return getVarsAssignment().equals(other.getVarsAssignment());
    }
#endif

private:

    static QStringList
    buildVarsCollection(const utils::XMLPatternVariablesAssignment &varsAssignment) {
	return codestructs::PassingSolver::makeArgumentList(varsAssignment);
    }

    QStringList varsAssignment;
    bool _isGlobal;
};

inline bool operator==(const SimpleAutomatonID &lhs,
		       const SimpleAutomatonID &rhs)
{
	return lhs.isGlobal() == rhs.isGlobal() &&
			lhs.getVarsAssignment() == rhs.getVarsAssignment();
}

inline bool operator!=(const SimpleAutomatonID &lhs,
		       const SimpleAutomatonID &rhs)
{
	return !(lhs == rhs);
}

inline bool operator<(const SimpleAutomatonID &lhs,
		      const SimpleAutomatonID &rhs)
{
	return lhs.isGlobal() < rhs.isGlobal() &&
			lhs.getVarsAssignment() < rhs.getVarsAssignment();
}

inline uint qHash(const SimpleAutomatonID &item)
{
	return (qHash(item.getVarsAssignment()) << 1) + item.isGlobal();
}

inline uint qHash(const SimpleAutomatonID &item, uint seed)
{
	return (qHash(item.getVarsAssignment(), seed) << 1) + item.isGlobal();
}

inline QDebug operator<<(QDebug d, const SimpleAutomatonID &item)
{
	if (item.isGlobal())
		d << 'G';
	else
		d << 'L';
	d << item.getVarsAssignment();
	return d;
}

}

#endif
