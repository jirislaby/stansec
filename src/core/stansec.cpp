/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QApplication>
#include <QFile>
#include <QTranslator>
#include <QTextCodec>

#include <memory>

#include "CmdLineManager.h"
#include "stansec.h"
#include "mainwindow.h"

#include "../checker/CheckerErrorReceiver.h"
#include "../checker/automatonchecker/AutomatonCheckerCreator.h"
#include "../checker/reachabilitychecker/ReachabilityCheckerCreator.h"
#include "../parser/parser.h"

using namespace core;

Stansec::Stansec(int argc, char *argv[], bool GUI) :
	app(GUI ? std::make_unique<QApplication>(argc, argv) :
		  std::make_unique<QCoreApplication>(argc, argv)),
	GUI(GUI) {
    app->setApplicationVersion("1");

    QTranslator translator;
    if (translator.load(QLocale(), "stansec", "_",
			app->applicationDirPath() + "/trans"))
	app->installTranslator(&translator);

    cmdLine = std::make_unique<CmdLineManager>(*app);
}

int Stansec::startGUI()
{
	MainWindow w(cmdLine->positionalArguments());
	w.show();

	return app->exec();
}

int Stansec::startTUI()
{
	auto codec = QTextCodec::codecForName("UTF-8");

	for (auto fileName: cmdLine->positionalArguments()) {
		qInfo().noquote().nospace() << tr("Processing") << " \"" <<
					       fileName << '"';
		qInfo() << "======================";
		QFile f(fileName);
		if (!f.open(QFile::ReadOnly | QFile::Text)) {
			qWarning().noquote().nospace() << tr("Cannot open") << " \"" <<
						      fileName << "\" " <<
						      tr("due to error") << ": " <<
						      f.errorString();
			continue;
		}
		const auto data = codec->toUnicode(f.readAll());
		f.close();

		checker::QInfoCheckerProgressMonitor monitor;
		checker::CheckerErrorReceiver errReceiver([](const checker::CheckerError &err) {
		    qWarning() << "================";
		    qWarning() << "ERROR:" << err.getShortDesc() << "from" <<
				  err.getCheckerName();
		    qWarning() << err.getFullDesc() << "with importance" <<
				  err.getImportance();
		    for (const auto &trace : err.getTraces())
			    trace.dump();
		    qWarning() << "================";
		});
		checker::ReachabilityCheckerCreator reach;

		QFile xmlFile("auto.xml");
		QList<QFile *> args({ &xmlFile });
		checker::AutomatonCheckerCreator autom(args);

		parser::Parser parser(&monitor, errReceiver);
		parser.addChecker(&reach);
		parser.addChecker(&autom);
		parser.parseAndCheck(data.toStdString());
	}

	return 0;
}

int Stansec::startUI()
{
	return GUI ? startGUI() : startTUI();
}
