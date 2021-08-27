#ifndef PASSINGSOLVER_H
#define PASSINGSOLVER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QPair>
#include <QString>

namespace codestructs {

class PassingSolver {

public:
#if 0
    static QString makeArgument(const CFGNode::Operand &op);
    static QString makeArgument(const CFGNode &node);
    static QString makeArgument(const Element &elem);
#endif

    static QString pass(const QString &argument,
			const QList<QPair<QString,QString>> &callMapping);

    static QString pass(const QString &argument,
			const QPair<QString, QString> &callMapping);

    static QString simplify(QString &argument);

    static QString parseRootVariableName(const QString &argument);

private:

    //static QString parseElement(const Element &elem);

    static QString parseNodeType(const QString &type);

    PassingSolver() = delete;
};

}

#endif
