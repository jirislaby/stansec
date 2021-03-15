#include "CFG.h"
#include "CFGNode.h"

#include <antlr4-runtime.h>

#include <QString>

CFG::CFG(antlr4::CommonTokenStream *tokens, CFGNode *startNode,
		CFGNode *endNode, QString &functionName) :
	CFGPart(tokens, startNode, endNode), line(), column(),
	functionName(functionName)
{
}

CFG::~CFG()
{
    for (auto n: getAllNodes())
        delete n;
}

/**
 * Creates a new instance of CFG
 *
 * @param cfgPart CFGPart to create CFG from
 * @param functionDefinition XML representation of a function definition
 * @return CFG created from CFGPart
 */
CFG *CFG::createFromCFGPart(CFGPart *cfgPart, QString &name)
{
#if 0
	List<String> params = new ArrayList<String>();
	for (int i = 1; i < linear.size(); ++i) {
		assert linear.get(i).getName().equals("id");
		params.add(linear.get(i).getText());
	}
#endif
	auto cfg = new CFG(cfgPart->getTokens(), cfgPart->getStartNode(),
			   cfgPart->getEndNode(), name);

	//cfg.setParams(params);
	//cfg->functionDefinition = functionDefinition;

	delete cfgPart;

	return cfg;
}

void CFG::setBoundaries(antlr4::misc::Interval intval)
{
	auto start = tokens->get(intval.a);
	auto end = tokens->get(intval.b);

	line[0] = start->getLine();
	line[1] = end->getLine();
	column[0] = start->getCharPositionInLine();
	column[1] = end->getCharPositionInLine() +
			end->getStopIndex() - end->getStartIndex();
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
