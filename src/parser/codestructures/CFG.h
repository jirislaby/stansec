#ifndef CFG_H
#define CFG_H

#include <antlr4-runtime.h>

#include <QList>
#include <QSet>

#include "CFGPart.h"

class CFGNode;

class CFG : public CFGPart {
public:
    CFG(antlr4::CommonTokenStream *tokens, CFGNode *startNode,
		    CFGNode *endNode, QString &functionName);
    ~CFG();

    QString getRetVar() const { return retvar; }
    void setRetVar(QString &value) { retvar = value; }

    unsigned int getColumnStart() const	{ return column[0]; }
    unsigned int getLineStart() const	{ return line[0]; }
    unsigned int getColumnEnd() const	{ return column[1]; }
    unsigned int getLineEnd() const	{ return line[1]; }

    static CFG *createFromCFGPart(CFGPart *cfgPart, QString &name);
    void setBoundaries(antlr4::misc::Interval intval);

protected:
    QString getFunctionName() const { return functionName; }


private:
    int line[2];
    int column[2];

    const QString functionName;
    QList<QString> params;
    QSet<QString> localSymbols;
    //private Element functionDefinition;
    QString retvar;
};

#endif // CFG_H
