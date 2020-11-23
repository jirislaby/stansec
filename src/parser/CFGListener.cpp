#include "CFGListener.h"

#include <QDebug>
#include <QString>

#include "CFG.h"
#include "CFGNode.h"

CFGListener::CFGListener(antlr4::CommonTokenStream &tokens) :
    currentCFG(nullptr), tokens(tokens)
{
}

void CFGListener::enterFunctionDefinition(CParser::FunctionDefinitionContext *ctx)
{
    QString name(ctx->declarator()->directDeclarator()->directDeclarator()->Identifier()->getText().c_str());
    assert(!currentCFG);
    currentCFG = new CFG(tokens, nullptr, nullptr, name);
    map.insert(name, currentCFG);
    qDebug() << __func__ << name;
}

void CFGListener::exitFunctionDefinition(CParser::FunctionDefinitionContext */*ctx*/)
{
#if 0
    auto g = CFG::createFromCFGPart(ctx->compoundStatement()->g, nullptr);
                   $functionDefinition.start.getElement());
    $g.setSymbols($Function::symbols);
    CFGNode endNode = new CFGNode(xmlFactory.createElement("exit").
                      addAttribute("bl", Integer.toString(
                               $compoundStatement.start.getChild(0).
                               getLine())));
    $g.setEndNode(endNode);
    for (CFGBreakNode n: $Function::rets)
        n.addBreakEdge(endNode);
    $Function::lastStatement.addEdge(endNode);
    for (Pair<String, CFGBreakNode> gotoPair: $Function::gotos) {
        CFGNode labelNode =
                $Function::labels.get(gotoPair.getFirst());
        gotoPair.getSecond().addBreakEdge(labelNode);
    }
#endif

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
