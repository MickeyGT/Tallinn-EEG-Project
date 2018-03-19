#include <QDebug>
#include <QHostAddress>
#include <QDataStream>
#include <QNetworkDatagram>

#include "UdpConnection.h"

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

	mCurrentValue = buffer;
}

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
	mSocket = new QUdpSocket(this);
	mSocket->bind(QHostAddress::Any, UDPPort);
	mSocket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 2000000);
	connect(mSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void UdpConnection::sendValues(const QByteArray &array , const QHostAddress &address , const int &port)
{
	mSocket->writeDatagram(array, address, port);
}