#include "udpconnection.h"
#include <qdebug.h>
#include <QHostAddress>
#include <QDataStream>
#include <QNetworkDatagram>

udpconnection::udpconnection(QObject *parent) :
	QObject(parent)
{
}

udpconnection::udpconnection(const int &port, QObject *parent) :
	QObject(parent)
{
	setPort(port);
}

void udpconnection::readyRead()
{
	QByteArray buffer;
	buffer.resize(socket->pendingDatagramSize());

	QHostAddress sender;
	quint16 senderPort;

	socket->readDatagram(buffer.data(), buffer.size(),
		&sender, &senderPort);

	quint8 mynumber;
	QDataStream readStream(&buffer, QIODevice::ReadOnly);
	readStream >> mynumber;

	currentValue = buffer;

	qDebug() << "Message from: " << sender.toString();
	qDebug() << "Message port: " << senderPort;
	qDebug() << "Message: " << sizeof(buffer);
}
//00 00 00 00 00 56 5d bf
// 00 00 00 00 00 d6 41 3f

bool udpconnection::hasPendingDatagram()
{
	return socket->hasPendingDatagrams();
}

QByteArray udpconnection::getCurrentValue()
{
	return currentValue;
}

void udpconnection::setPort(const double &UDPPort)
{
	//theres a last message on the port waiting
	socket = new QUdpSocket(this);
	socket->bind(QHostAddress::Any, UDPPort);
	socket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 2000000);
	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}