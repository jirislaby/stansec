#include "CFGListener.h"

#include <QDebug>
#include <QString>

CFGListener::CFGListener(antlr4::CommonTokenStream &tokens) :
    currentCFG(nullptr), tokens(tokens)
{
}

void CFGListener::enterFunctionDefinition(CParser::FunctionDefinitionContext *ctx)
{
    QString name(ctx->declarator()->directDeclarator()->directDeclarator()->Identifier()->getText().c_str());
    assert(!currentCFG);
    currentCFG = new CFG(tokens, name);
    map.insert(name, currentCFG);
    qDebug() << __func__ << name;
}

void CFGListener::exitFunctionDefinition(CParser::FunctionDefinitionContext *)
{
    currentCFG = nullptr;
}

void CFGListener::enterEveryRule(antlr4::ParserRuleContext *ctx)
{
    Q_UNUSED(ctx);
    //qDebug() << __func__ << QString::fromStdString(ctx->start->getText());
}

void CFGListener::enterExpression(CParser::ExpressionContext *)
{

}

void CFGListener::exitExpression(CParser::ExpressionContext *ctx)
{
    currentCFG->addNode(new CFGNode(currentCFG, ctx->getSourceInterval()));
}
