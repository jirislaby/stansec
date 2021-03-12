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
	functionStack.push(Function());
}

void CFGListener::exitFunctionDefinition(CParser::FunctionDefinitionContext *ctx)
{
	QString name(ctx->declarator()->directDeclarator()->directDeclarator()->Identifier()->getText().c_str());
	qDebug() << __func__ << name;

	antlr4::misc::Interval intval(ctx->getSourceInterval().b,
				      ctx->getSourceInterval().b);
	auto endNode = new CFGExitNode(intval, name);

	auto cfgPart = cfgs.removeFrom(ctx->compoundStatement());
	cfgPart->append(endNode);

	auto top = functionStack.pop();
	for (auto p: top.gotos) {
		auto labelNode = top.labels.find(p.first).value();
		p.second->addBreakEdge(labelNode);
	}

	for (auto ret: top.rets)
		ret->addBreakEdge(endNode);

	auto cfg = CFG::createFromCFGPart(cfgPart, nullptr);
	map.insert(name, cfg);
}

void CFGListener::exitLabeledStatement(CParser::LabeledStatementContext *ctx)
{
	auto stmtCFG = cfgs.removeFrom(ctx->statement());
	auto stmtCFGStart = stmtCFG->getStartNode();

	if (ctx->Case() || ctx->Default()) {
		auto label = QString(ctx->Default() ? "default" :
				 ctx->constantExpression(0)->getText().c_str());
		if (auto ce1 = ctx->constantExpression(1))
			label.append("...").append(ce1->getText().c_str());
		auto p = QPair<QString, CFGNode *>(label, stmtCFGStart);
		iterSwitchStack.top().cases.push_back(p);
	} else {
		auto id = QString(ctx->Identifier()->getText().c_str());
		functionStack.top().labels.insert(id, stmtCFGStart);
	}

	cfgs.put(ctx, stmtCFG);
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
}

void CFGListener::exitStatement(CParser::StatementContext *ctx)
{
    cfgs.put(ctx, cfgs.removeFrom(ctx->getRuleContext<antlr4::ParserRuleContext>(0)));
}

void CFGListener::exitExpressionStatement(CParser::ExpressionStatementContext *ctx)
{
	if (auto e = ctx->expression())
		cfgs.put(ctx, cfgs.removeFrom(e));
	else {
		auto cfg = new CFGPart(tokens);
		cfg->append(new CFGNode(ctx->getSourceInterval()));
		cfgs.put(ctx, cfg);
	}
}

CFGNode *CFGListener::buildAssert(antlr4::ParserRuleContext *ctx, bool branch)
{
    return new CFGAssertNode(ctx->getSourceInterval(), !branch);
}

void CFGListener::enterSelectionStatement(CParser::SelectionStatementContext *ctx)
{
	if (ctx->Switch())
		iterSwitchStack.push(IterSwitch(true));
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
	auto top = iterSwitchStack.pop();
	assert(top.isSwitch);

	for (auto c: top.cases) {
		// TODO assert
		endECFG->addEdge(c.second, c.first);
	}

	s1C->getEndNode()->addEdge(joinN);
	delete s1C;


	for (auto b: top.breaks)
		b->addBreakEdge(joinN);
    }

    eCFG->setEndNode(joinN);
    cfgs.put(ctx, eCFG);
}

void CFGListener::enterIterationStatement(CParser::IterationStatementContext *)
{
	iterSwitchStack.push(IterSwitch(false));
}

void CFGListener::exitIterationStatement(CParser::IterationStatementContext *ctx)
{
    CFGPart *cfg;
    auto joinN = new CFGJoinNode(ctx->getSourceInterval());
    CFGNode *contN;

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
	contN = cond->getStartNode();
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
	contN = cfg->getStartNode();
	cond->addEdge(contN, "true");
        cond->addEdge(joinN, "false");

    } else {
        cfg = cfgs.removeFrom(ctx->expression());
        auto stmt = cfgs.removeFrom(ctx->statement());

        cfg->getEndNode()->addEdge(stmt->getStartNode(), "true");
        cfg->getEndNode()->addEdge(joinN, "false");

	contN = cfg->getStartNode();
	stmt->getEndNode()->addEdge(contN);

        delete stmt;
    }
    cfg->setEndNode(joinN);
    cfgs.put(ctx, cfg);

    auto top = iterSwitchStack.pop();
    assert(!top.isSwitch);
    for (auto b: top.breaks)
	    b->addBreakEdge(joinN);
    for (auto c: top.conts)
	    c->addBreakEdge(contN);
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
	auto bn = new CFGBreakNode(antlr4::misc::Interval(i.a, i.b - 1));
	cfg->append(bn);

	if (ctx->Goto()) {
		if (auto id = ctx->Identifier()) {
			auto p = QPair<QString, CFGBreakNode *>(id->getText().c_str(), bn);
			functionStack.top().gotos.push_back(p);
		} else
			abort(); // TODO
	} else if (ctx->Continue()) {
		/*
		 * conts (opposing to breaks) are not there for switch, find
		 * deeper in the stack
		 */
		for (auto s = iterSwitchStack.rbegin(); s != iterSwitchStack.rend(); ++s)
			if (!s->isSwitch) {
				s->conts.push_back(bn);
				break;
			}
	} else if (ctx->Break()) {
		iterSwitchStack.top().breaks.push_back(bn);
	} else if (ctx->Return()) {
		functionStack.top().rets.push_back(bn);
	}
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
	Q_UNUSED(ctx);
	//qDebug() << "XXX ATTR:" << ctx->getText().c_str();
}
