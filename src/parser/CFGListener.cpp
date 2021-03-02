#include "CFGListener.h"

#include <QDebug>
#include <QString>

#include "CFG.h"
#include "CFGNode.h"

CFGListener::CFGListener(antlr4::CommonTokenStream &tokens) :
    tokens(tokens)
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

void CFGListener::exitLabeledStatement(CParser::LabeledStatementContext *ctx)
{
    cfgs.put(ctx, cfgs.removeFrom(ctx->statement()));
}

void CFGListener::exitCompoundStatement(CParser::CompoundStatementContext *ctx)
{
    CFGPart *cfg;
    auto nitems = ctx->blockItem().size();

    if (!nitems) {
        cfg = new CFGPart(tokens);
        cfg->append(new CFGNode(ctx->getSourceInterval()));
    } else
        cfg = cfgs.removeFrom(ctx->blockItem(0));

    cfgs.put(ctx, cfg);

    for (typeof(nitems) i = 1; i < nitems; ++i) {
        auto bi = ctx->blockItem(i);
        auto bilCfg = cfgs.removeFrom(bi);
        cfg->append(bilCfg);
    }
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
	else
		cfgs.put(ctx, new CFGPart(tokens));
}

CFGNode *CFGListener::buildAssert(antlr4::ParserRuleContext *ctx, bool branch)
{
    return new CFGAssertNode(ctx->getSourceInterval(), !branch);
}

void CFGListener::exitSelectionStatement(CParser::SelectionStatementContext *ctx)
{
    auto joinN = new CFGJoinNode(ctx->getSourceInterval());
    auto e = ctx->expression();
    auto eCFG = cfgs.removeFrom(e);
    auto endECFG = eCFG->getEndNode();
    auto s1C = cfgs.removeFrom(ctx->statement(0));

    if (ctx->If()) {
        /* true */
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
    } else {
	/* TODO switch properly */
	qDebug() << s1C->toDot();
	endECFG->addEdge(s1C->getStartNode());
	s1C->getEndNode()->addEdge(joinN);
	delete s1C;
    }

    eCFG->setEndNode(joinN);
    cfgs.put(ctx, eCFG);
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

	if (cond) {
		cond->getEndNode()->addEdge(stmt->getStartNode(), "true");
		cond->getEndNode()->addEdge(joinN, "false");
	} else
		cond = stmt;
	cfg->append(cond->getStartNode());

	if (incr)
		stmt->append(incr);
	stmt->append(cond);

	if (stmt != cond)
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

void CFGListener::exitForDeclaration(CParser::ForDeclarationContext *ctx)
{
	auto idl = cfgs.removeFrom(ctx->initDeclaratorList());
	cfgs.put(ctx, idl);
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

void CFGListener::exitAsmStatement(CParser::AsmStatementContext *ctx)
{
    auto cfg = new CFGPart(tokens);
    cfgs.put(ctx, cfg);
    cfg->append(new CFGAsmNode(ctx->getSourceInterval()));
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

void CFGListener::exitDeclaration(CParser::DeclarationContext *ctx)
{
	auto idl = ctx->initDeclaratorList();
	auto cfg = idl ? cfgs.removeFrom(idl) : new CFGPart(tokens);
	cfgs.put(ctx, cfg);
}

void CFGListener::exitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx)
{
	CFGPart *cfg = nullptr;

	for (auto id: ctx->initDeclarator()) {
		auto idlCfg = cfgs.removeFrom(id);
		if (idlCfg) {
			if (!cfg)
				cfg = idlCfg;
			else
				cfg->append(idlCfg);
		}
	}

	if (!cfg)
		cfg = new CFGPart(tokens);

	cfgs.put(ctx, cfg);
}

void CFGListener::exitInitDeclarator(CParser::InitDeclaratorContext *ctx)
{
    if (!ctx->initializer())
        return;

    auto cfg = new CFGPart(tokens);
    cfg->append(new CFGNode(ctx->getSourceInterval()));
    cfgs.put(ctx, cfg);
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

void CFGListener::exitGccAttribute(CParser::GccAttributeContext *ctx)
{
    qDebug() << "XXX ATTR:" << ctx->getText().c_str();
}
