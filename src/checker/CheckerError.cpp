/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QString>

#include "CheckerError.h"

using namespace checker;

QString CheckerError::toString() const
{
    //const auto &errorLocation = getErrorLocation();
    QString res("[");
    res.append(QString::number(getImportance())).append("] ");
#if 0
    QString path = new File(errorLocation.getUnitName()).getAbsolutePath();
    // relativize
    path.replaceFirst(Stanse.getInstance().getRootDirectory() + '/', "");
    res.append(path).append(", line ").append(errorLocation.getLineNumber()).
	    append(": ").append(getShortDesc());
#endif
    return res;
}

void CheckerError::dump() const
{
	qDebug().noquote().nospace() << toString();
	for (const auto &trace : getTraces())
	    trace.dump();
}

#if 0
    public Element xmlDump() {
	Element result = DocumentFactory.getInstance().createElement("error");
	result.addElement("short_desc").addText(getShortDesc());
	result.addElement("full_desc").addText(getFullDesc());
	result.addElement("importance").addText(
			Integer.toString(getImportance()));
	result.addElement("checker_name").addText(getCheckerName());
	Element eTraces = result.addElement("traces").addText(getCheckerName());

        for (const CheckerErrorTrace trace: getTraces())
            eTraces.add(trace.xmlDump());
        return result;
    }
#endif
