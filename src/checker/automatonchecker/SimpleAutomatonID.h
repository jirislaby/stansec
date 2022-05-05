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

namespace utils {
class XMLPatternVariablesAssignment;
}

namespace checker {

class SimpleAutomatonID final {
public:
    // package-private section

    SimpleAutomatonID(const utils::XMLPatternVariablesAssignment &assignment,
		      const bool isGlobal);

    SimpleAutomatonID(const QStringList &varsAssignment, const bool isGlobal) :
	    varsAssignment(varsAssignment), _isGlobal(isGlobal) {}

    const QStringList getVarsAssignment() const { return varsAssignment; }

    bool isGlobal() const { return _isGlobal; }

    QString toString() const;

private:
    static QStringList
    buildVarsCollection(const utils::XMLPatternVariablesAssignment &varsAssignment);

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

QDebug operator<<(QDebug d, const SimpleAutomatonID &item);

}

#endif
