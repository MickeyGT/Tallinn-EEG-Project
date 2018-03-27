#include <QDebug>

#include "DancerThread.h"
#include "DancerSignalDecoder.h"


DancerThread::~DancerThread()
{
}

DancerThread::DancerThread(const int &receivePort)
{
	mSendPort = "56789";
	mSendAddress.setAddress("192.168.0.5");
	setUpConnection(receivePort);
	initSignalMinMaxValue();
}


void DancerThread::processDatagram()
{
	QByteArray buffer;
	buffer.resize(mUDPconnection->pendingDatagramSize());

	mUDPconnection->readDatagram(buffer.data(), buffer.size());

	DancerSignalDecoder decoder;

	QList <QVariant> dataList = decoder.decodeSignal(buffer);

	updateSignalMinMaxValues(dataList);
	QString percentageList = getPercentage(dataList);

	qDebug() << "sent value is : " << percentageList;
	QByteArray data;
	data.append(percentageList);
	mUDPconnection->writeDatagram(data, mSendAddress, mSendPort.toInt());
	
	if (dataList.first().toInt() >= MINIMUMBORDER && dataList.first().toInt() <= MAXIMUMBORDER)
		emit(updatePlot(dataList.first().toString()));
}

void DancerThread::setUpConnection(const int &receivePort)
{
	mUDPconnection = new QUdpSocket(this);
	mUDPconnection->bind(QHostAddress::Any, receivePort);
	mUDPconnection->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 16);
	connect(mUDPconnection, SIGNAL(readyRead()), this, SLOT(processDatagram()));
}

void DancerThread::changeRecevingPort(const int &receivePort)
{
	bool ok = disconnect(mUDPconnection, SIGNAL(readyRead()), this, SLOT(processDatagram()));
	delete mUDPconnection;

	mUDPconnection = new QUdpSocket(this);
	mUDPconnection->bind(QHostAddress::Any, receivePort);
	mUDPconnection->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 16);
	connect(mUDPconnection, SIGNAL(readyRead()), this, SLOT(processDatagram()));
}

QString DancerThread::getPercentage(const QList<QVariant> &list)
{
	const int listSize = signalMinMaxValues.size();
	QString percentageList;
	for (int i = 0; i < listSize; ++i)
	{
		double minimumValue = list.at(i).toDouble() - signalMinMaxValues[i].first.toDouble();
		double maximumValue = signalMinMaxValues[i].second.toDouble() - signalMinMaxValues[i].first.toDouble();
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

void DancerThread::initSignalMinMaxValue()
{
	QPair<QVariant, QVariant> initPair = qMakePair(10000, -10000);
	for (int i = 0; i <= 7; ++i)
		signalMinMaxValues.append(initPair);
}

void DancerThread::setSendAddressAndPort(const QString &address, const QString &port)
{
	mSendAddress = address;
	mSendPort = port;
}

void DancerThread::updateSignalMinMaxValues(const QList<QVariant> &list)
{
	const int listSize = signalMinMaxValues.size();
	const int receivedListSize = list.size();
	if (receivedListSize == listSize)
	{
		for (int i = 0; i < listSize; ++i)
		{
			if (list[i] < signalMinMaxValues.at(i).first /*&& list[i] > MINIMUMBORDER*/)
			{
				signalMinMaxValues[i].first = list.at(i);
			}
			else if (list[i] > signalMinMaxValues.at(i).second /*&& list[i] < MAXIMUMBORDER*/)
			{
				signalMinMaxValues[i].second = list.at(i);
			}
		}
	}
}
