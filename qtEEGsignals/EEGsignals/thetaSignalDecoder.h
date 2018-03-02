#ifndef THETASIGNALDECODER_H
#define THETASIGNALDECODER_H
#include "datagramDecoder.h"
class ThetaSignalDecoder :	public DatagramDecoder
{
public:
	ThetaSignalDecoder();
	~ThetaSignalDecoder();
	long long decodeSignal(const QByteArray &datagram);
};

#endif