#include "AlphaSignalDecoder.h"



AlphaSignalDecoder::AlphaSignalDecoder()
{
}


AlphaSignalDecoder::~AlphaSignalDecoder()
{
}

double AlphaSignalDecoder::decodeSignal(const QByteArray& datagram)
{	
	QByteArray auxByteArray(datagram);
	QByteArray byte1 = auxByteArray.mid(0, 8);
	QByteArray byte2 = auxByteArray.mid(8, 8);
	QByteArray byte3 = auxByteArray.mid(16, 8);
	QByteArray byte4 = auxByteArray.mid(24, 8);
	QByteArray byte5 = auxByteArray.mid(32, 8);
	QByteArray byte6 = auxByteArray.mid(40, 8);
	QByteArray byte7 = auxByteArray.mid(48, 8);
	QByteArray byte8 = auxByteArray.mid(56, 8);
	QByteArray byte9 = auxByteArray.mid(64, 8);

	double alpha1213;
	QDataStream firstSignal(&byte1, QIODevice::ReadOnly);
	firstSignal.setByteOrder(QDataStream::LittleEndian);
	firstSignal >> alpha1213;
	qDebug() << alpha1213;
	

	double alpha1112;
	QDataStream secondSignal(&byte2, QIODevice::ReadOnly);
	secondSignal.setByteOrder(QDataStream::LittleEndian);
	secondSignal >> alpha1112;
	qDebug() << alpha1112;

	double alpha1011;
	QDataStream thirdSignal(&byte3, QIODevice::ReadOnly);
	thirdSignal.setByteOrder(QDataStream::LittleEndian);
	thirdSignal >> alpha1011;
	qDebug() << alpha1011;

	double alpha910;
	QDataStream fourthSignal(&byte4, QIODevice::ReadOnly);
	fourthSignal.setByteOrder(QDataStream::LittleEndian);
	fourthSignal >> alpha910;
	qDebug() << alpha910;

	double alpha89;
	QDataStream fifthSignal(&byte5, QIODevice::ReadOnly);
	fifthSignal.setByteOrder(QDataStream::LittleEndian);
	fifthSignal >> alpha89;
	qDebug() << alpha89;

	double a;
	QDataStream ss(&byte6, QIODevice::ReadOnly);
	ss.setByteOrder(QDataStream::LittleEndian);
	ss >> a;
	qDebug() << a;

	double b;
	QDataStream aa(&byte7, QIODevice::ReadOnly);
	aa.setByteOrder(QDataStream::LittleEndian);
	aa >> b;
	qDebug() << b;

	double c;
	QDataStream bb(&byte8, QIODevice::ReadOnly);
	bb.setByteOrder(QDataStream::LittleEndian);
	bb >> c;
	qDebug() << c;

	double d;
	QDataStream uu(&byte9, QIODevice::ReadOnly);
	uu.setByteOrder(QDataStream::LittleEndian);
	uu >> d;
	qDebug() << d;

	return (-(alpha1213 * alpha1213) - alpha1112 + alpha910 + (alpha89 * alpha89));
}

double AlphaSignalDecoder::hexstr2double(const std::string& hexstr)
{
	union
	{
		long long i;
		double    d;
	} value;

	value.i = std::stoll(hexstr, nullptr, 16);

	return value.d;
}