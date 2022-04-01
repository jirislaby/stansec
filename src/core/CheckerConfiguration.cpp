/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include "../checker/Checker.h"
#include "../checker/CheckerFactory.h"

#include "CheckerConfiguration.h"

using namespace core;

std::unique_ptr<checker::Checker> CheckerConfiguration::getChecker() /*throws CheckerException*/
{
    return interprocedural ?
		checker::CheckerFactory::createInterprocedural(getCheckerClassName(),
						     getCheckerArgumentsList()) :
		checker::CheckerFactory::createIntraprocedural(getCheckerClassName(),
						     getCheckerArgumentsList());
}
