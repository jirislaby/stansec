#ifndef TREEERRORMODEL_H
#define TREEERRORMODEL_H

/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include <QAbstractItemModel>
#include <QList>

#include "../checker/CheckerError.h"

namespace Ui {

class TreeErrorModel : public QAbstractItemModel
{
public:
	explicit TreeErrorModel(QObject *parent = nullptr);

	virtual QModelIndex index(int row, int column,
		      const QModelIndex &parent = QModelIndex()) const override;
	virtual QModelIndex parent(const QModelIndex &child) const override;

	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	void addError(const checker::CheckerError error) {
		beginInsertRows(QModelIndex(), errors.size(), errors.size() + 1);
		errors.append(error);
		endInsertRows();
	}
private:
	QList<checker::CheckerError> errors;

	enum {
		TRACE_SHIFT = 0,
		ERROR_SHIFT = 16,
		TRACE_MASK = 0xffff,
		ERROR_MASK = 0xffff,
		INVALID_AID = 0xffff,
	};

	static quintptr composeAid(unsigned int error, unsigned int trace) {
		return (error << 16) | trace;
	}
	static unsigned int errorNo(quintptr aid) {
		return (aid >> ERROR_SHIFT) & ERROR_MASK;
	}
	static unsigned int traceNo(quintptr aid) {
		return (aid >> TRACE_SHIFT) & TRACE_MASK;
	}
};

}

#endif // TREEERRORMODEL_H
