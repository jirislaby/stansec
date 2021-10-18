/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QMap>
#include <QString>

#include "XMLPatternVariablesAssignment.h"

using namespace utils;

#if 0
    public bool isEqualWith(const XMLPatternVariablesAssignment other) {
	if (varToElement.size() != other.varToElement.size()
		|| varToNode.size() != other.varToNode.size())
	    return false;

        for (QString key : varToElement.keySet()) {
            if (!varToElement.get(key).equals(other.varToElement.get(key)))
		return false;
        }
        for (QString key : varToNode.keySet()) {
            if (!varToNode.get(key).equals(other.varToNode.get(key)))
		return false;
        }

        return true;
    }

QMap<QString, QString> XMLPatternVariablesAssignment::makeArgumentMap() {
    QMap<QString, QString> res;
#if 0
    for (QString key : varToElement.keys())
	res.insert(key, PassingSolver.makeArgument(varToElement.get(key)));
    for (QString key : varToNode.keySet())
	res.insert(key, PassingSolver.makeArgument(varToNode.get(key)));
#endif
    return res;
}
#endif

void XMLPatternVariablesAssignment::merge(XMLPatternVariablesAssignment other) {
    for (auto key : other.varToElement.keys())
	varToElement.insert(key, other.varToElement[key]);
    assert(false);
#if 0
    for (auto key : other.varToNode.keys())
	varToNode.insert(key, other.varToNode[key]);
#endif
}
