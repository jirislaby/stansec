#ifndef SOURCECODEEDIT_H
#define SOURCECODEEDIT_H

#include <QTextEdit>

class SourceCodeEdit : public QTextEdit
{
public:
	SourceCodeEdit();

	bool event(QEvent *event) override;
private:
	static int getLine(QTextCursor cursor);
};

#endif // SOURCECODEEDIT_H
