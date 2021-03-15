#ifndef CFGPART_H
#define CFGPART_H

#include <antlr4-runtime.h>

#include <QMap>
#include <QSet>

class CFGNode;

/**
 * CFGPart -- Represents a control-flow graph of a procedure
 */
class CFGPart {
public:
    CFGPart(antlr4::CommonTokenStream *tokens, CFGNode *startNode = nullptr,
                 CFGNode *endNode = nullptr);

    CFGNode *getStartNode() const { return startNode; }
    void setStartNode(CFGNode *n) { startNode = n; }

    CFGNode *getEndNode() const { return endNode; }
    void setEndNode(CFGNode *n) { endNode = n; }

    bool isEmpty() const { return getEndNode() == nullptr; }

    void append(CFGPart *g);
    void append(CFGNode *n);

    antlr4::CommonTokenStream *getTokens() const { return tokens; }

    QSet<CFGNode *> getAllNodes(bool optimized = false);
    QSet<CFGNode *> getAllNodesOpt() { return getAllNodes(true); }

    QString toDot(int shrink = 0);

protected:
    //QMap<unsigned int, CFGNode *> nodes;

    antlr4::CommonTokenStream *tokens;
    CFGNode *startNode;
    CFGNode *endNode;

private:
    void buildArcs(QString &sb, CFGNode *from, bool optimized);
};

#if 0
    public Set<CFGNode> getAllNodesReverse() {
	Set<CFGNode> nodesToDo = new HashSet<CFGNode>();
	Set<CFGNode> nodesDone = new LinkedHashSet<CFGNode>();

	nodesToDo.add(getEndNode());

	while (!nodesToDo.isEmpty()) {
	    CFGNode node = nodesToDo.iterator().next();
	    nodesToDo.remove(node);

	    nodesDone.add(node);

	    for (CFGNode pred: node.getPredecessors())
		if (!nodesDone.contains(pred))
		    nodesToDo.add(pred);
	}

	/* startNode might be unavailable, add it unconditionally */
	nodesDone.add(getStartNode());

	return nodesDone;
    }

    public void drop() {
	Set<CFGNode> nodes = getAllNodes();
	Set<CFGNode> nodesr = getAllNodesReverse();
	nodesr.removeAll(nodes);
	for (CFGNode n: nodes)
	    n.drop();
	for (CFGNode n: nodesr)
	    n.drop();
	setStartNode(null);
	setEndNode(null);
    }

    @Override
    public boolean equals(Object obj) {
	if (obj == null) {
	    return false;
	}
	if (getClass() != obj.getClass()) {
	    return false;
	}
	return true;
    }

    @Override
    public int hashCode() {
	int hash = super.hashCode();
	hash = 5 * hash + getStartNode().getNumber();
	hash = 7 * hash + getEndNode().getNumber();
	return hash;
    }

    @Override
    public String toString() {
	return Integer.toString(getStartNode().getNumber()) + "->...->" +
	    Integer.toString(getEndNode().getNumber());
    }

    /**
     * @brief Converts CFGPart to a string representation
     *
     * Useful for dumping to logs or console.
     *
     * @return string representation
     */
    public String toStringGraph() {
	StringBuilder sb = new StringBuilder();
	String eol = System.getProperty("line.separator");
	boolean shorten = false;

	for (CFGNode n: getAllNodes()) {
	    sb.append(n.toString());
	    Element e = n.getElement();
	    if (e != null) {
		sb.append(' ');
		sb.append(e.asXML());
	    }
	    int edge = 0;
	    for (CFGNode succ: n.getSuccessors()) {
		sb.append(eol);
		sb.append("  -");
		Object edgeLabel = n.getEdgeLabel(edge);
		if (edgeLabel instanceof Element) {
		    sb.append(((Element)edgeLabel).asXML());
		    sb.append('-');
		}
		edge++;
		sb.append("> ");
		sb.append(succ.toString());
	    }
	    sb.append(eol);
	    shorten = true;
	}

	if (shorten)
	    sb.setLength(sb.length() - 1);

	return sb.toString();
    }

#endif

#endif // CFGPART_H
