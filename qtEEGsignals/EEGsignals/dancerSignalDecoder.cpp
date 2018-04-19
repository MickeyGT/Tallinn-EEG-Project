#include "DancerSignalDecoder.h"

DancerSignalDecoder::DancerSignalDecoder()
{
}


DancerSignalDecoder::~DancerSignalDecoder()
{
}


QList<QVariant> DancerSignalDecoder::decodeSignal(const QByteArray &datagram)
{
//	qDebug() << datagram.toHex();
	QList<QVariant> dataList;
	QByteArray auxByteArray(datagram);
	QByteArray byte1 = auxByteArray.mid(0, 8);
	QByteArray byte2 = auxByteArray.mid(8, 8);
	QByteArray byte3 = auxByteArray.mid(16, 8);
	QByteArray byte4 = auxByteArray.mid(24, 8);
	QByteArray byte5 = auxByteArray.mid(32, 8);
	QByteArray byte6 = auxByteArray.mid(40, 8);
	QByteArray byte7 = auxByteArray.mid(48, 8);
	QByteArray byte8 = auxByteArray.mid(56, 8);

	double firstByte;
	QDataStream firstSignal(&byte1, QIODevice::ReadOnly);
	firstSignal.setByteOrder(QDataStream::LittleEndian);
	firstSignal >> firstByte;
	dataList.append(firstByte);
	//	qDebug() << firstByte;

	double secondByte;
	QDataStream secondSignal(&byte2, QIODevice::ReadOnly);
	secondSignal.setByteOrder(QDataStream::LittleEndian);
	secondSignal >> secondByte;
	dataList.append(secondByte);
	//	qDebug() << secondByte;

	double thirdByte;
	QDataStream thirdSignal(&byte3, QIODevice::ReadOnly);
	thirdSignal.setByteOrder(QDataStream::LittleEndian);
	thirdSignal >> thirdByte;
	dataList.append(thirdByte);
	//	qDebug() << thirdByte;

	double fourthByte;
	QDataStream fourthSignal(&byte4, QIODevice::ReadOnly);
	fourthSignal.setByteOrder(QDataStream::LittleEndian);
	fourthSignal >> fourthByte;
	dataList.append(fourthByte);
	//	qDebug() << fourthByte;

	double fifthByte;
	QDataStream fifthSignal(&byte5, QIODevice::ReadOnly);
	fifthSignal.setByteOrder(QDataStream::LittleEndian);
	fifthSignal >> fifthByte;
	dataList.append(fifthByte);
	//	qDebug() << fifthByte;

	double sixthByte;
	QDataStream sisxthSignal(&byte6, QIODevice::ReadOnly);
	sisxthSignal.setByteOrder(QDataStream::LittleEndian);
	sisxthSignal >> sixthByte;
	dataList.append(sixthByte);
	//	qDebug() << sixthByte;

	double seventhByte;
	QDataStream seventhSignal(&byte7, QIODevice::ReadOnly);
	seventhSignal.setByteOrder(QDataStream::LittleEndian);
	seventhSignal >> seventhByte;
	dataList.append(seventhByte);
	//	qDebug() << seventhByte;

	double eighthByte;
	QDataStream eighthSignal(&byte8, QIODevice::ReadOnly);
	eighthSignal.setByteOrder(QDataStream::LittleEndian);
	eighthSignal >> eighthByte;
	dataList.append(eighthByte);
	//	qDebug() << eighthByte;

	return dataList;
}