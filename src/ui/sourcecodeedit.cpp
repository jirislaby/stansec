#include "sourcecodeedit.h"

#include <QEvent>
#include <QHelpEvent>
#include <QTextBlock>
#include <QTextCursor>
#include <QToolTip>

SourceCodeEdit::SourceCodeEdit()
{

}

int SourceCodeEdit::getLine(QTextCursor cursor)
{
	cursor.movePosition(QTextCursor::StartOfLine);

	int lines = 1;
	while (cursor.positionInBlock() > 0) {
		cursor.movePosition(QTextCursor::Up);
		lines++;
	}
	auto block = cursor.block().previous();

	while (block.isValid()) {
		lines += block.lineCount();
		block = block.previous();
	}

	return lines;
}

bool SourceCodeEdit::event(QEvent *event)
{
	if (event->type() == QEvent::ToolTip) {
		auto helpEvent = static_cast<QHelpEvent *>(event);
		auto pos = helpEvent->pos();
		auto posText = this->cursorForPosition(pos);
		QToolTip::showText(helpEvent->globalPos(),
				   QString::number(getLine(posText)) + ':' +
				   QString::number(posText.columnNumber()));

		return true;
	}

	return QWidget::event(event);
}
