#include <QDebug>
#include <QRegularExpression>

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include "XMLRuleStringParser.h"

using namespace checker;

llvm::Optional<XMLRuleStringParser::XMLRule>
XMLRuleStringParser::parseOneSymbolRuleString(const QString &string)
{
	auto result = parseRuleString(string);
	if (!result || result->size() != 1) {
		qWarning() << "AttributeName" << string <<
			      "must containt exactly one generic symbol.";
		return llvm::Optional<XMLRule>();
	}
	return result->first();
}

QStringList XMLRuleStringParser::splitStringToGenericsSymbolsParts(QString string)
{
	return string.replace(" ", "").
			replace("\t", "").
			replace("]", "] ").
			replace("] [", "][").
			trimmed().
			split(' ');
}

llvm::Optional<QList<XMLRuleStringParser::XMLRule> >
XMLRuleStringParser::parseRuleString(const QString &string)
{
	QList<XMLRule> result;

	for (auto &symbol : splitStringToGenericsSymbolsParts(string)) {
		auto generic = parseGenericSymbol(symbol);
		if (!generic)
			return llvm::Optional<QList<XMLRule> >();
		result.append(*generic);
	}

	return result;
}

llvm::Optional<XMLRuleStringParser::XMLRule>
XMLRuleStringParser::parseGenericSymbol(const QString &symbol)
{
	static QRegularExpression REvar("\\[([A-Za-z0-9_]+|\\*)\\]");
	static QRegularExpression REsym("^(\\+|-)?([A-Za-z0-9_]+)((?:" + REvar.pattern() + ")*)$");
	assert(REsym.isValid());
	assert(REvar.isValid());

	auto match = REsym.match(symbol);
	if (!match.hasMatch()) {
	    qWarning() << "cannot parse symbol" << symbol;
	    return llvm::Optional<XMLRule>();
	}

	return parseREMatch(match, REvar);
}

XMLRuleStringParser::XMLRule
XMLRuleStringParser::parseREMatch(const QRegularExpressionMatch &match,
				  const QRegularExpression &REvar)
{
	auto modeStr = match.captured(1);
	Mode mode = modeStr == '-' ? Minus : Plus;
	auto stateSymbol = match.captured(2);
	auto varsSymbolsStr = match.captured(3);
	QStringList varsSymbols;

	auto i = REvar.globalMatch(varsSymbolsStr);
	while (i.hasNext()) {
	    auto match = i.next();
	    varsSymbols.append(match.captured(1));
	}

	return std::make_tuple(stateSymbol, varsSymbols, mode);
}
