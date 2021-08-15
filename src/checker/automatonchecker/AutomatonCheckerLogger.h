#ifndef AUTOMATONCHECKERLOGGER_H
#define AUTOMATONCHECKERLOGGER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QString>

#include "../CheckerProgressMonitor.h"

namespace checker {

class AutomatonCheckerLogger {
private:
	AutomatonCheckerLogger();
public:
    // package-private section

    AutomatonCheckerLogger(CheckerProgressMonitor &monitor) :
	    monitor(monitor) {
#if 0
	columnsFormatter = new ColumnMessageFormatter("  ");
        timingFormatter = new TimedMessageSequenceFormatter(
                                   columnsFormatter.getTabPattern() + "done in ",
                                   " seconds","...");
#endif
    }

    void phaseLog(const QString &s) {
	note(s);
	//note(getTimingFormatter().write(s));
    }

    void phaseBreak(const QString &s) {
	note("I " + s);
	//note(getTimingFormatter().interrupt(s));
    }
    void note(const QString &s) {
	getMonitor().write(s + '\n');
	//getMonitor().write(getColumnsFormatter().write(s + "\n"));
    }
    void pushTab() {
	//getColumnsFormatter().pushTab();
    }

    void popTab() {
	//getColumnsFormatter().popTab();
    }

    // package-private section

#if 0
    ColumnMessageFormatter getColumnsFormatter() {
        return columnsFormatter;
    }

    TimedMessageSequenceFormatter getTimingFormatter() {
        return timingFormatter;
    }
#endif

private:
    CheckerProgressMonitor &getMonitor() {
	return monitor;
    }

    CheckerProgressMonitor &monitor;
    //private final ColumnMessageFormatter columnsFormatter;
    //private final TimedMessageSequenceFormatter timingFormatter;
};

}

#endif
