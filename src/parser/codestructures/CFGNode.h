#ifndef CFGNODE_H
#define CFGNODE_H

#include <antlr4-runtime.h>

#include <QList>
#include <QString>

class CFG;

/**
 * CFGNode -- Represents a node in control-flow graph (class ControlFlowGraph
 * in this package)
 */
class CFGNode {
public:

    class EdgeLabel final {
    public:
	    unsigned int edgeIndex;
	    void *cond;

	    EdgeLabel() : edgeIndex(0), cond(nullptr) { }

        EdgeLabel(unsigned int edgeIndex, void *cond)
		    : edgeIndex(edgeIndex), cond(cond) { }

	    QString toString() const {
		    return "(" + QString::number(edgeIndex) + ", " +
			    /*cond.toString() +*/ ")";
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

    CFGNode(CFG *cfg, const antlr4::misc::Interval &intvl);

    void addSucc(CFGNode *node) { succs.append(node); }
    void addPred(CFGNode *node) { preds.append(node); }

    antlr4::misc::Interval getIntvl() const { return intvl; }
    QString getCode() const;
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
    void *getEdgeLabel(unsigned int edge) const { return edgeLabels[edge]; }

    void addEdge(CFGNode *to);
    void addEdge(CFGNode *to, void *label);
    void addEdge(CFGNode *to, unsigned int edgeIndex, void *label);
    void addOptEdge(CFGNode *to);
    void replaceEdge(CFGNode *oldTo, CFGNode *newTo);
    void replaceOptEdge(CFGNode *oldTo, CFGNode *newTo);

    static unsigned int getNextNumber() { return numberCounter++; }

protected:
    void removeSucc(int index);

private:
    static unsigned int numberCounter;

    CFG *cfg;
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

    /**
     * Get all predecessors of the node
     * @return (read only) set of this node's predecessors
     */
    public List<CFGNode> getPredecessors() {
	return Collections.unmodifiableList(preds);
    }

    /**
     * Get all successors of the node
     * @return (read only) set of this node's successors
     */
    public List<CFGNode> getSuccessors() {
	return Collections.unmodifiableList(succs);
    }

    /**
     * Get all predecessors of the node
     * @return (read only) set of this node's predecessors
     */
    public List<CFGNode> getOptPredecessors() {
	return Collections.unmodifiableList(optPreds);
    }

    /**
     * Get all successors of the node
     * @return (read only) set of this node's successors
     */
    public List<CFGNode> getOptSuccessors() {
	return Collections.unmodifiableList(optSuccs);
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

    public void drop() {
	preds.clear();
	succs.clear();
	edgeLabels.clear();
	optPreds.clear();
	optSuccs.clear();
	element.clearContent();
	element = null;
	code = null;
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
    public int hashCode() {
	int hash = 5;
	hash = 59 * hash + number;
	return hash;
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
