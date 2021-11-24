/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QMap>
#include <QString>

#include "../../codestructures/PassingSolver.h"

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
#endif
