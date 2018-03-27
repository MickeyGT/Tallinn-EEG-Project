#ifndef DANCERTHREAD_H
#define DANCERTHREAD_H
#include <QThread>
#include <QTimer>
#include <QUdpsocket>
#include <QPair>


#include "Utility.h"

class DancerThread : public QThread
{
	#define MINIMUMBORDER - 1000
	#define MAXIMUMBORDER	1000

	Q_OBJECT

public:
	
	DancerThread(const int &receivePort);
	~DancerThread();
	void setUpConnection(const int &receivePort);
	void setSendAddressAndPort(const QString &address, const QString &port);
	void changeRecevingPort(const int &receivePort);

	public slots :
	void processDatagram();

	signals:
	void updatePlot(const QString &value);

private:

	QHostAddress mSendAddress;
	QString mSendPort;
	QUdpSocket *mUDPconnection;

	QList < QPair<QVariant, QVariant> > signalMinMaxValues;
	void initSignalMinMaxValue();
	void updateSignalMinMaxValues(const QList<QVariant> &list);
	QString getPercentage(const QList<QVariant> &list);
};
#endif