#include <cstdio>
#include <iostream>
#include <string>

#include <antlr4-runtime.h>

#include <QDebug>
#include <QFile>
#include <QProcess>

#include "CFGListener.h"
#include "CLexer.h"
#include "CParser.h"
#include "parser.h"

Parser::Parser()
{
}

Parser::~Parser()
{
	for (auto cfg: map)
		delete cfg;
}

void Parser::parse(const std::string &in)
{
	input.reset(new antlr4::ANTLRInputStream(in));
	lexer.reset(new CLexer(input.get()));
	tokens.reset(new antlr4::CommonTokenStream(lexer.get()));
	parser.reset(new CParser(tokens.get()));
	auto tree = parser->compilationUnit();
	CFGListener cfgListener(map, tokens.get());
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&cfgListener, tree);

	qDebug().noquote() << getDot("main");
}

CFG *Parser::getFunction(unsigned int line) const
{
	for (auto c : map)
		if (c->getLineStart() <= line && line <= c->getLineEnd())
			return c;

	return nullptr;
}

QString Parser::getDot(unsigned int line, int shrink) const
{
	if (auto f = getFunction(line))
		return f->toDot(shrink);

	return QString();
}

QString Parser::getDot(const QString &fun, int shrink) const
{
	if (!map.contains(fun))
		return QString();
	return map[fun]->toDot(shrink);
}

void Parser::dumpDots() const
{
    for (auto i = cfgBegin(); i != cfgEnd(); ++i) {
        auto name = i.key();
        auto cfg = i.value();

        QFile file(name + ".dot");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
	    out << cfg->toDot(100);
            file.close();
	    if (name == "main")
		    QProcess::execute("dot", QStringList() << "-Tpdf" << "-O" << file.fileName());
        }
    }
}

std::string Parser::getParseTree(const std::string &in)
{
	if (!parser)
		parse(in);

	return parser->compilationUnit()->toStringTree(parser.get(), true);
}
