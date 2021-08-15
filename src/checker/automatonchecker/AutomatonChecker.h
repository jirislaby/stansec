#ifndef AUTOMATONCHECKER_H
#define AUTOMATONCHECKER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 *
 * Licensed under GPLv2.
 */

#include <QFile>
#include <QMap>
#include <QString>

#include "../Checker.h"
#include "AutomatonCheckerLogger.h"
#include "PatternLocation.h"
#include "XMLAutomatonDefinition.h"

class QDomDocument;

namespace checker {

class AutomatonChecker : public Checker {
public:
	typedef QMap<PatternLocation, int> PatternIds;

	AutomatonChecker() = delete;
	AutomatonChecker(QFile &xmlFile) : xmlFile(xmlFile) { }

	QString getName() override;

	virtual CheckingResult check(const codestructs::LazyInternalStructures &internals,
				     CheckerErrorReceiver &errReciver,
				     CheckerProgressMonitor &monitor) override;
	/*throws XMLAutomatonSyntaxErrorException*/

private:
#if 0
    int makePatternId(PatternIds patternids, StringBuilder sb, PatternLocation pattern) {
        if (!patternids.containsKey(pattern)) {
            sb.append("n").append(patternids.size()).append("[label=\"");
            for (AutomatonState state : pattern.getUnprocessedAutomataStates()){
                sb.append("[").append(state.toString()).append("]");
            }
            for (AutomatonState state : pattern.getProcessedAutomataStates()){
                sb.append("[").append(state.toString()).append("]");
            }
            sb.append(pattern.getCFGreferenceNode());
            sb.append("\"]").append(";\n");
            patternids.put(pattern, patternids.size());
            return patternids.size() - 1;
        } else
            return patternids.get(pattern);
    }

    void dumpNodeLocationGraph(Collection<Pair<PatternLocation, PatternLocation> > locs) {
        StringBuilder sb = new StringBuilder();
        sb.append("digraph G {\n");

	HashMap<PatternLocation, int> patternids = new HashMap<PatternLocation, int>();
        for (Pair<PatternLocation, PatternLocation> loc : locs) {
	    int firstId = makePatternId(patternids, sb, loc.getFirst());
	    int secondId = makePatternId(patternids, sb, loc.getSecond());
            for (PatternLocation succ : loc.getFirst().getSuccessorPatternLocations()) {
		int succId = makePatternId(patternids, sb, succ);
                sb.append("n").append(firstId).append("->").append("n").append(succId).append(";\n");
            }
            if (firstId != secondId) {
                sb.append("n").append(firstId).append("->").append("n").append(secondId).append(";\n");
                for (PatternLocation succ : loc.getSecond().getSuccessorPatternLocations()) {
		    int succId = makePatternId(patternids, sb, succ);
                    sb.append("n").append(secondId).append("->").append("n").append(succId).append(";\n");
                }
            }
        }

        sb.append("}");
        System.out.print(sb);
    }
#endif
    CheckingResult check(const std::unique_ptr<XMLAutomatonDefinition> xmlAutomatonDefinition,
			 const codestructs::LazyInternalStructures &internals,
			 CheckerErrorReceiver &errReceiver,
			 AutomatonCheckerLogger &monitor);
    //throws XMLAutomatonSyntaxErrorException
#if 0
    String getNodeUnitName(final CFGNode node,
                                   final LazyInternalStructures internals) {
        return Stanse.getUnitManager().getUnitName(
                    internals.getNodeToCFGdictionary().get(node));
    }

    String getLocationUnitName(final PatternLocation location,
                                   final LazyInternalStructures internals) {
        return getNodeUnitName(location.getCFGreferenceNode(),internals);
    }
#endif
    QFile &getXmlFile() {
        return xmlFile;
    }

    std::unique_ptr<QDomDocument> loadXMLdefinition();

    std::unique_ptr<XMLAutomatonDefinition>
    parseXMLAutomatondefinition(std::unique_ptr<QDomDocument> XMLdefinition);

    QFile &xmlFile;
};

}

#endif
