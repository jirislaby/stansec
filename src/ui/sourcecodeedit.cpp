#include "sourcecodeedit.h"
#include "../parser/parser.h"

#include <QEvent>
#include <QHelpEvent>
#include <QProcess>
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
#if 0
	if (event->type() == QEvent::ToolTip) {
		auto helpEvent = static_cast<QHelpEvent *>(event);
		auto pos = helpEvent->pos();
		auto posText = cursorForPosition(pos);
		auto line = getLine(posText);
		auto tip = QString::number(line).append(':').
				append(QString::number(posText.columnNumber()));

		if (parser) {
			auto dot = parser->getDot(line);

			QProcess dotProc(this);
			dotProc.start("dot", QStringList() << "-Tpng");
			dotProc.write(dot.toLatin1());
			dotProc.closeWriteChannel();
			dotProc.waitForFinished();

			auto png = dotProc.readAllStandardOutput();
			tip.append("<br/>\n").
					append("<img src='data:image/png;base64, ").
					append(png.toBase64()).
					append("' width='600' />");
		}

		QToolTip::showText(helpEvent->globalPos(), tip);

		return true;
	}
#endif
	return QWidget::event(event);
}
