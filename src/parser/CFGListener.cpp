#include "CFGListener.h"

#include <QDebug>
#include <QString>

CFGListener::CFGListener()
{
}

void CFGListener::enterFunctionDefinition(CParser::FunctionDefinitionContext *ctx)
{
    QString name(ctx->declarator()->directDeclarator()->directDeclarator()->Identifier()->getText().c_str());
    auto cfg = new CFG(name);
    map.insert(name, cfg);
    qDebug() << __func__ << name;
}

void CFGListener::enterEveryRule(antlr4::ParserRuleContext *ctx)
{
        Q_UNUSED(ctx);
    //qDebug() << __func__ << QString::fromStdString(ctx->start->getText());
}
