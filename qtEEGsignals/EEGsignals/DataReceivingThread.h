/*Base class for every thread that has the functioanlity of a data receiving object(via UDP).*/
#ifndef DATARECEIVINGTHREAD_H
#define DATARECEIVINGTHREAD_H
#include <QThread>
#include <QUdpsocket>
#include <QDir>

#include "qtcsv/stringdata.h"
#include "qtcsv/reader.h"
#include "qtcsv/writer.h"

class DataReceivingThread : public QThread
{
	Q_OBJECT

public:
	DataReceivingThread();
	~DataReceivingThread();
	/*Method used to change the udp ip address and port to which the thread sends the data.*/
	void setSendAddressAndPort(const QString &address, const QString &port);
	/*Method used to change the udp port from which the thread reads datagrams.*/
	void changeRecevingPort(const int &receivePort);

	public slots:
		/*Every thread that is "data receiving" should implement its own way of proccessing the data.*/
		virtual void processDatagram() = 0;

	signals:
		/*Sends a signal to EEGsignals(main class) with the value with which the coresponding plot will be updated*/
		void updatePlot(const QString &value);

protected:
	/*Contains the path to the root of the project. Threads will individually update this variable and will use it to log data.*/
	QString mFilePath;
	/*The udp port that is used to send data.*/
	QString mSendPort;
	/*The udp ip address that is used to send data.*/
	QHostAddress mSendAddress;
	/*Initialization proccess : bind the socket to any ip address and the receiving port , increase the buffer size and connect it to the processDatagram SLOT of every thread.*/
	void setUpConnection(const int &receivePort);


	QUdpSocket *mUDPconnection;

private:
	
};
#endif