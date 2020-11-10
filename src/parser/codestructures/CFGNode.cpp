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

CFGNode::CFGNode(CFG *cfg, const antlr4::misc::Interval &intvl) :
    cfg(cfg), intvl(intvl), number(getNextNumber()), visible(true)
{
}

QString CFGNode::getCode() const
{
    return QString(cfg->getTokens().getText(intvl).c_str());
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
void CFGNode::addEdge(CFGNode *to, void *label)
{
    succs.append(to);
    edgeLabels.append(new EdgeLabel(0, label));
    to->addPred(this);
}

/**
 * Adds an edge between two nodes
 * @param to which node to add the edge to
 */
void CFGNode::addEdge(CFGNode *to, unsigned int edgeIndex, void *label)
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

