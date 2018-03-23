#include "GameThread.h"

#include "AlphaSignalDecoder.h"

GameThread::GameThread(const int &receivePort)
{
	sendPort = "56789";
	sendAddress.setAddress("192.168.0.5");
	setUpConnection(receivePort);
	mMinValue = 10000;
	mMaxValue = -10000;
}


GameThread::~GameThread()
{
}


void GameThread::processDatagram()
{
	QByteArray buffer;
	buffer.resize(mUDPconnection->pendingDatagramSize());

	mUDPconnection->readDatagram(buffer.data(), buffer.size());

	AlphaSignalDecoder decoder;

	double value = decoder.decodeSignal(buffer);

	updateMinMaxValue(value);
	QString percentage = getPercentage(value);

	QByteArray data;
	data.append(percentage);
	mUDPconnection->writeDatagram(data, sendAddress, sendPort.toInt());

	qDebug() << "sending percentage: " << percentage;

	emit(updatePlot(percentage));
}

void GameThread::setUpConnection(const int &receivePort)
{
	mUDPconnection = new QUdpSocket(this);
	mUDPconnection->bind(QHostAddress::Any, receivePort);
	mUDPconnection->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 16);
	connect(mUDPconnection, SIGNAL(readyRead()), this, SLOT(processDatagram()));
}

void GameThread::updateMinMaxValue(const double &value)
{
	if (value > mMaxValue)
	{
		mMaxValue = value;
	}
	else if (value < mMinValue)
	{
		mMinValue = value;
	}
}

QString GameThread::getPercentage(const double &value)
{
	double minValue = value - mMinValue;
	double maxValue = mMaxValue - mMinValue;
	if (minValue == 0)
	{
		return "0";
	}
	else
	{
		double percentage = (minValue * 100) / maxValue;
		int integerPercentage = (int)percentage;
		QString valueAsString = QString::number(integerPercentage);
		return valueAsString;
	}
}