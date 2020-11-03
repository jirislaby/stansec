#include "CFGListener.h"

#include <QDebug>
#include <QString>

CFGListener::CFGListener()
{
}

void CFGListener::enterFunctionDefinition(CParser::FunctionDefinitionContext *ctx)
{
    qDebug() << __func__ << QString::fromStdString(ctx->start->getText());
}

void CFGListener::enterEveryRule(antlr4::ParserRuleContext *ctx)
{
    qDebug() << __func__ << QString::fromStdString(ctx->start->getText());
}
