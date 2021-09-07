#ifndef CORE_STANSEC_H
#define CORE_STANSEC_H

/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QObject>

#include "CmdLineManager.h"

namespace core {

class Stansec : public QObject
{
	Q_OBJECT
public:
	Stansec(QApplication &app, const CmdLineManager &cmdLine) :
		app(app), cmdLine(cmdLine) {}

	int startUI();

private:
	int startTUI();
	int startGUI();

	QApplication &app;
	const CmdLineManager &cmdLine;

signals:

};

} // namespace core

#endif // CORE_STANSEC_H
