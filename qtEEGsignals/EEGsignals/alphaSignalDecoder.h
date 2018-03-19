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
	QVariant decodeSignal(const QByteArray& datagram);
	double hexstr2double(const std::string& hexstr);
};

#endif