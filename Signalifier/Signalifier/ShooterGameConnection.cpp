#include "ShooterGameConnection.h"
#include "FftFactory.h"

ShooterGameConnection::ShooterGameConnection()
{
	_udpConnection = new QUdpSocket(this);
	_address.setAddress("192.168.1.7");
}

void ShooterGameConnection::processTimeDomainValues(const QVector<int>& data)
{
	FftFactory* factory = new FftFactory(data);
	QThread* gameThread = new QThread;
	factory->moveToThread(gameThread);

	QObject::connect(factory, SIGNAL(sendResult(const QPair<double, double>&)), this, SLOT(processFftValues(const QPair<double, double>&)));
	QObject::connect(factory, SIGNAL(isFftFactoryRunning(const bool&)), this, SLOT(notifyBitalinoFftMap(const bool&)));
	QObject::connect(gameThread, SIGNAL(started()), factory, SLOT(process()));
	QObject::connect(gameThread, SIGNAL(finished()), gameThread, SLOT(deleteLater()));

	gameThread->start();
}

void ShooterGameConnection::processFftValues(const QPair<double, double>& alphaThetaPair)
{
	double alphaThetaDivision = alphaThetaPair.first / alphaThetaPair.second;

	updateMinMaxValues(alphaThetaPair.second);
	QString percentage = getPercentage(alphaThetaPair.second);

	QByteArray dataByteArray;
	dataByteArray.append(percentage);

	qDebug() << percentage;

	_udpConnection->writeDatagram(dataByteArray, _address, 25000);
}

void ShooterGameConnection::notifyBitalinoFftMap(const bool& result)
{
	emit updateBitalinoDeviceFftFlag(result);
}


QString ShooterGameConnection::getPercentage(const double& value)
{
	double minValue = value - _minValue;
	double maxValue = _maxValue - _minValue;
	QString valueAsString;
	if (minValue == 0)
	{
		return "0";
	}
	else
	{
		double percentage = (minValue * 100) / maxValue;
		int integerPercentage = (int)percentage;
		valueAsString = QString::number(integerPercentage);
	}

	return valueAsString;
}

void ShooterGameConnection::updateMinMaxValues(const double& value)
{
	if (value > _maxValue)
	{
		_maxValue = value;
	}
	else if (value < _minValue)
	{
		_minValue = value;
	}
}
