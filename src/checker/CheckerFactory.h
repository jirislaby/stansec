#ifndef CHECKERFACTORY_H
#define CHECKERFACTORY_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QMap>
#include <QString>
#include <QStringList>

#include "CheckerCreator.h"

namespace checker {
class Checker;

class CheckerFactory final {
public:
    static std::unique_ptr<Checker>
    createInterprocedural(const QString &checkerName, const QStringList &args)
		/*throws UnsupportedOperationException, CheckerException*/ {
	auto chC = getCheckerCreator(checkerName);
	return chC ? chC->createInterprocedural(args) : nullptr;
    }

    static std::unique_ptr<Checker>
    createIntraprocedural(const QString &checkerName, const QStringList &args)
		/*throws UnsupportedOperationException, CheckerException*/ {
	auto chC = getCheckerCreator(checkerName);
	return chC ? chC->createIntraprocedural(args) : nullptr;
    }

    static QString getCheckerCreationInfo(const QString &checkerName)
		/*throws UnsupportedOperationException*/ {
	auto chC = getCheckerCreator(checkerName);
	return chC ? chC->getCheckerCreationInfo() : QString();
    }

    static QStringList getDataFilesExtensions(const QString &checkerName)
    /*throws UnsupportedOperationException*/ {
	auto chC = getCheckerCreator(checkerName);
	return chC ? chC->getDataFilesExtensions() : QStringList();
    }

    static bool checkArgumentList(const QString &checkerName,
				  const QStringList &args)
    /*throws UnsupportedOperationException*/ {
	auto chC = getCheckerCreator(checkerName);
	return chC ? chC->checkArgumentList(args) : false;
    }

    static const QStringList getRegisteredCheckers() {
	return creatorsDictionary.keys();
    }

private:
    using CreatorMap = QMap<QString, CheckerCreator *>;

    CheckerFactory() = delete;

    static CheckerCreator *getCheckerCreator(const QString &checkerName)
		/*throws UnsupportedOperationException*/ {
	//auto creator = creatorsDictionary.find(checkerName);
	    /*throw new UnsupportedOperationException("Checker '" + checkerName +
			"' is not registered to the factory.");*/
	return creatorsDictionary[checkerName];
    }

    static std::pair<QString, CheckerCreator *>
    checkerCreatorPair(CheckerCreator *creator) {
	return std::make_pair(creator->getCheckerName(), creator);
    }

    static const CreatorMap creatorsDictionary;
};

}

#endif
