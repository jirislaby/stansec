#include "CFGListener.h"

#include <QDebug>
#include <QString>

#include "CFG.h"
#include "CFGNode.h"

CFGListener::CFGListener(antlr4::CommonTokenStream &tokens) :
    currentCFG(nullptr), tokens(tokens)
{
}

CFGListener::~CFGListener()
{
    for (auto cfg: map)
        delete cfg;
}

void CFGListener::enterFunctionDefinition(CParser::FunctionDefinitionContext *ctx)
{
    Q_UNUSED(ctx);
}

void CFGListener::exitFunctionDefinition(CParser::FunctionDefinitionContext *ctx)
{
    QString name(ctx->declarator()->directDeclarator()->directDeclarator()->Identifier()->getText().c_str());
    qDebug() << __func__ << name;

    auto cfg = CFG::createFromCFGPart(cfgs.removeFrom(ctx->compoundStatement()), nullptr);
    map.insert(name, cfg);
#if 0
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
}

void CFGListener::enterEveryRule(antlr4::ParserRuleContext *ctx)
{
    Q_UNUSED(ctx);
    //qDebug() << __func__ << QString::fromStdString(ctx->start->getText());
}

void CFGListener::exitCompoundStatement(CParser::CompoundStatementContext *ctx)
{
    if (auto bil = ctx->blockItemList()) {
        auto bilCfg = cfgs.removeFrom(bil);
        cfgs.put(ctx, bilCfg);
    }
}

void CFGListener::exitBlockItemList(CParser::BlockItemListContext *ctx)
{
    auto cfg = cfgs.removeFrom(ctx->blockItem());

    if (auto bil = ctx->blockItemList()) {
        auto bilCfg = cfgs.removeFrom(bil);
        bilCfg->append(cfg);
        cfg = bilCfg;
    }

    cfgs.put(ctx, cfg);
}

void CFGListener::exitBlockItem(CParser::BlockItemContext *ctx)
{
    auto cfg = cfgs.removeFrom(ctx->getRuleContext<antlr4::ParserRuleContext>(0));
    cfgs.put(ctx, cfg);
    qDebug() << __func__ << ctx->getText().c_str() << "->";
    qDebug().noquote() << cfg->toDot();
}

void CFGListener::exitStatement(CParser::StatementContext *ctx)
{
    cfgs.put(ctx, cfgs.removeFrom(ctx->getRuleContext<antlr4::ParserRuleContext>(0)));
}

void CFGListener::exitExpressionStatement(CParser::ExpressionStatementContext *ctx)
{
    if (auto e = ctx->expression())
        cfgs.put(ctx, cfgs.removeFrom(e));
}

CFGNode *CFGListener::buildAssert(antlr4::ParserRuleContext *ctx, bool branch)
{
    return new CFGAssertNode(ctx->getSourceInterval(), !branch);
}

void CFGListener::exitSelectionStatement(CParser::SelectionStatementContext *ctx)
{
    if (ctx->If()) {
        auto joinN = new CFGJoinNode(ctx->getSourceInterval());
        auto e = ctx->expression();
        auto eCFG = cfgs.removeFrom(e);
        auto endECFG = eCFG->getEndNode();

        /* true */
        auto s1C = cfgs.removeFrom(ctx->statement(0));
        auto assTrue = buildAssert(e, true);
        endECFG->addEdge(assTrue, "true");
        assTrue->addEdge(s1C->getStartNode());
        s1C->getEndNode()->addEdge(joinN);
        delete s1C;

        /* false */
        auto assFalse = buildAssert(e, false);
        endECFG->addEdge(assFalse, "false");
        if (auto s2 = ctx->statement(1)) {
            auto s2C = cfgs.removeFrom(s2);
            assFalse->addEdge(s2C->getStartNode());
            s2C->getEndNode()->addEdge(joinN);
            delete s2C;
        } else
            assFalse->addEdge(joinN);

        eCFG->setEndNode(joinN);
        cfgs.put(ctx, eCFG);
        return;
    }
}

