#include "MuseSignalDecoder.h"
#include <QDebug>


MuseSignalDecoder::MuseSignalDecoder()
{
}


MuseSignalDecoder::~MuseSignalDecoder()
{
}

QList<QVariant> MuseSignalDecoder::decodeSignal(const QByteArray &datagram)
{
	qDebug() << datagram;
	return QList<QVariant>();
}