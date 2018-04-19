#include "MuseThread.h"
#include "MuseSignalDecoder.h"


MuseThread::MuseThread(const int &receivePort)
{
	mSendPort = "25000";
	mSendAddress.setAddress("192.168.0.5");
	setUpConnection(receivePort);
	mFilePath += "/MuseDataLogs.csv";
}


MuseThread::~MuseThread()
{
}

void MuseThread::processDatagram()
{
	QByteArray buffer;
	MuseSignalDecoder decoder;
	QtCSV::StringData csvData;
	QByteArray data;
	QString percentage;
	QList<QVariant> value;

	buffer.resize(mUDPconnection->pendingDatagramSize());

	mUDPconnection->readDatagram(buffer.data(), buffer.size());

	value = decoder.decodeSignal(buffer);


	csvData.addRow(percentage);
	QtCSV::Writer::write(mFilePath, csvData, ",", "\"", QtCSV::Writer::APPEND);

	data.append(percentage);
	mUDPconnection->writeDatagram(data, mSendAddress, mSendPort.toInt());

//	qDebug() << "sending percentage: " << percentage;

	emit(updatePlot(percentage));
}