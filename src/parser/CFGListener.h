#ifndef CFGLISTENER_H
#define CFGLISTENER_H

#include "CBaseListener.h"

class CFGListener : public CBaseListener {

public:
    CFGListener();

    void enterFunctionDefinition(CParser::FunctionDefinitionContext *) override;
    void enterEveryRule(antlr4::ParserRuleContext *) override;
};

#endif