void CFGListener::exitIterationStatement(CParser::IterationStatementContext *ctx)
{
    CFGPart *cfg;
    auto joinN = new CFGJoinNode(ctx->getSourceInterval());

    if (ctx->For()) {
        if (auto init = ctx->forCondition()->forDeclaration())
            cfg = cfgs.removeFrom(init);
        else if (auto init = ctx->forCondition()->expression())
            cfg = cfgs.removeFrom(init);
        else
            cfg = new CFGPart(tokens);

        auto cond = cfgs.removeFrom(ctx->forCondition()->forExpression(0));
        auto incr = cfgs.removeFrom(ctx->forCondition()->forExpression(1));
        auto stmt = cfgs.removeFrom(ctx->statement());

        cfg->append(cond->getStartNode());
        cond->getEndNode()->addEdge(stmt->getStartNode(), "true");
        cond->getEndNode()->addEdge(joinN, "false");

        stmt->append(incr);
        stmt->append(cond);

        delete stmt;
    } else if (ctx->Do()) {
        cfg = cfgs.removeFrom(ctx->statement());
        cfg->append(cfgs.removeFrom(ctx->expression()));

        auto cond = cfg->getEndNode();
        cond->addEdge(cfg->getStartNode(), "true");
        cond->addEdge(joinN, "false");

    } else {
        cfg = cfgs.removeFrom(ctx->expression());
        auto stmt = cfgs.removeFrom(ctx->statement());

        cfg->getEndNode()->addEdge(stmt->getStartNode(), "true");
        cfg->getEndNode()->addEdge(joinN, "false");

        stmt->getEndNode()->addEdge(cfg->getStartNode());

        delete stmt;
    }
    cfg->setEndNode(joinN);
    cfgs.put(ctx, cfg);
}

void CFGListener::enterForDeclaration(CParser::ForDeclarationContext *)
{
    currentCFG = new CFGPart(tokens);
}

void CFGListener::exitForDeclaration(CParser::ForDeclarationContext *ctx)
{
    cfgs.put(ctx, currentCFG);
    currentCFG = nullptr;
}

void CFGListener::exitForExpression(CParser::ForExpressionContext *ctx)
{
    auto cfg = cfgs.removeFrom(ctx->assignmentExpression());

    if (auto forE = ctx->forExpression()) {
        auto forECfg = cfgs.removeFrom(forE);
        forECfg->append(cfg);
        cfg = forECfg;
    }

    cfgs.put(ctx, cfg);
}

void CFGListener::exitJumpStatement(CParser::JumpStatementContext *ctx)
{
    auto cfg = new CFGPart(tokens);
    cfgs.put(ctx, cfg);
    /* drop semicolon */
    auto i = ctx->getSourceInterval();
    cfg->append(new CFGNode(antlr4::misc::Interval(i.a, i.b - 1)));
}

void CFGListener::exitAssignmentExpression(CParser::AssignmentExpressionContext *ctx)
{
    auto cfg = new CFGPart(tokens);
    cfgs.put(ctx, cfg);

    cfg->append(new CFGNode(ctx->getSourceInterval()));
}

void CFGListener::exitExpression(CParser::ExpressionContext *ctx)
{
    auto e = ctx->expression();
    auto cfg = e ? cfgs.removeFrom(e) : new CFGPart(tokens);
    cfgs.put(ctx, cfg);

    cfg->append(cfgs.removeFrom(ctx->assignmentExpression()));
    //qDebug() << __func__ << ctx->getText().c_str() << "->";
    //qDebug().noquote() << cfg->toDot();
}

void CFGListener::enterDeclaration(CParser::DeclarationContext *ctx)
{
    Q_UNUSED(ctx);

    currentCFG = new CFGPart(tokens);
}

void CFGListener::exitDeclaration(CParser::DeclarationContext *ctx)
{
    cfgs.put(ctx, currentCFG);
    currentCFG = nullptr;

    //qDebug() << __func__ << ctx->getText().c_str();
}

void CFGListener::exitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx)
{
    Q_UNUSED(ctx);
#if 0
    auto cfg = cfgs.removeFrom(ctx->initDeclarator());

    if (auto idl = ctx->initDeclaratorList()) {
        auto idlCfg = cfgs.removeFrom(idl);
        if (cfg && idlCfg) {
            idlCfg->append(cfg);
            cfg = idlCfg;
        } else if (idlCfg)
            cfg = idlCfg;
    }

    if (cfg)
        cfgs.put(ctx, cfg);
#endif
}

void CFGListener::exitInitDeclarator(CParser::InitDeclaratorContext *ctx)
{
    if (!ctx->initializer())
        return;

    /*auto cfg = new CFGPart(tokens);
    cfgs.put(ctx, cfg);*/

    currentCFG->append(new CFGNode(ctx->getSourceInterval()));
}

#if 0
void CFGListener::exitInitializerList(CParser::InitializerListContext *ctx)
{
    auto il = ctx->initializerList();
    auto cfg = il ? cfgs.removeFrom(il) : nullptr;

    if (auto inCfg = cfgs.removeFrom(ctx->initializer())) {
        if (!cfg)
            cfg = new CFGPart(tokens);
        cfg->append(inCfg);
    }

    if (cfg)
        cfgs.put(ctx, cfg);
}

void CFGListener::exitInitializer(CParser::InitializerContext *ctx)
{
    if (auto ae = ctx->assignmentExpression())
        cfgs.put(ctx, cfgs.removeFrom(ae));
}
#endif
