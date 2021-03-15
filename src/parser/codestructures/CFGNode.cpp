#include "CFG.h"
#include "CFGNode.h"

#include <antlr4-runtime.h>

#include <QString>

CFGNode::Operand::Operand(QString &type, void *id) :
	id(id)
{
    if (type == "func")
        this->type = CFGNode::OperandType::function;
    else if (type == "const")
        this->type = CFGNode::OperandType::constant;
    else if (type == "varptr")
        this->type = CFGNode::OperandType::varptr;
    else if (type == "var")
        this->type = CFGNode::OperandType::varval;
    else if (type == "node")
        this->type = CFGNode::OperandType::nodeval;
	else
        assert(false);
}

unsigned CFGNode::numberCounter;

CFGNode::CFGNode(const antlr4::misc::Interval &intvl) :
    intvl(intvl), number(getNextNumber()), visible(true)
{
}

CFGNode::~CFGNode()
{
    for (auto el: edgeLabels)
        delete el;
}

QString CFGNode::getCode(const CFGPart *cfg) const
{
    static const QChar noSpace[] = { ';', '(', ')' };
    QString ret;

    for (auto tok: cfg->getTokens()->getTokens(intvl.a, intvl.b)) {
        QString tokStr(tok->getText().c_str());
        if (!ret.isEmpty()) {
            bool addSpace = true;
            for (auto ch: noSpace)
                if (tokStr == ch) {
                    addSpace = false;
                    break;
                }
            if (addSpace)
                ret.append(' ');
        }
        ret.append(tokStr);
    }

    return ret;
    //return QString(cfg->getTokens().getText(intvl).c_str());
}

unsigned int CFGNode::getColumnStart(const CFGPart *cfg) const
{
	return cfg->getTokens()->get(intvl.a)->getCharPositionInLine();
}

unsigned int CFGNode::getLineStart(const CFGPart *cfg) const
{
	return cfg->getTokens()->get(intvl.a)->getLine();
}

unsigned int CFGNode::getColumnEnd(const CFGPart *cfg) const
{
	auto tok = cfg->getTokens()->get(intvl.b);

	return tok->getCharPositionInLine() + tok->getText().length();
}

unsigned int CFGNode::getLineEnd(const CFGPart *cfg) const
{
	return cfg->getTokens()->get(intvl.b)->getLine();
}

/**
 * Adds an edge between two nodes
 * @param to which node to add the edge to
 */
void CFGNode::addEdge(CFGNode *to)
{
    succs.append(to);
    edgeLabels.append(new EdgeLabel());
    addPred(this);
}

/**
 * Adds an edge between two nodes
 * @param to which node to add the edge to
 */
void CFGNode::addEdge(CFGNode *to, const QString &label)
{
    succs.append(to);
    edgeLabels.append(new EdgeLabel(0, label));
    to->addPred(this);
}

/**
 * Adds an edge between two nodes
 * @param to which node to add the edge to
 */
void CFGNode::addEdge(CFGNode *to, unsigned int edgeIndex, const QString &label)
{
    succs.append(to);
    edgeLabels.append(new EdgeLabel(edgeIndex, label));
    to->addPred(this);
}

/**
 * Adds an optimized edge between two nodes (is in code, not in CFG)
 * @param to which node to add the edge to
 */
void CFGNode::addOptEdge(CFGNode *to) {
    optSuccs.append(to);
    optPreds.append(this);
}

/**
 * Replaces an edge between two nodes with a new edge
 * @param oldTo which node to replace
 * @param newTo which node use as a replacement
 */
void CFGNode::replaceEdge(CFGNode *oldTo, CFGNode *newTo) {
    auto idx = succs.indexOf(oldTo);
    succs.replace(idx, newTo);
    newTo->addPred(this);
}

/**
 * Replaces an edge between two nodes with a new edge
 * @param oldTo which node to replace
 * @param newTo which node use as a replacement
 */
void CFGNode::replaceOptEdge(CFGNode *oldTo, CFGNode *newTo) {
	auto idx = optSuccs.indexOf(oldTo);
    optSuccs.replace(idx, newTo);
    newTo->optPreds.append(this);
}

/**
 * Removes the node from the successors
 * @param index the index of the element to be removed
 */
void CFGNode::removeSucc(int index) {
    succs.removeAt(index);
}

QString CFGAssertNode::getCode(const CFGPart *cfg) const
{
    QString ret("assert(");

    if (neg)
        ret.append("!(");

    ret.append(CFGNode::getCode(cfg));

    if (neg)
        ret.append(')');

    ret.append(')');

    return ret;
}
