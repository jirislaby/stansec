#ifndef CFGLISTENER_H
#define CFGLISTENER_H

#include "CFG.h"
#include "CBaseListener.h"

#include <QMap>
#include <QString>

class CFGListener : public CBaseListener {

public:
    CFGListener();

    void enterFunctionDefinition(CParser::FunctionDefinitionContext *) override;
    void enterEveryRule(antlr4::ParserRuleContext *) override;
private:
    QMap<QString, CFG *> map;
};

#endif
