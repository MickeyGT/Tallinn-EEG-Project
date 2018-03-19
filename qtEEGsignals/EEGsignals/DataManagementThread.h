#ifndef DATAMANAGEMENTTHREAD_H
#define DATAMANAGEMENTTHREAD_H
#include <QThread>
#include <QTimer>
#include <QUdpsocket>
#include <QPair>

#include "qcustomplot.h"
#include "Utility.h"

class DataManagementThread : public QThread
{
	Q_OBJECT

public:
	
	DataManagementThread(const int &port);
	~DataManagementThread();
	void setUpConnection(const int &port);
	void startStopConnection(const bool &flag);

	public slots :
	void processDatagram();

signals:
	void updatePlot(const QString &value);

private:
	QList < QPair<QVariant , QVariant> > signalMinMaxValues;
	bool mAbortFlag;
	QCustomPlot *mainWindowRealTimePlot;
	QUdpSocket *mUDPconnection;

	void updateSignalMinMaxValues(const QList<QVariant> &list);
	QString getPercentage(const QList<QVariant> &list);
};
#endif