#ifndef ALPHASIGNALDECODER_H
#define ALPHASIGNALDECODER_H

#include <QDebug>
#include <QDataStream>
#include <QUdpSocket>
#include <QList>
class AlphaSignalDecoder
{
public:
	AlphaSignalDecoder();
	~AlphaSignalDecoder();
	double decodeSignal(const QByteArray& datagram);
};

#endif