#ifndef PASSINGSOLVER_H
#define PASSINGSOLVER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <llvm/ADT/Optional.h>

#include <QList>
#include <QPair>
#include <QString>
#include <QStringList>

namespace clang {
class Expr;
class Stmt;
}

namespace utils {
class XMLPatternVariablesAssignment;
}

namespace codestructs {

class PassingSolver {
public:
    using CallMapping = QPair<QString, QString>;
    static QStringList makeArgumentList(const utils::XMLPatternVariablesAssignment &xmlAssignment);
    static QString makeArgument(const clang::Stmt *node);
    static QString makeArgument(const clang::Expr *op);
#if 0
    static QString makeArgument(const Element &elem);
#endif

    static llvm::Optional<QString>
    pass(const QString &argument,
	 const QList<CallMapping> &callMapping);
    static llvm::Optional<QString>
    pass(QString argument,
	 const CallMapping &callMapping);

    static QString simplify(QString argument) {
	    return argument.replace("* & ", "")
			    .replace("->", ". *");
    }

    static QString parseRootVariableName(const QString &argument);

private:

    //static QString parseElement(const Element &elem);

    static QString parseNodeType(const QString &type);

    PassingSolver() = delete;
};

}

#endif
