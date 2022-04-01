#ifndef CHECKERCONFIGURATION_H
#define CHECKERCONFIGURATION_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <memory>

#include <QString>
#include <QStringList>

namespace checker {
class Checker;
}

namespace core {

class CheckerConfiguration final {
public:
#ifdef NEEDED
    CheckerConfiguration(const QString &checkerClassName,
			 const QString &checkerArgument,
			 const bool &interprocedural) :
	    checkerClassName(checkerClassName), interprocedural(interprocedural) {
        checkerArgumentsList.add(checkerArgument);
    }
#endif

    CheckerConfiguration(const QString &checkerClassName,
			 const QStringList &checkerArgumentsList = {},
			 const bool &interprocedural = false) :
	    checkerClassName(checkerClassName),
	    checkerArgumentsList(checkerArgumentsList),
	    interprocedural(interprocedural) { }

    std::unique_ptr<checker::Checker> getChecker();

    QString getCheckerClassName() const { return checkerClassName; }
    QStringList getCheckerArgumentsList() const { return checkerArgumentsList; }
    bool isInterprocedural() const { return interprocedural; }

private:
    QString checkerClassName;
    QStringList checkerArgumentsList;
    bool interprocedural;
};

}

#endif
