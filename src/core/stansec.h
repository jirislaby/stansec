#ifndef CORE_STANSEC_H
#define CORE_STANSEC_H

/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <memory>

#include <QCoreApplication>
#include <QObject>

#include "CmdLineManager.h"

namespace core {

class Stansec : public QObject
{
	Q_OBJECT
public:
	Stansec(int argc, char *argv[], bool GUI);

	int startUI();

private:
	int startTUI();
	int startGUI();

	std::unique_ptr<QCoreApplication> app;
	std::unique_ptr<CmdLineManager> cmdLine;
	bool GUI;
};

} // namespace core

#endif // CORE_STANSEC_H
