#include "sourcecodeedit.h"
#include "../parser/parser.h"

#include <QEvent>
#include <QHelpEvent>
#include <QTextBlock>
#include <QTextCursor>
#include <QToolTip>

SourceCodeEdit::SourceCodeEdit() : parser(nullptr)
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
		auto posText = cursorForPosition(pos);
		auto line = getLine(posText);
		auto tip = QString::number(line).append(':').
				append(QString::number(posText.columnNumber()));

		if (parser) {
			auto dot = parser->getDot(line);
			tip.append("<br/>\n").append(dot);
		}

		QToolTip::showText(helpEvent->globalPos(), tip);

		return true;
	}

	return QWidget::event(event);
}
