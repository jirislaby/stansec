#ifndef REACHABILITYCHECKERCREATOR_H
#define REACHABILITYCHECKERCREATOR_H

/**
 * @brief ReachabilityChecker factory
 *
 * Copyright (c) 2009-2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QFile>
#include <QString>

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

    virtual std::unique_ptr<Checker> createIntraprocedural(const clang::TranslationUnitDecl *TU) override {
	return std::make_unique<ReachabilityChecker>();
    }

    virtual std::unique_ptr<Checker> createInterprocedural(const clang::TranslationUnitDecl *TU) override {
	return createIntraprocedural(TU);
    }

    virtual QList<QString> getDataFilesExtensions() const override {
	/*throw new UnsupportedOperationException("Reachability Checker needs no data");*/
	return QList<QString>();
    }

    virtual bool checkArgumentList(const QList<QFile *> &args) const override {
        return args.size() == 0;
    }

    // package-private section

    static QString getNameForCheckerFactory() {
        return "ReachabilityChecker";
    }
};

}

#endif
