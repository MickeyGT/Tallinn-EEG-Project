#ifndef ALPHASIGNALDECODER_H
#define ALPHASIGNALDECODER_H
#include "DatagramDecoder.h"
#include <QDataStream>
#include <qdebug.h>

class AlphaSignalDecoder : public DatagramDecoder
{
public:
	AlphaSignalDecoder();
	~AlphaSignalDecoder();
	double decodeSignal(const QByteArray& datagram);
	double hexstr2double(const std::string& hexstr);
};

#endif