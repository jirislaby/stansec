#ifndef CFG_H
#define CFG_H

#include <antlr4-runtime.h>

#include <QList>
#include <QSet>

#include "CFGPart.h"

class CFGNode;

class CFG : public CFGPart {
public:
    CFG(antlr4::CommonTokenStream &tokens, CFGNode *startNode,
		    CFGNode *endNode, QString &functionName);

    QString getRetVar() const { return retvar; }
    void setRetVar(QString &value) { retvar = value; }

    static CFG *createFromCFGPart(CFGPart *cfgPart, void *functionDefinition);

protected:
    QString getFunctionName() const { return functionName; }


private:
    const QString functionName;
    QList<QString> params;
    QSet<QString> localSymbols;
    //private Element functionDefinition;
    QString retvar;
};

#endif // CFG_H
