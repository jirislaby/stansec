#ifndef CFGLISTENER_H
#define CFGLISTENER_H

#include "CFG.h"
#include "CBaseListener.h"

#include <QMap>
#include <QString>

class CFGListener : public CBaseListener {

public:
    CFGListener(antlr4::CommonTokenStream &tokens);

    void enterFunctionDefinition(CParser::FunctionDefinitionContext *) override;
    void exitFunctionDefinition(CParser::FunctionDefinitionContext *) override;
    void enterEveryRule(antlr4::ParserRuleContext *) override;

    void enterExpression(CParser::ExpressionContext *) override;
    void exitExpression(CParser::ExpressionContext *) override;

    QString getDot(const QString &fun) {
        const auto cfg = map[fun];
        return cfg ? cfg->toDot() : QString();
    }

private:
    //antlr4::tree::ParseTreeProperty<> props;
    QMap<QString, CFG *> map;
    CFG *currentCFG;

    antlr4::CommonTokenStream &tokens;
};

#endif
