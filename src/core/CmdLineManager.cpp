/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QString>

#include "CmdLineManager.h"
#include "Configuration.h"

//#include "SourceConfiguration.h"
//#include "MakefileSourceEnumerator.h"
//#include "FileListEnumerator.h"
//#include "BatchFileEnumerator.h"

using namespace core;

CmdLineManager::CmdLineManager(QCoreApplication &a)
{
    QCommandLineParser parser;

    parser.addHelpOption();
    parser.addVersionOption();

    /*
     * TODO: following option switches between (inter/intra)procedural analyses.
     * But it does it globaly per all the checkers. This should be rewriten to
     * enable swiching these options per checker.
     */
    QCommandLineOption intraprocedural("intraprocedural", tr("Use simpler "
	     "intraprocedural analysis instead of much more complex "
	     "interprocedural analysis. Affects all checkers."));
    parser.addOption(intraprocedural);

    QCommandLineOption checkers({ "c", "checker" }, tr("Checker name and (possibly) configuration. "
				"Can be used multiple times."),
		    "name[[:configuration_file1]:"
		    "configuration_file2:name ...]");
    parser.addOption(checkers);

    QCommandLineOption makefile("makefile", tr("Makefile specifying input files."),
				tr("file"));
    parser.addOption(makefile);
    QCommandLineOption makeParams("make-params", tr("Parameters passed to the make tool."),
				  tr("parameters"));
    parser.addOption(makeParams);

    QCommandLineOption jobfile("jobfile", tr("Jobfile specifying input files."),
		    tr("file"));
    parser.addOption(jobfile);

    QCommandLineOption dumpCFG("dump-cfg", tr("Dump control flow graphs in Dot format."));
    parser.addOption(dumpCFG);

    QCommandLineOption debugLevel({ "d", "debug-level" }, tr("Sets the debug level."),
		    tr("n"), "-1");
    parser.addOption(debugLevel);

    parser.addPositionalArgument(tr("sources"),
				 tr("Sources to check"),
				 tr("[sources...]"));
    parser.process(a);

    _intraprocedural = parser.isSet(intraprocedural);
    _checkers = parser.values(checkers);
    _makefile = parser.value(makefile);
    _makeParams = parser.value(makeParams);
    _jobfile = parser.value(jobfile);
    _dumpCFG = parser.isSet(dumpCFG);
    _debugLevel = parser.value(debugLevel).toInt();


    _positionalArguments = parser.positionalArguments();

#if 0
        dir =
              parser.accepts("dir","Directory to be (non-recursively) " +
                                   "searched for input files.")
                    .withRequiredArg()
                    .describedAs("directory")
                    .ofType(QString.class);
        rdir =
              parser.accepts("rdir","Directory to be recursively searched " +
                                    "for input files.")
                    .withRequiredArg()
                    .describedAs("directory")
                    .ofType(QString.class);

    	dumpXML =
              parser.accepts("dump-xml",
                             "Dump XML representation of AST");
        dumpCallGraph =
              parser.accepts("dump-callgraph",
                             "Dump callgraph in Dot format");

        outputDir =
              parser.accepts("output-dir",
                             "Sets the output directory for generated files")
                    .withRequiredArg()
                    .describedAs("directory")
                    .ofType(File.class);

        statsBuild =
              parser.accepts("stats-build","Builds statistical data in XML " +
                                           "format of processed checking. " +
                                           "Output file for statistical data " +
                                           "must be provided as an argument")
                    .withRequiredArg()
                    .describedAs("file")
                    .ofType(QString.class);
        statsGuiTracing =
              parser.accepts("stats-err-guitracing",
                             "Loads statistical database file and parses all " +
                             "its error messages and deliveres them into " +
                             "Stanse's GUI to enable easy error-tracing. It " +
                             "is also possible to specify relocation of " +
                             "source code files by specifying original and " +
                             "current location (directory) of souces. "+
                             "Original reports are updated by user-defined "+
                             "resolution state and are written to the " +
                             "output file.")
                    .withRequiredArg()
                    .describedAs("XMLdatabaseFile:outputFile" +
                                 "[:Original-sources-dir:Current-sources-dir]")
                    .ofType(QString.class);
        statsSort =
              parser.accepts("stats-err-sort",
                             "Loads statistical database file and then it " +
                             "will sort error messages by lexicografical " +
                             "order defined by these keywords: " +
                             "checker_name (checker name), " +
                             "description (short description of report), " +
                             "unit (unit of error report), " +
                             "importance (importance). Output consists of " +
                             "directory tree with information files (.txt) " +
                             "and data files (.xml). Root of this directory " +
                             "structure is passed as the second argument here.")
                    .withRequiredArg()
                    .describedAs("XMLdatabaseFile:" +
                                 "outputDirectory:SortKeyword1:" +
                                 "SortKeyword2 ...")
                    .ofType(QString.class);
        statsMerge =
              parser.accepts("stats-err-merge",
                             "Loads statistical database file and all XML " +
                             "file in specified directory. All these files " +
                             "combined (merged) to form one output XML " +
                             "database file. Merge is realized this way. " +
                             "Content of sections 'files','internals', " +
                             "'checkers' and 'checkfails' are simply copied" +
                             "from original database file. The last section " +
                             "'errors' is computed by simple concatenation " +
                             "of contents of 'errors' sections in XML files " +
                             "inside specified directory structure. Content " +
                             "of 'errors' section in original database file " +
                             "does not participate in this merge of 'errors' " +
                             "sections.")
                    .withRequiredArg()
                    .describedAs("XMLdatabaseFile:" +
                                 "outputDatabaseFile:RootOfDirectoryStructure")
                    .ofType(QString.class);
        statsPerformance =
              parser.accepts("stats-performance",
                             "Loads statistical database file and then it " +
                             "searched in the data to collect all performace " +
                             "information. Collected performance data are " +
                             "then written into specified output file, in " +
                             "specified output format. Valid formats are: " +
                             "simple-text (human-readable simple text file)")
                    .withRequiredArg()
                    .describedAs("XMLdatabaseFile:" +
                                 "outputFile:OutputFormat")
                    .ofType(QString.class);
        statsReports =
              parser.accepts("stats-reports",
                             "Loads statistical database file and then it " +
                             "searched in the data to collect all reports " +
                             "related information. Collected data are " +
                             "then written into specified output file, in " +
                             "specified output format. Valid formats are: " +
                             "simple-text (human-readable simple text file)")
                    .withRequiredArg()
                    .describedAs("XMLdatabaseFile:" +
                                 "outputFile:OutputFormat")
                    .ofType(QString.class);
        stanseHome =
              parser.accepts("home",
                             "")
                    .withRequiredArg()
                    .describedAs("dir")
                    .ofType(QString.class);

        numArgs = args.length;
#endif
    }
