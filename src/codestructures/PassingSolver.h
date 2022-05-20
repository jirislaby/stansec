#ifndef PASSINGSOLVER_H
#define PASSINGSOLVER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <functional>

#include <QList>
#include <QPair>
#include <QString>
#include <QStringList>

namespace clang {
class Decl;
class Expr;
class Stmt;
}

namespace utils {
class XMLPatternVariablesAssignment;
}

namespace codestructs {

class PassingSolver {
public:
    using CallMapping = QPair<const clang::Expr *, const clang::Expr *>;
    using CallSiteToCalleeMap = QList<CallMapping>;

    static const clang::Expr *
    pass(const clang::Expr *argument, const CallSiteToCalleeMap &callMapping);
    static const clang::Expr *
    pass(const clang::Expr *argument, const CallMapping &callMapping);

    static bool stmtContainsDecl(const clang::Stmt *stmt,
				 const clang::Decl *decl);

    static const clang::Decl *getFirstDecl(const clang::Stmt *stmt);
    static bool forEachDecl(const clang::Stmt *stmt,
			    const std::function<bool (const clang::Decl *)> &CB);
private:
    //static QString parseElement(const Element &elem);

    static QString parseNodeType(const QString &type);

    PassingSolver() = delete;
};

}

#endif
