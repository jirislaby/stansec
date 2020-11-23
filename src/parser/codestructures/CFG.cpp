#include "CFG.h"
#include "CFGNode.h"

#include <antlr4-runtime.h>

#include <QString>

CFG::CFG(antlr4::CommonTokenStream &tokens, CFGNode *startNode,
		CFGNode *endNode, QString &functionName) :
    CFGPart(tokens, startNode, endNode), functionName(functionName)
{
}

/**
 * Creates a new instance of CFG
 *
 * @param cfgPart CFGPart to create CFG from
 * @param functionDefinition XML representation of a function definition
 * @return CFG created from CFGPart
 */
CFG *CFG::createFromCFGPart(CFGPart *cfgPart, void */*functionDefinition*/)
{
#if 0
	List<Element> linear = XMLLinearizeASTElement.functionDeclaration(functionDefinition);
	assert linear.size() > 0;
	assert linear.get(0).getName().equals("id");

	String functionName = linear.get(0).getText();

	List<String> params = new ArrayList<String>();
	for (int i = 1; i < linear.size(); ++i) {
		assert linear.get(i).getName().equals("id");
		params.add(linear.get(i).getText());
	}
#else
    QString functionName("N/A");
#endif
    auto cfg = new CFG(cfgPart->getTokens(), cfgPart->getStartNode(),
                       cfgPart->getEndNode(), functionName);

	//cfg.setParams(params);
    //cfg->functionDefinition = functionDefinition;

	return cfg;
}

void CFG::addNode(CFGNode *node)
{
    nodes.insert(node->getNumber(), node);

    if (!startNode) {
        startNode = node;
        return;
    }

    startNode->addSucc(node);
}

QString CFG::toDot()
{
    QString sb("digraph CFG {");

    sb.append("\n\tnode [shape=box];\n");

    foreach (auto n, nodes) {
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
                append(": ").
                append(n->getCode()).
                append("\"];");
#endif
        sb.append('\n');
    }

    /*for (CFGNode from: allNodes) {
        buildArcs(sb, from, false, eol);
        buildArcs(sb, from, true, eol);
    }*/

    sb.append("}");

    return sb;
}


#if 0
    protected Element getElement() {
        if (functionDefinition != null && !functionDefinition.getName().equals("functionDefinition"))
	    throw new UnsupportedOperationException(
		    "wrong element in functionDefinition");
        return functionDefinition;
    }

    public void setParams(List<String> params) {
	this.params = params;
    }

    public void setSymbols(Set<String> symbols) {
	this.symbols = symbols;
    }

    public List<String> getParams() {
	assert this.params != null;
	return Collections.unmodifiableList(this.params);
    }

    public Set<String> getSymbols() {
	return Collections.unmodifiableSet(this.symbols);
    }

    public boolean isSymbolLocal(String symbol) {
	return symbols.contains(symbol);
    }

    @Override
    public boolean equals(Object obj) {
	if (obj == null) {
	    return false;
	}
	if (getClass() != obj.getClass()) {
	    return false;
	}
	final CFG other = (CFG)obj;
	return this.functionName.equals(other.functionName);
    }

    @Override
    public String toString() {
	return functionName + "(): " + super.toString();
    }
#endif
