#include "DataManagementThread.h"
#include <qDebug>
#include <QRandomGenerator>

DataManagementThread::DataManagementThread()
{
}


DataManagementThread::~DataManagementThread()
{
}

DataManagementThread::DataManagementThread(DynamicSpline *spline , const int &port)
{
	mMainWindowSpline = spline;

	mUDPconnection = new QUdpSocket(this);
	mUDPconnection->bind(QHostAddress::Any, port);
	mUDPconnection->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 2000000);
	connect(mUDPconnection, SIGNAL(readyRead()), this, SLOT(readyRead()));
}


void DataManagementThread::readyRead()
{
	
	QByteArray buffer;
	buffer.resize(mUDPconnection->pendingDatagramSize());

	QHostAddress sender;
	quint16 senderPort;

	mUDPconnection->readDatagram(buffer.data(), buffer.size(),
		&sender, &senderPort);

	mCurrentValue = buffer;
}

void DataManagementThread::run()
{
	forever
	{
		qDebug() << "i am thread number" << this->currentThreadId;
		this->sleep(2);
		qDebug() << "getting message" << mCurrentValue.toHex();
		mMainWindowSpline->setSignalYValue(QRandomGenerator::global()->bounded(5) - 2.5);
	}
}