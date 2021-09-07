/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QFile>
#include <QTextCodec>

#include <memory>

#include "stansec.h"
#include "mainwindow.h"

#include "../parser/parser.h"

using namespace core;

int Stansec::startGUI()
{
	MainWindow w(cmdLine.positionalArguments());
	w.show();

	return app.exec();
}

int Stansec::startTUI()
{
	auto codec = QTextCodec::codecForName("UTF-8");

	for (auto fileName: cmdLine.positionalArguments()) {
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

		parser::Parser parser;
		parser.parse(data.toStdString());
	}

	return 0;
}

int Stansec::startUI()
{
	return cmdLine.startGUI() ? startGUI() : startTUI();
}
