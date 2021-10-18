#ifndef CHECKERCREATOR_H
#define CHECKERCREATOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <memory>

#include <QFile>
#include <QList>
#include <QString>

#include "Checker.h"

namespace clang {
class TranslationUnitDecl;
}

namespace checker {

class CheckerCreator {
public:
    CheckerCreator() {}

    virtual QString getCheckerName() = 0;
    virtual QString getCheckerCreationInfo() = 0;
    virtual QList<QString> getDataFilesExtensions() = 0;
    virtual bool checkArgumentList(const QList<QFile *> &args) = 0;
    virtual std::unique_ptr<Checker> createInterprocedural(const clang::TranslationUnitDecl *TU) = 0;
    //throws CheckerException;
    virtual std::unique_ptr<Checker> createIntraprocedural(const clang::TranslationUnitDecl *TU) = 0;
    //throws CheckerException;
};

}

#endif
