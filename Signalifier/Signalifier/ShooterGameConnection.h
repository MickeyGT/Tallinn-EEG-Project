#ifndef SHOOTERGAMECONNECTION_H
#define SHOOTERGAMECONNECTION_H

#include <QThread>
#include <QUdpsocket>

#define MIN_SIGNAL_VALUE_INIT 10000;
#define MAX_SIGNAL_VALUE_INIT -10000;

class ShooterGameConnection : public QObject
{
	Q_OBJECT

public:
	ShooterGameConnection();

public slots:
	void processTimeDomainValues(const QVector<int>&);
	void processFftValues(const QPair<double, double>&);
	void notifyBitalinoFftMap(const bool&);

signals:
	void updateBitalinoDeviceFftFlag(const bool&);

private:
	QString getPercentage(const double& value);
	void	updateMinMaxValues(const double& value);

private:
	QUdpSocket*		_udpConnection;
	QHostAddress	_address;
	double			_minValue = MIN_SIGNAL_VALUE_INIT;
	double			_maxValue = MAX_SIGNAL_VALUE_INIT;
};

#endif