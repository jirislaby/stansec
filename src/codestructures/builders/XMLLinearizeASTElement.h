#ifndef XMLLINEARIZEASTELEMENT_H
#define XMLLINEARIZEASTELEMENT_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QString>
#include <QVector>

#include "../../utils/xmlpatterns/XMLAlgo.h"

class QDomElement;

namespace codestructs {

/*final*/ class XMLLinearizeASTElement {
public:

    static QVector<QDomElement> functionCall(const QDomElement &elem);
    static QVector<QDomElement> voidFunctionCall(const QDomElement &elem);
    static QVector<QDomElement> assignFunctionCall(const QDomElement &elem);
    static QDomElement functionRet(const QDomElement &elem);
    static QVector<QDomElement> functionDeclaration(const QDomElement elem);

private:
    /**
     * Checks whether @params are the single void keyword (i.e. no params)
     *
     * Compares @params to:
     * <parameter>
     *  <declarationSpecifiers>
     *   <typeSpecifier>
     *     <baseType>void</baseType>
     *   </typeSpecifier>
     * 	</declarationSpecifiers>
     * </parameter>
     * and returns true if it matches.
     */
    static bool isVoidParam(const QList<QDomElement> &params);


    static QDomElement parseParameterName(const QDomElement &param,
				      const int argID);

    static QDomElement createElement(const QString &type, const QString &data);

    template<typename T>
    static QVector<T> cons(const T &v, const QList<T> &l) {
	QVector<T> result(l.begin(), l.end());
	result.prepend(v);
        return result;
    }

    template<typename T>
    static QVector<T> tail(const QVector<T> &l) {
	return l.mid(1);
    }

    XMLLinearizeASTElement() = delete;

    static const QDomElement voidParam;
};

}

#endif
