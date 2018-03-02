#ifndef THETASIGNALDECODER_H
#define THETASIGNALDECODER_H
#include "DatagramDecoder.h"
class ThetaSignalDecoder :	public DatagramDecoder
{
public:
	ThetaSignalDecoder();
	~ThetaSignalDecoder();
	double decodeSignal(const QByteArray& datagram);
};

#endif