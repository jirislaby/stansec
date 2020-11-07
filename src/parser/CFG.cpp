#include "CFG.h"

#include <antlr4-runtime.h>

#include <QString>

unsigned CFGNode::numberCounter;

CFGNode::CFGNode(CFG *cfg, const antlr4::misc::Interval &intvl) :
    cfg(cfg), intvl(intvl), number(getNextNumber())
{
}

QString CFGNode::getCode() const
{
    return QString(cfg->getTokens().getText(intvl).c_str());
}

CFG::CFG(antlr4::CommonTokenStream &tokens, QString &name) :
    startNode(nullptr), tokens(tokens), name(name)
{
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
