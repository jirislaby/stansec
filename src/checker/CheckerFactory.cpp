/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include "automatonchecker/AutomatonCheckerCreator.h"
#include "reachabilitychecker/ReachabilityCheckerCreator.h"

#include "CheckerFactory.h"

using namespace checker;

const CheckerFactory::CreatorMap CheckerFactory::creatorsDictionary({
	{ checkerCreatorPair(new AutomatonCheckerCreator()) },
	{ checkerCreatorPair(new ReachabilityCheckerCreator()) }
});
