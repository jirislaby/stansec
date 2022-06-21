#ifndef SIMPLEAUTOMATONID_H
#define SIMPLEAUTOMATONID_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QList>
#include <QString>

namespace clang {
class Expr;
class LangOptions;
}

namespace utils {
class XMLPatternVariablesAssignment;
}

namespace checker {

class SimpleAutomatonID final {
public:
    using VarsAssignment = QList<const clang::Expr *>;
    // package-private section

    SimpleAutomatonID(const utils::XMLPatternVariablesAssignment &assignment,
		      const bool isGlobal);

    SimpleAutomatonID(const VarsAssignment &varsAssignment, const bool isGlobal) :
	    varsAssignment(varsAssignment), _isGlobal(isGlobal) {}

    const VarsAssignment getVarsAssignment() const { return varsAssignment; }

    bool isGlobal() const { return _isGlobal; }

    QString toString(const clang::LangOptions &LO) const;

private:
    static VarsAssignment
    buildVarsCollection(const utils::XMLPatternVariablesAssignment &varsAssignment);

    VarsAssignment varsAssignment;
    bool _isGlobal;
};

bool operator==(const SimpleAutomatonID &lhs,
		const SimpleAutomatonID &rhs);

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
	// clang::Expr can vary, but still point to the same DeclRef
	// So depend only on isGlobal for now.
	//return (qHash(item.getVarsAssignment()) << 1) + item.isGlobal();
	return item.isGlobal();
}

inline uint qHash(const SimpleAutomatonID &item, uint seed)
{
	return item.isGlobal();
	//return (qHash(item.getVarsAssignment(), seed) << 1) + item.isGlobal();
}

QDebug operator<<(QDebug d, const SimpleAutomatonID &item);

}

#endif
