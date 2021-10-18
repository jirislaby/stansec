#ifndef CHECKERPROGRESSMONITOR_H
#define CHECKERPROGRESSMONITOR_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QString>

namespace checker {

class CheckerProgressMonitor {
public:
    virtual void write(const QString &s) const = 0;
};

class QInfoCheckerProgressMonitor : public CheckerProgressMonitor {
public:
    virtual void write(const QString &s) const override {
	qInfo().noquote().nospace() << s;
    }
};

}

#endif
