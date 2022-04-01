#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/*
 * Copyright (c) 2008-2009 Marek Trtik
 * Copyright (c) 2021-2022 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QList>
#include <QMap>
#include <QPair>
#include <QString>

#include "CheckerConfiguration.h"

//#include "DummyEvaluationStatistic.h"
//#include "EvaluationStatistic.h"
//#include "SourceCodeFilesException.h"
//#include "FileListEnumerator.h"
//#include "LazyInternalStructures.h"
//#include "CheckingResult.h"
//#include "CheckingFailed.h"
//#include "CheckerError.h"
//#include "CheckerException.h"
//#include "CheckerErrorReceiver.h"
//#include "CheckerErrorTraceLocation.h"
//#include "CheckerProgressMonitor.h"
//#include "ClassLogger.h"
//#include "ColumnMessageFormatter.h"

namespace core {

class Configuration final {

public:
	Configuration() = delete;
#if 0
	Configuration() : sourceConfiguration(createDefaultSourceConfiguration()),
		checkerConfigurations(createDefaultCheckerConfiguration()) {}

	Configuration(const SourceConfiguration &sourceConfiguration) :
		sourceConfiguration(sourceConfiguration),
		checkerConfigurations(createDefaultCheckerConfiguration()) {}

	Configuration(const SourceConfiguration &sourceConfiguration,
		      const QList<CheckerConfiguration> &checkerConfiguration) {
		this.sourceConfiguration = sourceConfiguration;
		this.checkerConfigurations = checkerConfiguration;
	}

	void evaluate(const CheckerErrorReceiver &receiver,
			const CheckerProgressMonitor &monitor,
			const EvaluationStatistic &statistic);

	void evaluateWait(const CheckerErrorReceiver &receiver,
		const CheckerProgressMonitor &monitor,
		const EvaluationStatistic &statistic);
#endif
#ifdef NEEDED
	//@Deprecated
	void evaluate_EachUnitSeparately(const CheckerErrorReceiver receiver,
			const CheckerProgressMonitor monitor) {
		evaluate_EachUnitSeparately(receiver, monitor,
			new DummyEvaluationStatistic());
	}

	//@Deprecated
	void evaluate_EachUnitSeparately(const CheckerErrorReceiver receiver,
			const CheckerProgressMonitor monitor,
			const EvaluationStatistic statistic) {
		new java.lang.Thread() {
			@Override
			public void run() {
				evaluateWait_EachUnitSeparately(receiver, monitor, statistic);
			}
		}.start();
	}

	//@Deprecated
	void evaluateWait_EachUnitSeparately(const CheckerErrorReceiver receiver,
			const CheckerProgressMonitor monitor,
			const EvaluationStatistic statistic);
#endif
#if 0
	SourceConfiguration getSourceConfiguration() const {
		return sourceConfiguration;
	}
#endif
	QList<CheckerConfiguration> getCheckerConfigurations() const {
		return checkerConfigurations;
	}
#if 0
	static SourceConfiguration createDefaultSourceConfiguration() {
		return new SourceConfiguration(new FileListEnumerator({}));
	}
#endif

	static QList<CheckerConfiguration> createDefaultCheckerConfiguration() {
		return { };
	}

private:
#if 0
	void runChecker(const CheckerErrorReceiver &receiver,
			const EvaluationStatistic &statistic,
			const QList<int> &numCheckerConfigs,
			const CheckerConfiguration &checkerCfg,
			const MonitorForThread &monitor);

	CheckerErrorTraceLocation getFirstRealLoc(
			const QList<CheckerErrorTraceLocation> &locs) {
		CheckerErrorTraceLocation loc;
		int idx = 0;
		do {
			loc = locs.get(idx);
			idx++;
		} while (loc.getDescription().startsWith("<context>") &&
			idx < locs.size());
		return loc;
	}

	bool updateUniq(const QMap<QPair<int, QString>, CheckerError> &uniq,
			const CheckerErrorTraceLocation &loc,
			const CheckerError &error, const int newSize) {
		const auto &uniqEntry = qMakePair(loc.getLineNumber(), loc.getDescription());
		if (uniq.containsKey(uniqEntry)) {
			const auto &olderError = uniq.get(uniqEntry);
			if (olderError.getTraces().get(0).getLocations().size()
					> newSize) {
				uniq.put(uniqEntry, error);
			}
			return true;
		}
		uniq.put(uniqEntry, error);
		return false;
	}

	int filterUnitErrors(const QList<CheckerError> &unitErrors,
			     const CheckerErrorReceiver &receiver) {
		// const Map<Integer,Integer> errorCount = new QMap<Integer, Integer>();
		const QMap<QPair<int, QString>, CheckerError> uniqF;
		const QMap<QPair<int, QString>, CheckerError> uniqL;

		for (const auto &error : unitErrors) {
			const auto &locs = error.getTraces().get(0).getLocations();

			const auto &firstLoc = getFirstRealLoc(locs);
			const auto &lastLoc = locs.get(locs.size() - 1);

			/* we count only distinct errors below */
			bool dupF = updateUniq(uniqF, firstLoc, error, locs.size());
			bool dupL = updateUniq(uniqL, lastLoc, error, locs.size());

/*			if (!dupF && !dupL)
				continue;*/

			/* We don't count it yet, it should serve for "z-ranking"
			Integer count = errorCount.get(errorLoc);
			if (count == null)
			errorCount.put(errorLoc, Integer.valueOf(1));
			else
			count++;
			 */
		}
		int cnt = 0;
		/* do intersection of minimums */
		for (const auto &error : uniqL.values())
			if (uniqF.containsValue(error)) {
				receiver.receive(error);
				cnt++;
			}
		return cnt;
	}

	class MonitorForThread : public CheckerProgressMonitor final {

		MonitorForThread(int threadID, const CheckerProgressMonitor monitor) {
			super();
			formatter = new ColumnMessageFormatter("<" + threadID + "> ", 1);
			this.monitor = monitor;
		}

		@Override
		public void write(const QString s) {
			monitor.write(formatter.write(s + (s.endsWith("\n") ? "" : "\n")));
		}
		private const ColumnMessageFormatter formatter;
		private const CheckerProgressMonitor monitor;
	}

	class MonitoredThread : pubilc java.lang.Thread {

		MonitoredThread(const MonitorForThread monitor) {
			super();
			this.monitor = monitor;
		}

		const MonitorForThread getMonitor() {
			return monitor;
		}
		private:
		const MonitorForThread monitor;
	};

	QString getFailUnitName(const CheckerConfiguration &checkerCfg) {
		const LazyInternalStructures internals =
			checkerCfg.isInterprocedural()
			? getSourceConfiguration().getLazySourceInternals()
			: getSourceConfiguration().getLazySourceIntraproceduralInternals();
		return (internals.getUnits().size() == 1)
			? internals.getUnits().iterator().next().getName()
			: "<unknown>";
	}
	const SourceConfiguration sourceConfiguration;
#endif
	const QList<CheckerConfiguration> checkerConfigurations;
};

}

#endif
