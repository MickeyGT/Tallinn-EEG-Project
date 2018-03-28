#include "AlphaThetaGameThread.h"
#include "AlphaThetaSignalDecoder.h"
#include <QPair>

AlphaThetaGameThread::AlphaThetaGameThread(const int &receivePort)
{
	mSendPort = "26000";
	mSendAddress.setAddress("192.168.0.5");
	setUpConnection(receivePort);
	mMinValue = 10000;
	mMaxValue = -10000;
	mFilePath += "/GameDataLogs.csv";
}


void AlphaThetaGameThread::processDatagram()
{
	QByteArray buffer;
	buffer.resize(mUDPconnection->pendingDatagramSize());

	mUDPconnection->readDatagram(buffer.data(), buffer.size());

	AlphaThetaSignalDecoder decoder;
	QPair<double , double> value = decoder.decodeSignal(buffer);

	if (value.first != 0 && value.second != 0)
	{
		double AlphaThetaDivision = value.first / value.second;
		updateMinMaxValue(AlphaThetaDivision);
		QString percentage = getPercentage(AlphaThetaDivision);

		QByteArray data;

		data.append(percentage);
		mUDPconnection->writeDatagram(data, mSendAddress, mSendPort.toInt());

		qDebug() << "sending percentage: " << percentage;

		emit(updatePlot(percentage));
	}
}



AlphaThetaGameThread::~AlphaThetaGameThread()
{
}

void AlphaThetaGameThread::updateMinMaxValue(const double &value)
{
	if (value == INFINITY)
	{
		int a;
		a = 3;
	}

	if (value > mMaxValue)
	{
		mMaxValue = value;
	}
	else if (value < mMinValue)
	{
		mMinValue = value;
	}
}

QString AlphaThetaGameThread::getPercentage(const double &value)
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