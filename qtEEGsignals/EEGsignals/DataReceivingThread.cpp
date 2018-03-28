#include "DataReceivingThread.h"



DataReceivingThread::DataReceivingThread()
{
	mFilePath = QDir::currentPath();
}


DataReceivingThread::~DataReceivingThread()
{
}

void DataReceivingThread::setUpConnection(const int &receivePort)
{
	mUDPconnection = new QUdpSocket(this);
	mUDPconnection->bind(QHostAddress::Any, receivePort);
	mUDPconnection->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 16);
	connect(mUDPconnection, SIGNAL(readyRead()), this, SLOT(processDatagram()));
}

void DataReceivingThread::setSendAddressAndPort(const QString &address, const QString &port)
{
	mSendAddress = address;
	mSendPort = port;
}

void DataReceivingThread::changeRecevingPort(const int &receivePort)
{
	bool ok = disconnect(mUDPconnection, SIGNAL(readyRead()), this, SLOT(processDatagram()));
	delete mUDPconnection;

	mUDPconnection = new QUdpSocket(this);
	mUDPconnection->bind(QHostAddress::Any, receivePort);
	mUDPconnection->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 16);
	connect(mUDPconnection, SIGNAL(readyRead()), this, SLOT(processDatagram()));
}