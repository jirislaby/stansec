#ifndef CHECKERERRORTRACELOCATION_H
#define CHECKERERRORTRACELOCATION_H

/*
 * Copyright (c) 2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QDebug>
#include <QString>

#include <clang/Basic/SourceLocation.h>

namespace checker {

class CheckerErrorTraceLocation {
public:
    CheckerErrorTraceLocation(const clang::PresumedLoc &ploc,
			      const QString description) :
	    unitName(ploc.isValid() ? ploc.getFilename() : "<invalid>"),
	    lineNumber(ploc.isValid() ? ploc.getLine() : 0),
	    columnNumber(ploc.isValid() ? ploc.getColumn() : 0),
	    description(description) { }

    CheckerErrorTraceLocation(const QString unitName,
			      const int lineNumber,
			      const int columnNumber,
			      const QString description) :
	    unitName(unitName), lineNumber(lineNumber),
	    columnNumber(columnNumber), description(description) { }

    QString toString() const {
        return getDescription() + " [file: " + getUnitName() + ", line: " +
	       QString::number(getLineNumber()) + "]";
    }

#if 0
    Element xmlDump() {
	Element result = DocumentFactory.getInstance().
		    createElement("location");
	result.addElement("unit").addText(getUnitName());
	result.addElement("line").addText(Integer.toString(getLineNumber()));
	result.addElement("column").addText(Integer.toString(getColumnNumber()));
	result.addElement("description").addText(getDescription());
        return result;
    }
#endif
    QString getUnitName() const {
        return unitName;
    }

    int getLineNumber() const {
        return lineNumber;
    }

    int getColumnNumber() const {
        return columnNumber;
    }

    QString getDescription() const {
        return description;
    }
#if 0
    bool isEqualWith(const CheckerErrorTraceLocation other) {
        return getUnitName().equals(other.getUnitName()) &&
               getLineNumber() == other.getLineNumber() &&
               getDescription().equals(other.getDescription());
    }
#endif
    bool isContextLocation() const {
        return getDescription().startsWith("<context>");
    }

private:
    QString unitName;
    int lineNumber;
    int columnNumber;
    QString description;
};

}

inline QDebug operator<<(QDebug d, const checker::CheckerErrorTraceLocation &item)
{
	d << item.getUnitName() + ':' +
		     QString::number(item.getLineNumber()) + ':' +
		     QString::number(item.getColumnNumber()) <<
	     item.getDescription();
	return d;
}

#endif
