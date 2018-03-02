#ifndef THETASIGNALDECODER_H
#define THETASIGNALDECODER_H
#include "datagramDecoder.h"
class thetaSignalDecoder :	public datagramDecoder
{
public:
	thetaSignalDecoder();
	~thetaSignalDecoder();
	long long decodeSignal(const QByteArray &datagram);
};

#endif