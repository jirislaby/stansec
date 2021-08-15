/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QString>

#include "../../codestructures/ArgumentPassingManager.h"

#include "AutomatonState.h"
#include "AutomatonStateContextAlgo.h"
#include "AutomatonStateTransferManager.h"
#include "CallSiteDetector.h"
#include "ComposedAutomatonID.h"
#include "SimpleAutomatonID.h"

using namespace checker;

llvm::Optional<ComposedAutomatonID>
AutomatonStateTransferManager::transferImpl(const codestructs::CFGNode &from,
					    const ComposedAutomatonID &id,
					    const codestructs::CFGNode &to)
{
	QList<SimpleAutomatonID> transformedIDs;

	for (const auto &simpleID : id.getSimpleAutomataIDs()) {
		const auto transformedID = transferImpl(from, simpleID, to);
		if (!transformedID)
			return llvm::Optional<ComposedAutomatonID>();
		transformedIDs.append(*transformedID);
	}

	return ComposedAutomatonID(transformedIDs);
}

llvm::Optional<SimpleAutomatonID>
AutomatonStateTransferManager::transferImpl(const codestructs::CFGNode &from,
					    const SimpleAutomatonID &id,
					    const codestructs::CFGNode &to) {
    if (id.isGlobal())
	return id;

    QList<QString> transformedVarsAssignments;

    for (const auto &varsAssignment : id.getVarsAssignment()) {
	const auto transformedVarAssign = getPassingManager().pass(from,
								   varsAssignment,
								   to);

	if (!transformedVarAssign)
	    return llvm::Optional<SimpleAutomatonID>();

	transformedVarsAssignments.append(*transformedVarAssign);
    }

    return SimpleAutomatonID(transformedVarsAssignments, id.isGlobal());
}

llvm::Optional<AutomatonState>
AutomatonStateTransferManager::transfer(const codestructs::CFGNode &from,
					const AutomatonState &state,
					const codestructs::CFGNode &to) {
	switch (getTransferType(from, to)) {
	case FROM_CALL:
		return transferFromCallToStartImpl(from, state, to);
	case TO_CALL:
		return transferFromEndToCallImpl(from, state, to);
	default:
		return state;
	}
}

llvm::Optional<ComposedAutomatonID>
AutomatonStateTransferManager::transfer(const codestructs::CFGNode &from,
					const ComposedAutomatonID &id,
					const codestructs::CFGNode &to)
{
	assert(from.hasStmt());
	if (isIdentityTransfer(from, to))
		return id;

	return transferImpl(from, id, to);
}

llvm::Optional<SimpleAutomatonID>
AutomatonStateTransferManager::transfer(const codestructs::CFGNode &from,
					const SimpleAutomatonID &id,
					const codestructs::CFGNode &to)
{
	assert(from.hasStmt());
	if (isIdentityTransfer(from, to))
		return id;

	return transferImpl(from, id, to);
}

AutomatonStateTransferManager::TransferType
AutomatonStateTransferManager::getTransferType(const codestructs::CFGNode &from,
					       const codestructs::CFGNode &to)
{
	if (getPassingManager().isIdentityPass(from, to))
		return IDENTITY;
	if (getCallDetector().isCallNode(from))
		return FROM_CALL;
	if (getCallDetector().isCallNode(to))
		return TO_CALL;
	return IDENTITY;
}

llvm::Optional<AutomatonState>
AutomatonStateTransferManager::transferFromCallToStartImpl(const codestructs::CFGNode &from,
							   const AutomatonState &state,
							   const codestructs::CFGNode &to)
{
	assert(from.hasStmt());
	const auto transformedID = transferImpl(from,
						state.getAutomatonID(), to);

	if (!transformedID ||
			!AutomatonStateContextAlgo::canPush(state.getContext(),
							    from,
							    *transformedID))
		return llvm::Optional<AutomatonState>();

	auto context = state.getContext();
	context.push(AutomatonStateContextItem(from, *transformedID));
	return AutomatonState(state.getSymbol(), context);
}

llvm::Optional<AutomatonState>
AutomatonStateTransferManager::transferFromEndToCallImpl(const codestructs::CFGNode &from,
							 const AutomatonState &state,
							 const codestructs::CFGNode &to)
{
	assert(to.hasStmt());
	if (to != state.getCFGNode())
	    return llvm::Optional<AutomatonState>();

	auto context = state.getContext();
	context.pop();
	if (context.isEmpty())
	    return llvm::Optional<AutomatonState>();

	return AutomatonState(state.getSymbol(), context);
}
