#ifndef CFGLISTENER_H
#define CFGLISTENER_H

#include "CFG.h"
#include "CBaseListener.h"

#include <QMap>
#include <QString>

class CFGListener : public CBaseListener {

public:
    CFGListener(antlr4::CommonTokenStream &tokens);
    ~CFGListener();

    void enterFunctionDefinition(CParser::FunctionDefinitionContext *) override;
    void exitFunctionDefinition(CParser::FunctionDefinitionContext *) override;
    void enterEveryRule(antlr4::ParserRuleContext *) override;

    void exitCompoundStatement(CParser::CompoundStatementContext *) override;
    void exitBlockItemList(CParser::BlockItemListContext *) override;
    void exitBlockItem(CParser::BlockItemContext *) override;

    void exitStatement(CParser::StatementContext *) override;
    void exitExpressionStatement(CParser::ExpressionStatementContext *) override;
    void exitSelectionStatement(CParser::SelectionStatementContext *) override;
    void exitIterationStatement(CParser::IterationStatementContext *) override;
    void enterForDeclaration(CParser::ForDeclarationContext *) override;
    void exitForDeclaration(CParser::ForDeclarationContext *) override;
    void exitForExpression(CParser::ForExpressionContext *) override;
    void exitJumpStatement(CParser::JumpStatementContext *) override;

    void exitAssignmentExpression(CParser::AssignmentExpressionContext *) override;
    void exitExpression(CParser::ExpressionContext *) override;

    void enterDeclaration(CParser::DeclarationContext *) override;
    void exitDeclaration(CParser::DeclarationContext *) override;
    void exitInitDeclaratorList(CParser::InitDeclaratorListContext *) override;
    void exitInitDeclarator(CParser::InitDeclaratorContext *) override;

    /*void exitInitializerList(CParser::InitializerListContext *) override;
    void exitInitializer(CParser::InitializerContext *) override;*/

    QString getDot(const QString &fun) {
        const auto cfg = map[fun];
        return cfg ? cfg->toDot() : QString();
    }

private:
    antlr4::tree::ParseTreeProperty<CFGPart *> cfgs;
    QMap<QString, CFG *> map;
    CFGPart *currentCFG;

    antlr4::CommonTokenStream &tokens;

    static CFGNode *buildAssert(antlr4::ParserRuleContext *ctx, bool neg);
};

#endif
