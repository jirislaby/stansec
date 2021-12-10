#ifndef STARTFUNCTIONSSETBUILDER_H
#define STARTFUNCTIONSSETBUILDER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include "../LazyInternalStructures.h"

namespace clang {
class CallGraph;
}

namespace codestructs {

class StartFunctionsSetBuilder final {
public:
    static LazyInternalStructures::StartFunctions
    run(const LazyInternalStructures &internals,
	const clang::CallGraph &callGraph);

private:
    StartFunctionsSetBuilder() = delete;
};

}

#endif
