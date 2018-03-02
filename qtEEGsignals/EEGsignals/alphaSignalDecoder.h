#ifndef ALPHASIGNALDECODER_H
#define ALPHASIGNALDECODER_H
#include "datagramDecoder.h"
class alphaSignalDecoder : public datagramDecoder
{
public:
	alphaSignalDecoder();
	~alphaSignalDecoder();
	long long decodeSignal(const QByteArray &datagram);
	double hexstr2double(const std::string& hexstr);
};

#endif