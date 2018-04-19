#include "AlphaThetaSignalDecoder.h"
#include <QPair>
#include <QDebug>

AlphaThetaSignalDecoder::AlphaThetaSignalDecoder()
{
}


AlphaThetaSignalDecoder::~AlphaThetaSignalDecoder()
{
}

QPair<double , double> AlphaThetaSignalDecoder::decodeSignal(const QByteArray &datagram)
{
	QByteArray auxByteArray(datagram);
	QByteArray byte1 = auxByteArray.mid(0, 8);
	QByteArray byte2 = auxByteArray.mid(8, 8);

//	qDebug() << datagram;

	double alpha;
	QDataStream firstSignal(&byte1, QIODevice::ReadOnly);
	firstSignal.setByteOrder(QDataStream::LittleEndian);
	firstSignal >> alpha;

	double theta;
	QDataStream secondSignal(&byte2, QIODevice::ReadOnly);
	secondSignal.setByteOrder(QDataStream::LittleEndian);
	secondSignal >> theta;

	return qMakePair(alpha, theta);
}