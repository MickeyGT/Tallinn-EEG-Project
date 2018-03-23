#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <QThread>
#include <QTimer>
#include <QUdpsocket>
#include <QPair>

#include "qcustomplot.h"
#include "Utility.h"

class GameThread : public QThread
{
	Q_OBJECT

public:
	GameThread(const int &receivePort);
	~GameThread();

	void setUpConnection(const int &receivePort);
	void setSendAddressAndPort(const QString &address, const QString &port);
	void changeRecevingPort(const int &receivePort);

	public slots :
	void processDatagram();

signals:
	void updatePlot(const QString &value);

private:

	QHostAddress sendAddress;
	QString sendPort;
	QUdpSocket *mUDPconnection;

	double mMinValue;
	double mMaxValue;

	void updateMinMaxValue(const double &value);
	QString getPercentage(const double &value);
};
#endif