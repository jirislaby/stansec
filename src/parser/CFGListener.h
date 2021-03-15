#ifndef CFGLISTENER_H
#define CFGLISTENER_H

#include "CFG.h"
#include "CFGNode.h"
#include "CBaseListener.h"

#include <QMap>
#include <QStack>
#include <QString>
#include <QVector>

class CFGListener : public CBaseListener {

public:
    CFGListener(QMap<QString, CFG *> &map, antlr4::CommonTokenStream *tokens);
    ~CFGListener();

    void enterFunctionDefinition(CParser::FunctionDefinitionContext *) override;
    void exitFunctionDefinition(CParser::FunctionDefinitionContext *) override;

    void exitLabeledStatement(CParser::LabeledStatementContext *) override;
    void exitCompoundStatement(CParser::CompoundStatementContext *) override;
    void exitBlockItem(CParser::BlockItemContext *) override;

    void exitStatement(CParser::StatementContext *) override;
    void exitExpressionStatement(CParser::ExpressionStatementContext *) override;
    void enterSelectionStatement(CParser::SelectionStatementContext *) override;
    void exitSelectionStatement(CParser::SelectionStatementContext *) override;
    void enterIterationStatement(CParser::IterationStatementContext *) override;
    void exitIterationStatement(CParser::IterationStatementContext *) override;
    void exitForDeclaration(CParser::ForDeclarationContext *) override;
    void exitForExpression(CParser::ForExpressionContext *) override;
    void exitJumpStatement(CParser::JumpStatementContext *) override;
    void exitAsmStatement(CParser::AsmStatementContext *) override;

    void exitAssignmentExpression(CParser::AssignmentExpressionContext *) override;
    void exitExpression(CParser::ExpressionContext *) override;

    void exitDeclaration(CParser::DeclarationContext *) override;
    void exitInitDeclaratorList(CParser::InitDeclaratorListContext *) override;
    void exitInitDeclarator(CParser::InitDeclaratorContext *) override;

    /*void exitInitializerList(CParser::InitializerListContext *) override;
    void exitInitializer(CParser::InitializerContext *) override;*/

    void exitGccAttribute(CParser::GccAttributeContext *) override;

private:
    QMap<QString, CFG *> &map;

    class ParseTreeProperty : public antlr4::tree::ParseTreeProperty<CFGPart *> {
    public:
	    std::map<antlr4::tree::ParseTree *, CFGPart *>::const_iterator
		    begin() const { return _annotations.cbegin(); }
	    std::map<antlr4::tree::ParseTree *, CFGPart *>::const_iterator
		    end() const { return _annotations.cend(); }
    };
    ParseTreeProperty cfgs;

    struct Function {
	    QVector<CFGBreakNode *> rets;
	    QVector<QPair<QString, CFGBreakNode *>> gotos;
	    QMap<QString, CFGNode *> labels;
	    //QSet<QString> symbols;
    };

    struct IterSwitch {
	    IterSwitch() : hasDefault(false), isSwitch(false) { abort(); }
	    IterSwitch(bool isSwitch) : hasDefault(false), isSwitch(isSwitch) {}

	    QVector<CFGBreakNode *> breaks;
	    QVector<CFGBreakNode *> conts;
	    QVector<QPair<QString, CFGNode *>> cases;
	    bool hasDefault;
	    bool isSwitch;
    };

    QStack<Function> functionStack;
    QStack<IterSwitch> iterSwitchStack;

    antlr4::CommonTokenStream *tokens;

    static CFGNode *buildAssert(antlr4::ParserRuleContext *ctx, bool neg);
};

#endif
