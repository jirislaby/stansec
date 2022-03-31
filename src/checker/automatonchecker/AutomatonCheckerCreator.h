#ifndef AUTOMATONCHECKERCREATOR_H
#define AUTOMATONCHECKERCREATOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QString>

#include "../Checker.h"
#include "../CheckerCreator.h"

#include "AutomatonChecker.h"

namespace checker {

class AutomatonCheckerCreator : public CheckerCreator {
public:
	AutomatonCheckerCreator(const QList<QFile *> &args) : xmlFile(*args[0]) {

	}

	QString getCheckerName() const override {
	    return getNameForCheckerFactory();
	}

	QString getCheckerCreationInfo() const override {
	    return "   AutomatonChecker is a static checker which is able to "
	       "detect locking problems, interrupts enabling/disabling "
	       "problems, unnecessary check optimizations and points-to "
	       "problems like null pointer dereference and memory leaks. \n"
	       "   The checker is based on execution of finite automata "
	       "specified in XML file whose states are propagated through "
	       "program locations. Some automata states are considered as "
	       "erroneous, so when automaton's transition to such erroneous "
	       "state is invoked in some program location, then appropriate "
	       "error message is reported. Program locations, which are "
	       "considered for automata state propagation are found by "
	       "pattern matching. These pattern are specified in the XML "
	       "file defining automata as well. \n"
	       "   For more info see Stanse documentation. You can also "
	       "have a look to AutomatonChecker XML data files, which are "
               "distributed with Stanse as well.";
	}

	QList<QString> getDataFilesExtensions() const override {
	    QList<QString> result({"xml"});
	    return result;
	}

    virtual bool checkArgumentList(const QList<QFile *> &args) const override {
	return args.size() == 1 &&
	       args[0]->fileName().endsWith(".xml", Qt::CaseInsensitive);
    }

    virtual std::unique_ptr<Checker> createIntraprocedural(const clang::TranslationUnitDecl *TU) override {
	return std::make_unique<AutomatonChecker>(xmlFile);
    }

    virtual std::unique_ptr<Checker> createInterprocedural(const clang::TranslationUnitDecl *TU) override {
	return std::make_unique<AutomatonChecker>(xmlFile);
    }

    static QString getNameForCheckerFactory() {
	return "AutomatonChecker";
    }
private:
    QFile &xmlFile;
};

}

#endif
