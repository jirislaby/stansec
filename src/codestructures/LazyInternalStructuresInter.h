#ifndef LAZYINTERNALSTRUCTURESINTER_H
#define LAZYINTERNALSTRUCTURESINTER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include "InterproceduralCFGsNavigator.h"
#include "LazyInternalStructures.h"

namespace codestructs {

class LazyInternalStructuresInter : public LazyInternalStructures {
public:
    LazyInternalStructuresInter(clang::ento::AnalysisManager &mgr,
				const clang::TranslationUnitDecl *TU) :
	LazyInternalStructures(mgr, TU) { }

    virtual void setNavigator() override {
	assert(!navigator);
	navigator = new InterproceduralCFGsNavigator(getCFGHandles());
    }
};

}

#endif
