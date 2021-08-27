#ifndef LAZYINTERNALSTRUCTURESINTRA_H
#define LAZYINTERNALSTRUCTURESINTRA_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include "LazyInternalStructures.h"

namespace codestructs {

class LazyInternalStructuresIntra : public LazyInternalStructures {
public:
	LazyInternalStructuresIntra(clang::ento::AnalysisManager &mgr,
				    const clang::TranslationUnitDecl *TU) :
	    LazyInternalStructures(mgr, TU) { }

	virtual void setNavigator() override {
#if 0
	    if (navigator == null)
		navigator = new IntraproceduralCFGsNavigator(getCFGHandles());
#endif
	}
};

}

#endif
