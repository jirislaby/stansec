#ifndef CMDLINEMANAGER_H
#define CMDLINEMANAGER_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QObject>
#include <QString>
#include <QStringList>

#include "CheckerConfiguration.h"

class QCoreApplication;

namespace core {

class CmdLineManager : public QObject {
    Q_OBJECT

    // package-private section
public:
    CmdLineManager(QCoreApplication &a);

    QStringList positionalArguments() const { return _positionalArguments; }

    bool dumpCFG() const { return _dumpCFG; }

    QList<CheckerConfiguration> getCheckerConfiguration() const;

#if 0
    SourceConfiguration getSourceConfiguration() const;

    QString getOutputDir() const;

    Level getVerbosityLevel() const;

    bool infoMode();

    bool dumpAST() {
        return getOptions().has(dumpXML);
    }

    bool dumpCallGraph() {
        return getOptions().has(dumpCallGraph);
    }

    bool statsMode() {
        return getOptions().has(statsBuild)         ||
               getOptions().has(statsSort)          ||
               getOptions().has(statsGuiTracing)    ||
               getOptions().has(statsMerge)         ||
               getOptions().has(statsPerformance)   ||
               getOptions().has(statsReports)       ;
    }

    QString statsBuildFile() {
        return (getOptions().has(statsBuild)) ?
                    getOptions().valueOf(statsBuild) : null;
    }

    QString getStatsDatabase() {
        assert(statsMode());
        const OptionSpec<QString> option = getStatsDatabaseOption();
        assert(option != null);
        QString[] cc = getOptions().valueOf(option).split(":");
        const QString database = cc[0];
        return database;
    }

    bool doStatsGuiTracing() {
        return getOptions().has(statsGuiTracing);
    }

    QString statsGuiTracingOutputFile() {
        assert(getOptions().has(statsGuiTracing));
        QString[] cc = getOptions().valueOf(statsGuiTracing).split(":");
        if (cc.length < 2)
	    return null;
        return cc[1];
    }

    QString statsGuiTracingOrigSrcDir() {
        assert(getOptions().has(statsGuiTracing));
        QString[] cc = getOptions().valueOf(statsGuiTracing).split(":");
        if (cc.length != 4)
            return null;
        return cc[2];
    }

    QString statsGuiTracingCurrSrcDir() {
        assert(getOptions().has(statsGuiTracing));
        QString[] cc = getOptions().valueOf(statsGuiTracing).split(":");
        if (cc.length != 4)
            return null;
        return cc[3];
    }

    QString statsOrderingRootDir() {
        if (!getOptions().has(statsSort))
            return null;
        QString[] cc = getOptions().valueOf(statsSort).split(":");
	if (cc.length < 2)
	    return null;
        const QString orderingFile = cc[1];
        return orderingFile;
    }

    QList<QString> getStatsOrdering() {
        if (!getOptions().has(statsSort))
            return null;
        const QList<QString> ordering = new QList<QString>();
        QString[] cc = getOptions().valueOf(statsSort).split(":");
        for (int i = 2; i < cc.length; i++)
            ordering.add(cc[i]);
        return ordering;
    }

    bool doStatsMerge() {
        return getOptions().has(statsMerge);
    }

    QString getStatsMergeOutputFile() {
        assert(getOptions().has(statsMerge));
        QString[] cc = getOptions().valueOf(statsMerge).split(":");
        if (cc.length != 3)
	    return null;
        return cc[1];
    }

    QString getStatsMergeDirsRoot() {
        assert(getOptions().has(statsMerge));
        QString[] cc = getOptions().valueOf(statsMerge).split(":");
        if (cc.length != 3)
	    return null;
        return cc[2];
    }

    bool doStatsPerformance() {
        return getOptions().has(statsPerformance);
    }

    QString getStatsPerformanceOutputFile() {
        assert(getOptions().has(statsPerformance));
        QString[] cc = getOptions().valueOf(statsPerformance).split(":");
        if (cc.length != 3)
	    return null;
        return cc[1];
    }

    QString getStatsPerformanceOutputFormat() {
        assert(getOptions().has(statsPerformance));
        QString[] cc = getOptions().valueOf(statsPerformance).split(":");
        if (cc.length != 3)
	    return null;
        return cc[2];
    }

    bool doStatsReports() {
        return getOptions().has(statsReports);
    }

    QString getStatsReportsOutputFile() {
        assert(getOptions().has(statsReports));
        QString[] cc = getOptions().valueOf(statsReports).split(":");
        if (cc.length != 3)
	    return null;
        return cc[1];
    }

    QString getStatsReportsOutputFormat() {
        assert(getOptions().has(statsReports));
        QString[] cc = getOptions().valueOf(statsReports).split(":");
        if (cc.length != 3)
	    return null;
        return cc[2];
    }

    QString getStanseHome() {
        return getOptions().valueOf(stanseHome);
    }

private:

    OptionSpec<QString> getStatsDatabaseOption() {
        if (getOptions().has(statsSort)) return statsSort;
        if (getOptions().has(statsGuiTracing)) return statsGuiTracing;
        if (getOptions().has(statsMerge)) return statsMerge;
        if (getOptions().has(statsPerformance)) return statsPerformance;
        if (getOptions().has(statsReports)) return statsReports;
        return null;
    }

    const OptionSpec<QString> dir;
    const OptionSpec<QString> rdir;
    const OptionSpec<Void> dumpXML;
    const OptionSpec<Void> dumpCallGraph;
    const OptionSpec<File> outputDir;
    const OptionSpec<QString> statsBuild;
    const OptionSpec<QString> statsGuiTracing;
    const OptionSpec<QString> statsSort;
    const OptionSpec<QString> statsMerge;
    const OptionSpec<QString> statsPerformance;
    const OptionSpec<QString> statsReports;
    const OptionSpec<QString> stanseHome;
    const int numArgs;
#endif
private:
    bool _intraprocedural;
    QStringList _checkers;
    QString _makefile;
    QString _makeParams;
    QString _jobfile;
    bool _dumpCFG;
    int _debugLevel;
    QStringList _positionalArguments;
};

}

#endif
