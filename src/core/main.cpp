/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QString>

#include "CmdLineManager.h"
#include "stansec.h"
#include "mainwindow.h"

using namespace core;

int main(int argc, char *argv[])
{
    bool GUI = argc > 0 && QString(argv[0]).contains("-qt");

    Stansec stansec(argc, argv, GUI);

    return stansec.startUI();
}
