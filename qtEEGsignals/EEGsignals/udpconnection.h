//This class creates a UDP connection between devices via QUdpSocket.
//It also has the functionality of receiving the datagram (readyRead() method) and storing it (currentyValue).

#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H
#include <QObject>
#include <QUdpSocket>

class UdpConnection : public QObject
{
	Q_OBJECT
public:
	explicit UdpConnection(QObject *parent = 0);
	/**
	* The constructor is overloaded so that we can create sockets on different ports right in EEGsignals.*
	**/
	explicit UdpConnection(const int &port, QObject *parent = 0);

	bool hasPendingDatagram();

	QByteArray getCurrentValue();

	void sendValues(const QByteArray & array , const QHostAddress &address, const int &port);
	/**
	*By calling the method the global sockey will be rebinded to another port.*
	*Note that if there are datagrams being sent on that port the bind will not work.*
	**/
	void setPort(const double &UDPChannel);

signals:

	public slots :
		void readyRead();

private:
	//	void setPort(const QHostAddress &port);

	QUdpSocket* mSocket;
	QByteArray  mCurrentValue;
};

#endif