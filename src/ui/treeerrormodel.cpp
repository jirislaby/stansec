/*
 * Copyright (c) 2021 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

#include "treeerrormodel.h"

#include <QDebug>
#include <QString>

using namespace Ui;

TreeErrorModel::TreeErrorModel(QObject *parent) : QAbstractItemModel(parent)
{

}

QModelIndex TreeErrorModel::index(int row, int column, const QModelIndex &parent) const
{
	if (parent.isValid()) {
		auto parAid = parent.internalId();
		auto parErrorNo = errorNo(parAid);
		auto parTraceNo = traceNo(parAid);
		qDebug() << "row" << row << "columnt" << column << "parent" << parent;
		if (parTraceNo == INVALID_AID) {
			return createIndex(row, column, composeAid(parent.row(), INVALID_AID));
		} else {
			return createIndex(row, column, composeAid(parErrorNo, parent.row()));
		}
	} else
	    return createIndex(row, column, composeAid(INVALID_AID, INVALID_AID));
}

QModelIndex TreeErrorModel::parent(const QModelIndex &child) const
{
	auto aid = child.internalId();
	auto errNo = errorNo(aid);
	auto trNo = traceNo(aid);

	if (errNo == INVALID_AID)
	    return QModelIndex();

	if (trNo == INVALID_AID)
	    return createIndex(errNo, 0, composeAid(INVALID_AID, INVALID_AID));

	return createIndex(trNo, 0, composeAid(errNo, INVALID_AID));
}

int TreeErrorModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid()) {
		auto parAid = parent.internalId();
		const auto &traces = errors[errorNo(parAid)].getTraces();
		if (traceNo(parAid) == INVALID_AID)
		    return traces.size();
		return traces[traceNo(parAid)].getLocations().size();
	}

	return errors.size();
}

int TreeErrorModel::columnCount(const QModelIndex &parent) const
{
	return 1;

	if (parent.isValid()) {
		if (!parent.parent().isValid())
			return 1;
		return 1;
	}

	return 1;
}

QVariant TreeErrorModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::DisplayRole) {
		if (index.parent().isValid()) {
		    return QString::number(errors[index.parent().row()].getTraces().size());
		} else
			return errors[index.row()].getShortDesc();
	}

	return QVariant();
}
