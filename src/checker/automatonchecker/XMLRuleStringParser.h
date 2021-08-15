#ifndef XMLRULESTRINGPARSER_H
#define XMLRULESTRINGPARSER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <tuple>
#include <llvm/ADT/Optional.h>

#include <QList>
#include <QString>
#include <QStringList>

class QRegularExpression;
class QRegularExpressionMatch;

namespace checker {

class XMLRuleStringParser final {
    // package-private section
public:
    enum Mode {
	Plus,
	Minus,
    };
    using XMLRule = std::tuple<QString, QStringList, Mode>;

    static llvm::Optional<XMLRule> parseOneSymbolRuleString(const QString &string);
    static llvm::Optional<QList<XMLRule> > parseRuleString(const QString &string);
private:
    static QStringList splitStringToGenericsSymbolsParts(QString string);
    static llvm::Optional<XMLRule> parseGenericSymbol(const QString &symbol);
    static XMLRule parseREMatch(const QRegularExpressionMatch &match,
				const QRegularExpression &REvar);

    XMLRuleStringParser() = delete;
};

}

#endif
