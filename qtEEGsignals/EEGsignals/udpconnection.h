#ifndef UDPCONNECTION_H
#define UDPCONNECTION_H
#include <QObject>
#include <QUdpSocket>

class udpconnection : public QObject
{
	Q_OBJECT
public:
	explicit udpconnection(QObject *parent = 0);
	explicit udpconnection(const int &port, QObject *parent = 0);

	bool hasPendingDatagram();

	QByteArray getCurrentValue();

	void setPort(const double &UDPChannel);

signals:

	public slots :
		void readyRead();

private:
	//	void setPort(const QHostAddress &port);
	QHostAddress auxADR;
	QUdpSocket * socket;
	QByteArray currentValue;
};

#endif