#include "GameThread.h"
#include "AlphaSignalDecoder.h"

GameThread::GameThread(const int &receivePort)
{
	mSendPort = "25000";
	mSendAddress.setAddress("192.168.0.5");
	setUpConnection(receivePort);
	mMinValue = 10000;
	mMaxValue = -10000;
	mFilePath += "/GameDataLogs.csv";
}


GameThread::~GameThread()
{
}


void GameThread::processDatagram()
{
	QByteArray buffer;
	AlphaSignalDecoder decoder;
	QtCSV::StringData csvData;
	QByteArray data;
	QString percentage;
	double value;

	buffer.resize(mUDPconnection->pendingDatagramSize());

	mUDPconnection->readDatagram(buffer.data(), buffer.size());
	
	value = decoder.decodeSignal(buffer);

	updateMinMaxValue(value);
	percentage = getPercentage(value);
	
	csvData.addRow(percentage);
	QtCSV::Writer::write(mFilePath, csvData, ",", "\"", QtCSV::Writer::APPEND);

	data.append(percentage);
	mUDPconnection->writeDatagram(data, mSendAddress, mSendPort.toInt());

	qDebug() << "sending percentage: " << percentage;

	emit(updatePlot(percentage));
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