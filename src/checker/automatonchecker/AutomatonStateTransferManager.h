#ifndef AUTOMATONSTATETRANSFERMANAGER_H
#define AUTOMATONSTATETRANSFERMANAGER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <llvm/ADT/Optional.h>

#include <QList>
#include <QStack>
#include <QString>

namespace clang {
class Stmt;
}

namespace codestructs {
class ArgumentPassingManager;
class CFGNode;
}

namespace checker {

class AutomatonState;
class CallSiteDetector;
class SimpleAutomatonID;
class ComposedAutomatonID;

class AutomatonStateTransferManager final {

    // package-private section
public:

    AutomatonStateTransferManager(codestructs::ArgumentPassingManager &passingManager,
				  const CallSiteDetector &callDetector) :
	passingManager(passingManager), callDetector(callDetector) {}

    llvm::Optional<AutomatonState>
    transfer(const codestructs::CFGNode &from, const AutomatonState &state,
	     const codestructs::CFGNode &to);

    llvm::Optional<ComposedAutomatonID>
    transfer(const codestructs::CFGNode &from, const ComposedAutomatonID &id,
	     const codestructs::CFGNode &to);

    llvm::Optional<SimpleAutomatonID>
    transfer(const codestructs::CFGNode &from, const SimpleAutomatonID &id,
	     const codestructs::CFGNode &to);

private:
    enum TransferType {
	    IDENTITY,
	    FROM_CALL,
	    TO_CALL,
    };

    bool isIdentityTransfer(const codestructs::CFGNode &from,
			    const codestructs::CFGNode &to) {
	return getTransferType(from, to) == IDENTITY;
    }

    TransferType getTransferType(const codestructs::CFGNode &from,
				 const codestructs::CFGNode &to);

    llvm::Optional<AutomatonState>
    transferFromCallToStartImpl(const codestructs::CFGNode &from,
				const checker::AutomatonState &state,
				const codestructs::CFGNode &to);

    llvm::Optional<AutomatonState>
    transferFromEndToCallImpl(const codestructs::CFGNode &from,
			      const checker::AutomatonState &state,
			      const codestructs::CFGNode &to);

    llvm::Optional<ComposedAutomatonID>
    transferImpl(const codestructs::CFGNode &from,
		 const checker::ComposedAutomatonID &id,
		 const codestructs::CFGNode &to);

    llvm::Optional<SimpleAutomatonID>
    transferImpl(const codestructs::CFGNode &from,
		 const SimpleAutomatonID &id,
		 const codestructs::CFGNode &to);

    const CallSiteDetector &getCallDetector() const { return callDetector; }
    codestructs::ArgumentPassingManager &
    getPassingManager() const { return passingManager; }

    codestructs::ArgumentPassingManager &passingManager;
    const CallSiteDetector &callDetector;
};

}

#endif
