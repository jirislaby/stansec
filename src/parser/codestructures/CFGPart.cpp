#include <antlr4-runtime.h>

#include <QDebug>

#include "CFGNode.h"
#include "CFGPart.h"

CFGPart::CFGPart(antlr4::CommonTokenStream *tokens, CFGNode *startNode,
                 CFGNode *endNode)
	: tokens(tokens), startNode(startNode), endNode(endNode)
{
}

/**
 * Appends one CFG to the another
 * @param g a CFG to append at the end of this instance
 */
void CFGPart::append(CFGPart *g) {
    if (isEmpty()) {
        setStartNode(g->getStartNode());
        setEndNode(g->getEndNode());
    } else if (!g->isEmpty()) {
        getEndNode()->addEdge(g->getStartNode());
        setEndNode(g->getEndNode());
    }

    delete g;
}

/**
 * Appends one CFGNode to the CFG
 * @param n a CFGNode to append at the end of this CFG
 */
void CFGPart::append(CFGNode *n) {
    if (isEmpty()) {
        setStartNode(n);
        setEndNode(n);
        return;
    }
    getEndNode()->addEdge(n);
    setEndNode(n);
}

/**
 * @brief Converts CFGPart to a dot graph representation
 *
 * Useful for dumping cfgs to a file and generating e.g. PostScript from it.
 * See Graphviz software.
 *
 * @return dot representation stored in a string
 */
QString CFGPart::toDot(int shrink)
{
    auto allNodes = getAllNodesOpt();
    QString sb("digraph CFG {");

    sb.append("\n\tnode [shape=box];\n");

    for (auto n: allNodes) {
        sb.append('\t').
            append(QString::number(n->getNumber()));
#if 0
        Element e = n.getElement();
        if (e != null) {
            sb.append(" [label=\"");
            sb.append(n.getNumber());
            sb.append(": ");
            String label = e.getName();
            if (e.getName().equals("functionCall")) {
                Element funName = (Element)e.node(0);
                if (funName != null)
                    label = funName.getText();
            }
            sb.append(label);
            sb.append("\"];");
        }
#else
            sb.append(" [label=\"").
                append(QString::number(n->getNumber())).
		append(" (").append(QString::number(n->getLineStart(this))).
			    append(':').
			    append(QString::number(n->getColumnStart(this))).
			    append('-').
			    append(QString::number(n->getLineEnd(this))).
			    append(':').
			    append(QString::number(n->getColumnEnd(this))).

			    append(')').
		append(": ");
	    auto code = n->getCode(this);
	    if (shrink > 3 && code.length() > shrink) {
		    code.resize(shrink - 3);
		    code.append("...");
	    }
	    code.replace('\\', "\\\\").replace('"', "\\\"");
	    sb.append(code).
                append("\"];");
#endif
        sb.append('\n');
    }

    for (auto from: allNodes) {
        buildArcs(sb, from, false);
        buildArcs(sb, from, true);
    }

    sb.append("}");

    return sb;
}

QSet<CFGNode *> CFGPart::getAllNodes(bool optimized) {
    QSet<CFGNode *> nodesToDo;
    QSet<CFGNode *> nodesDone;

    if (!getStartNode()) {
        qWarning() << "no start node!";
        return nodesDone;
    }

    nodesToDo.insert(getStartNode());

    while (!nodesToDo.isEmpty()) {
        auto node = *nodesToDo.begin();
        nodesToDo.remove(node);

        nodesDone.insert(node);

        for (auto succ : node->getSuccessors())
            if (!nodesDone.contains(succ))
                nodesToDo.insert(succ);
        if (!optimized)
            continue;
        for (auto succ : node->getOptSuccessors())
            if (!nodesDone.contains(succ))
                nodesToDo.insert(succ);
    }

    /* endNode might be unavailable, add it unconditionally */
    nodesDone.insert(getEndNode());

    return nodesDone;
}

void CFGPart::buildArcs(QString &sb, CFGNode *from, bool optimized)
{
    int edge = 0;

    for (auto succ: optimized ? from->getOptSuccessors() : from->getSuccessors()) {
        sb.append('\t').append(QString::number(from->getNumber())).
                append(" -> ").
                append(QString::number(succ->getNumber()));
#if 1
        auto edgeLabel = from->getEdgeLabel(edge);
        sb.append(" [label=\"").
            append(edgeLabel->cond).
            append("\"]");
        edge++;
#else
        Object edgeLabel = from->getEdgeLabel(edge);
        if (edgeLabel instanceof Element) {
            sb.append(" [label=\"");
            Element label = (Element)edgeLabel;
            if (label.getName().equals("intConst"))
                sb.append(label.getText());
            else
                sb.append(label.getName());
            sb.append("\"]");
            edge++;
        }
#endif
        if (optimized)
            sb.append(" [style=dashed]");
        sb.append(';').append('\n');
    }
}

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
