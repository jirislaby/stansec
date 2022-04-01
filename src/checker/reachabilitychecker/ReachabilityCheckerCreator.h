#ifndef REACHABILITYCHECKERCREATOR_H
#define REACHABILITYCHECKERCREATOR_H

/**
 * @brief ReachabilityChecker factory
 *
 * Copyright (c) 2009-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QFile>
#include <QString>
#include <QStringList>

#include "../Checker.h"
#include "../CheckerCreator.h"
//#include "CheckerException.h"

#include "ReachabilityChecker.h"

namespace checker {

class ReachabilityCheckerCreator : public CheckerCreator {

public:

    virtual QString getCheckerName() const override {
        return getNameForCheckerFactory();
    }

    virtual QString getCheckerCreationInfo() const override {
	return "   ReachabilityChecker is a static checker which is able to "
               "detect unreachable code.";
    }

    virtual std::unique_ptr<Checker>
    createIntraprocedural(const QStringList &args) override {
	return std::make_unique<ReachabilityChecker>();
    }

    virtual std::unique_ptr<Checker>
    createInterprocedural(const QStringList &args) override {
	return createIntraprocedural(args);
    }

    virtual QStringList getDataFilesExtensions() const override {
	assert(0 && "Reachability Checker needs no data");
	abort();
    }

    virtual bool checkArgumentList(const QStringList &args) const override {
        return args.size() == 0;
    }

    // package-private section

    static QString getNameForCheckerFactory() {
        return "ReachabilityChecker";
    }
};

}

#endif
