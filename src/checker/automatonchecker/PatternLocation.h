#ifndef PATTERNLOCATION_H
#define PATTERNLOCATION_H

/**
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QSet>
#include <QString>

#include "../../codestructures/CFGNode.h"

#include "AutomatonState.h"
#include "ErrorRule.h"
#include "TransitionRule.h"

namespace clang {
class CFG;
class Stmt;
class SourceManager;
}

namespace checker {

class AutomatonStateTransferManager;

class PatternLocation final {

    // package-private section
public:
	PatternLocation(const codestructs::CFGNode &referenceNode,
			const QList<TransitionRule> transitionRules = QList<TransitionRule>(),
			const QList<ErrorRule> errorRules = QList<ErrorRule>(),
			AutomatonStateTransferManager *transferor = nullptr) :
	    CFGreferenceNode(referenceNode), transitionRules(transitionRules),
	    errorRules(errorRules), transferor(transferor) { }

	QList<PatternLocation *> &getSuccessorPatternLocations() {
	    return successorPatternLocations;
	}

	const QList<PatternLocation *> getSuccessorPatternLocations() const {
	    return successorPatternLocations;
	}

	const codestructs::CFGNode getCFGreferenceNode() const {
	    return CFGreferenceNode;
	}

	void setInitialAutomataStates(const QList<AutomatonState> initStates) {
	    // We can have a start function accepting locks as parameters
	    // assert(getUnprocessedAutomataStates().isEmpty());
	    getUnprocessedAutomataStates() << initStates;
	}

	bool hasUnprocessedAutomataStates() {
	    return !getUnprocessedAutomataStates().isEmpty();
	}

	const QSet<AutomatonState> &getProcessedAutomataStates() const {
	    return processedAutomataStates;
	}

	QSet<AutomatonState> &getProcessedAutomataStates() {
	    return processedAutomataStates;
	}

	const QSet<AutomatonState> &getDeliveredAutomataStates() const {
	    return deliveredAutomataStates;
	}

	QSet<AutomatonState> &getDeliveredAutomataStates() {
	    return deliveredAutomataStates;
	}

	const QList<TransitionRule> getTransitionRules() const {
	    return transitionRules;
	}

	const QList<ErrorRule> getErrorRules() const {
	    return errorRules;
	}

	QList<ErrorRule> &getErrorRules() {
	    return errorRules;
	}

	AutomatonStateTransferManager *getTransferor() const {
	    return transferor;
	}

	void setTransferor(AutomatonStateTransferManager *transferor) {
	    this->transferor = transferor;
	}

	PatternLocation *getLocationForCallNotPassedStates() const {
	    return locationForCallNotPassedStates;
	}

	void setLocationForCallNotPassedStates(PatternLocation *location) {
	    locationForCallNotPassedStates = location;
	}

	void fireLocalAutomataStates() {

	}

	bool processUnprocessedAutomataStates();

	void reduceStateSets() {
	    reduceStateSet(getProcessedAutomataStates());
	    reduceStateSet(getDeliveredAutomataStates());
	}

	QList<AutomatonState> &getUnprocessedAutomataStates() {
	    return unprocessedAutomataStates;
	}

	QString toString(const clang::SourceManager &SM);

private:

	void transformAutomataStateToSuccessors(const AutomatonState &state);
	QSet<AutomatonState> transformAutomatonState(const AutomatonState &state);
	void propagateStateToLocation(const AutomatonState &state,
				      PatternLocation *location);

	static void reduceStateSet(QSet<AutomatonState> &set);

	codestructs::CFGNode CFGreferenceNode;
	QSet<AutomatonState> processedAutomataStates;
	QList<AutomatonState> unprocessedAutomataStates;
	QSet<AutomatonState> deliveredAutomataStates;
	QList<PatternLocation *> successorPatternLocations;
	QList<TransitionRule> transitionRules;
	QList<ErrorRule> errorRules;

	AutomatonStateTransferManager *transferor;
	PatternLocation *locationForCallNotPassedStates = nullptr;

	PatternLocation() = delete;
};

}

#endif
