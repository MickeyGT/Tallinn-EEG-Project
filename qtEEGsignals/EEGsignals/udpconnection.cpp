#include "udpconnection.h"
#include <qdebug.h>
#include <QHostAddress>
#include <QDataStream>
#include <QNetworkDatagram>

UdpConnection::UdpConnection(QObject *parent) :
	QObject(parent)
{
}

UdpConnection::UdpConnection(const int &port, QObject *parent) :
	QObject(parent)
{
	
	setPort(port);
}

void UdpConnection::readyRead()
{
	QByteArray buffer;
	buffer.resize(mSocket->pendingDatagramSize());

	QHostAddress sender;
	quint16 senderPort;

	mSocket->readDatagram(buffer.data(), buffer.size(),
		&sender, &senderPort);

	quint8 mynumber;
	QDataStream readStream(&buffer, QIODevice::ReadOnly);
	readStream >> mynumber;

	mCurrentValue = buffer;

	qDebug() << "Message from: " << sender.toString();
	qDebug() << "Message port: " << senderPort;
	qDebug() << "Message: " << sizeof(buffer);
}
//00 00 00 00 00 56 5d bf
// 00 00 00 00 00 d6 41 3f

bool UdpConnection::hasPendingDatagram()
{
	return mSocket->hasPendingDatagrams();
}

QByteArray UdpConnection::getCurrentValue()
{
	return mCurrentValue;
}

void UdpConnection::setPort(const double &UDPPort)
{
	//theres a last message on the port waiting
	mSocket = new QUdpSocket(this);
	mSocket->bind(QHostAddress::Any, UDPPort);
	mSocket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 2000000);
	connect(mSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}