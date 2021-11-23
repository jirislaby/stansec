#ifndef SOURCECODEEDIT_H
#define SOURCECODEEDIT_H

/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QTextEdit>

namespace parser { class Parser; }

namespace Ui {

class SourceCodeEdit : public QTextEdit
{
public:
	SourceCodeEdit();

	void setParser(parser::Parser *parser) { this->parser = parser; }

	bool event(QEvent *event) override;
private:
	parser::Parser *parser;
	static int getLine(QTextCursor cursor);
};

}

#endif // SOURCECODEEDIT_H
