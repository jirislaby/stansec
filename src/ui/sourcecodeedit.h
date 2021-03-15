#ifndef SOURCECODEEDIT_H
#define SOURCECODEEDIT_H

#include <QTextEdit>

class Parser;

class SourceCodeEdit : public QTextEdit
{
public:
	SourceCodeEdit();

	void setParser(Parser *parser) { this->parser = parser; }

	bool event(QEvent *event) override;
private:
	Parser *parser;
	static int getLine(QTextCursor cursor);
};

#endif // SOURCECODEEDIT_H
