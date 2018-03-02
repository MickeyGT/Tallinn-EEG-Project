#ifndef ALPHASIGNALDECODER_H
#define ALPHASIGNALDECODER_H
#include "datagramDecoder.h"
class AlphaSignalDecoder : public DatagramDecoder
{
public:
	AlphaSignalDecoder();
	~AlphaSignalDecoder();
	long long decodeSignal(const QByteArray &datagram);
	double hexstr2double(const std::string& hexstr);
};

#endif