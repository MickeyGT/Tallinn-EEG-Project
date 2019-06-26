#ifndef SHOOTERGAMECONNECTION_H
#define SHOOTERGAMECONNECTION_H

#include <QThread>
#include <QUdpsocket>


class ShooterGameConnection : public QObject
{
	Q_OBJECT

public:
	ShooterGameConnection();

public slots:
	void processTimeDomainValues(const QVector<int>&);
	void processFftValues(const QPair<double, double>&);

private:
	QString getPercentage(const double& value);
	void	updateMinMaxValues(const double& value);

private:
	QUdpSocket*		_udpConnection;
	QHostAddress	_address;
	double			_minValue = 10000;
	double			_maxValue = -10000;
};

#endif