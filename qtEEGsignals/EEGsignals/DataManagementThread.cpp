#include <QDebug>
#include <QDir>
#include <QRandomGenerator>

#include "DataManagementThread.h"
#include "qtcsv/stringdata.h"
#include "qtcsv/reader.h"
#include "qtcsv/writer.h"
#include "DancerSignalDecoder.h"


DataManagementThread::~DataManagementThread()
{
}

DataManagementThread::DataManagementThread(const int &port) :
	mAbortFlag(false)
{
	setUpConnection(port);
	QPair<QVariant, QVariant> initPair = qMakePair(10000,-10000);
	for(int i = 0 ; i <= 7 ; ++i)
		signalMinMaxValues.append(initPair);
}


void DataManagementThread::processDatagram()
{
	QByteArray buffer;
	buffer.resize(mUDPconnection->pendingDatagramSize());

	mUDPconnection->readDatagram(buffer.data(), buffer.size());

	DancerSignalDecoder decoder;

	QList <QVariant> dataList = decoder.decodeSignal(buffer);

	qDebug() << buffer.toHex();

	updateSignalMinMaxValues(dataList);
	QString percentageList = getPercentage(dataList);

//	qDebug() << "sent value is : " << percentageList;
	QByteArray data;
	data.append(percentageList);
	mUDPconnection->writeDatagram(data, QHostAddress("192.168.0.5"), 56789);
//	emit(updatePlot(value));
}

void DataManagementThread::setUpConnection(const int &port)
{
	mUDPconnection = new QUdpSocket(this);
	mUDPconnection->bind(QHostAddress::Any, port);
	mUDPconnection->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 200000000);
	connect(mUDPconnection, SIGNAL(readyRead()), this, SLOT(processDatagram()));
}

void DataManagementThread::startStopConnection(const bool &flag)
{
	if (flag)
		mUDPconnection->disconnect();
	else
	{
		mUDPconnection = new QUdpSocket(this);
		mUDPconnection->bind(QHostAddress::Any, 25000);
		mUDPconnection->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 2000000);
		connect(mUDPconnection, SIGNAL(readyRead()), this, SLOT(processDatagram()));
	}
}

void DataManagementThread::updateSignalMinMaxValues(const QList<QVariant> &list)
{
	const int listSize = signalMinMaxValues.size();
	for (int i = 0 ; i < listSize ; ++ i)
	{
		if (list[i] < signalMinMaxValues.at(i).first)
		{
			signalMinMaxValues[i].first = list.at(i);
		}	
		else if (list[i] > signalMinMaxValues.at(i).second)
		{
			signalMinMaxValues[i].second = list.at(i);
		}
	}
}

QString DataManagementThread::getPercentage(const QList<QVariant> &list)
{
	const int listSize = signalMinMaxValues.size();
	QString percentageList;
	for (int i = 0; i < listSize; ++i)
	{
		double minimumValue = list.at(i).toInt() - signalMinMaxValues[i].first.toInt();
		double maximumValue = signalMinMaxValues[i].second.toInt() - signalMinMaxValues[i].first.toInt();
		if (minimumValue == 0)
		{
			percentageList += "0";
		}
		else
		{
			double division = (maximumValue / minimumValue);
			double percentage = 100 / division;
			int integerPercentage = (int)percentage;
			QString valueAsString = QString::number(integerPercentage);
			percentageList += valueAsString;
			percentageList += " ";
		}
	}
	return percentageList;
}