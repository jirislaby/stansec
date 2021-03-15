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

QString Parser::getDot(const QString &fun) const
{
	if (!map.contains(fun))
		return QString();
	return map[fun]->toDot();
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
