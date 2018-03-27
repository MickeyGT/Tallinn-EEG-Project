#ifndef DATARECEIVINGTHREAD_H
#define DATARECEIVINGTHREAD_H
#include <QThread>
#include <QUdpsocket>
class DataReceivingThread : public QThread
{
	Q_OBJECT

public:
	DataReceivingThread();
	~DataReceivingThread();
	void setSendAddressAndPort(const QString &address, const QString &port);
	void changeRecevingPort(const int &receivePort);

	public slots:
		virtual void processDatagram() = 0;

	signals:
		void updatePlot(const QString &value);

protected:
	QString mSendPort;
	QHostAddress mSendAddress;
	QUdpSocket *mUDPconnection;


private:
	void setUpConnection(const int &receivePort);
};
#endif