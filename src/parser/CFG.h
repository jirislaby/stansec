#ifndef CFG_H
#define CFG_H

#include <antlr4-runtime.h>

#include <QList>
#include <QMap>

class CFG;

class CFGNode {
public:
    CFGNode(CFG *cfg, const antlr4::misc::Interval &intvl);

    void addSucc(CFGNode *node) { succs.append(node); }
    void addPred(CFGNode *node) { preds.append(node); }

    antlr4::misc::Interval getIntvl() const { return intvl; }
    QString getCode() const;
    unsigned int getNumber() const { return number; }

    static unsigned int getNextNumber() { return numberCounter++; }

private:
    static unsigned int numberCounter;

    CFG *cfg;
    const antlr4::misc::Interval intvl;
    unsigned int number;

    QList<CFGNode *> preds;
    QList<CFGNode *> succs;
#if 0
    QList<EdgeLabel *> edgeLabels = new ArrayList<EdgeLabel>();
    QList<CFGNode *> optPreds = new ArrayList<CFGNode>();
    QList<CFGNode *> optSuccs = new ArrayList<CFGNode>();
#endif
};

class CFG {
public:
    CFG(antlr4::CommonTokenStream &tokens, QString &name);

    antlr4::CommonTokenStream &getTokens() const { return tokens; }
    void addNode(CFGNode *);

    QString toDot();

private:
    QMap<unsigned int, CFGNode *> nodes;
    CFGNode *startNode;

    antlr4::CommonTokenStream &tokens;
    const QString name;
};

#endif // CFG_H
