#ifndef CFGNODE_H
#define CFGNODE_H

#include <antlr4-runtime.h>

#include <QList>
#include <QString>

class CFGPart;

/**
 * CFGNode -- Represents a node in control-flow graph (class ControlFlowGraph
 * in this package)
 */
class CFGNode {
public:

    class EdgeLabel final {
    public:
	    unsigned int edgeIndex;
        QString cond;

        EdgeLabel() : edgeIndex(0) { }

        EdgeLabel(unsigned int edgeIndex, const QString &cond)
		    : edgeIndex(edgeIndex), cond(cond) { }

	    QString toString() const {
            return "(" + QString::number(edgeIndex) + ", " + cond + ")";
	    }
    };

    enum OperandType { none, function, constant, varptr, varval, nodeval };

    class Operand final {
    public:
	    Operand(OperandType type, void *id) :
		    type(type), id(id) { }

	    Operand(QString &type, void *id);

	    QString toString() const {
            return QString::number(type) + " " /*+ id.toString()*/;
	    }

	    OperandType type;
	    void *id;
    };

    CFGNode(const antlr4::misc::Interval &intvl);
    virtual ~CFGNode();

    void addSucc(CFGNode *node) { succs.append(node); }
    void addPred(CFGNode *node) { preds.append(node); }

    antlr4::misc::Interval getIntvl() const { return intvl; }
    virtual QString getCode(const CFGPart *cfg) const;
    unsigned int getNumber() const { return number; }

    unsigned int getColumn() const { return column; }
    unsigned int getLine() const { return line; }

    bool isVisible() const { return visible; }
    void setVisible(bool value) { visible = value; }

    /**
     * getEdgeLabel -- Get label of a branch edge indexed from 0
     *
     * @param edge edge index
     * @return element which is the label
     */
    EdgeLabel *getEdgeLabel(unsigned int edge) const { return edgeLabels[edge]; }

    void addEdge(CFGNode *to);
    void addEdge(CFGNode *to, const QString &label);
    void addEdge(CFGNode *to, unsigned int edgeIndex, const QString &label);
    void addOptEdge(CFGNode *to);
    void replaceEdge(CFGNode *oldTo, CFGNode *newTo);
    void replaceOptEdge(CFGNode *oldTo, CFGNode *newTo);

    const QList<CFGNode *> getPredecessors()	{ return preds; }
    const QList<CFGNode *> getSuccessors()		{ return succs; }
    const QList<CFGNode *> getOptPredecessors()	{ return optPreds; }
    const QList<CFGNode *> getOptSuccessors()	{ return optSuccs; }

    static unsigned int getNextNumber() { return numberCounter++; }

protected:
    void removeSucc(int index);

private:
    static unsigned int numberCounter;

    const antlr4::misc::Interval intvl;
    unsigned int number;

    //Element element;
    //QString code;
    QList<CFGNode *> preds;
    QList<CFGNode *> succs;
    QList<EdgeLabel *> edgeLabels;
    QList<CFGNode *> optPreds;
    QList<CFGNode *> optSuccs;

    //QString nodeType = null;
    QList<Operand *> operands;
    //QFile file;
    unsigned int line;
    unsigned int column;
    bool visible;

};

class CFGJoinNode : public CFGNode {
public:
    CFGJoinNode(const antlr4::misc::Interval &intvl) : CFGNode(intvl) {};

    QString getCode(const CFGPart *) const override { return "JOIN"; }
};

class CFGAssertNode : public CFGNode {
public:
    CFGAssertNode(const antlr4::misc::Interval &intvl, bool neg) :
        CFGNode(intvl), neg(neg) {};

    QString getCode(const CFGPart *) const override;
private:
    bool neg;
};

class CFGAsmNode : public CFGNode {
public:
    CFGAsmNode(const antlr4::misc::Interval &intvl) :
        CFGNode(intvl) {};

    QString getCode(const CFGPart *) const override { return "asm"; }
};

#if 0
    public void setLocation(File file, int line, int column) {
        this.file = file;
	this.line = line;
	this.column = column;
    }

    public boolean hasLocation() {
	return file != null;
    }

    public File getFile() {
        return this.file;
    }

    public static Set<String> getDependentVars(Operand op) {
	Set<String> res = new java.util.HashSet<String>();
	if (op.type == OperandType.varptr || op.type == OperandType.varval)
	    res.add((String)op.id);
	else if (op.type == OperandType.nodeval)
	    res.addAll(((CFGNode)op.id).getDependentVars());
	return res;
    }

    public Set<String> getDependentVars() {
	Set<String> res = new java.util.HashSet<String>();
	for (Operand op : operands)
	    res.addAll(getDependentVars(op));
	return res;
    }

    public List<Operand> getOperands() {
	return Collections.unmodifiableList(operands);
    }

    public void setOperands(List<Operand> operands) {
	this.operands.clear();
	this.operands.addAll(operands);
    }

    public void addOperand(OperandType type, Object id) {
	operands.add(new Operand(type, id));
    }

    public String getNodeType() {
	return nodeType;
    }

    public void setNodeType(String nodeType) {
	this.nodeType = nodeType;
    }

    /**
     * Adds the node to the predecessors
     * @param pred new predecessor
     */
    protected void addPred(CFGNode pred) {
	preds.add(pred);
    }

    @Override
    public boolean equals(Object obj) {
    if (this == obj)
		return true;
	if (obj == null)
	    return false;
	if (getClass() != obj.getClass())
	    return false;
	final CFGNode other = (CFGNode)obj;
	if (number != other.getNumber())
	    return false;
	return true;
    }

    @Override
    public String toString() {
	String res = Integer.toString(number);
	if (nodeType != null)
		res += " " + nodeType.toString();
	for (Operand op : operands) {
	    res += "[" + op.toString() + "]";
	}
	return res;
    }
}
#endif

#endif // CFGNODE_H
