#ifndef CFG_H
#define CFG_H

#include <QMap>

class CFGNode {
};

class CFG {
public:
    CFG(QString &name);

private:
    QMap<int, CFGNode> nodes;
};

#endif // CFG_H