#if 0
    SourceConfiguration getSourceConfiguration() {
        if (getOptions().has(makefile))
            return new SourceConfiguration(new MakefileSourceEnumerator(
                            getOptions().valueOf(makefile),
                            getOptions().has(makeParams) ?
                                getOptions().valueOf(makeParams) : ""));
        if (getOptions().has(jobfile))
            return new SourceConfiguration(new BatchFileEnumerator(
                            getOptions().valueOf(jobfile)));
        if (getOptions().has(dir))
            return new SourceConfiguration(new DirectorySourceEnumerator(
                            getOptions().valueOf(dir),"c",false));
        if (getOptions().has(rdir))
            return new SourceConfiguration(new DirectorySourceEnumerator(
                            getOptions().valueOf(dir),"c",true));
        if (!getOptions().nonOptionArguments().isEmpty())
            return new SourceConfiguration(new FileListEnumerator(
                            getOptions().nonOptionArguments()));
        return Configuration.createDefaultSourceConfiguration();
    }
#endif
QList<CheckerConfiguration> CmdLineManager::getCheckerConfiguration() const
{
    if (_checkers.isEmpty())
	return Configuration::createDefaultCheckerConfiguration();

    QList<CheckerConfiguration> checkerConfiguration;
    for (const auto &s: _checkers) {
	auto cc = s.split(":");
	const auto &checkerName = cc.takeFirst();
	checkerConfiguration.append(
	    CheckerConfiguration(checkerName, cc, !_intraprocedural));
    }
    return checkerConfiguration;
}
#if 0
    QString getOutputDir() {
        return getOptions().has(outputDir) ? getOptions().valueOf(outputDir)
                                                         .toString() :
                                             null;
    }

	Level getVerbosityLevel() {
		if (!getOptions().has(debugLevel))
			return Level.INFO;
		switch (getOptions().valueOf(debugLevel)) {
		case 0:
			return Level.ERROR;
		case 1:
			return Level.WARN;
		default:
			System.err.println("Illegal verbosity level. Falling "
				+ "back to the default - 2");
		case 2:
			return Level.INFO;
		case 3:
			return Level.DEBUG;
		}
	}

    bool infoMode() {
        return numArgs == 0 || getOptions().has(help)
                            || getOptions().has(version);
    }

    void printInfo(const java.io.OutputStream sink) {
        if (numArgs == 0 || getOptions().has(help))
            try {
		getParser().printHelpOn(sink);
	    } catch (const java.io.IOException e) {
		System.err.println("Can't print help");
	    }
        if (getOptions().has(version))
            try {
		new java.io.DataOutputStream(sink).writeChars(
                          Stanse.class.getPackage().getImplementationVersion());
            } catch (const java.io.IOException e) {
		System.err.println("Can't print version");
	    }
    }

    bool dumpAST() {
        return getOptions().has(dumpXML);
    }

    bool dumpCFG() {
        return getOptions().has(dumpCFG);
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

    QPair<QString,QString> getUIdesc() {
	if (!getOptions().has(gui))
	    return QPair.make("TUI","");
	QString value = getOptions().valueOf(gui);
	if (value == null)
	    value = "default";
        return QPair.make("GUI", value);
    }

    public QString getStanseHome() {
        return getOptions().valueOf(stanseHome);
    }

private:

    private OptionSet getOptions() {
        return options;
    }

    private OptionParser getParser() {
        return parser;
    }

    private OptionSpec<QString> getStatsDatabaseOption() {
        if (getOptions().has(statsSort)) return statsSort;
        if (getOptions().has(statsGuiTracing)) return statsGuiTracing;
        if (getOptions().has(statsMerge)) return statsMerge;
        if (getOptions().has(statsPerformance)) return statsPerformance;
        if (getOptions().has(statsReports)) return statsReports;
        return null;
    }
#endif
