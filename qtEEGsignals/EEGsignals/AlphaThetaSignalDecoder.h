/*Alpha Theta game mode works with 2 signals : highest alpha and theta*/
#ifndef ALPHATHETASIGNALDECODER_H
#define ALPHATHETASIGNALDECODER_H
#include <QDataStream>

class AlphaThetaSignalDecoder
{
public:
	AlphaThetaSignalDecoder();
	~AlphaThetaSignalDecoder();
	QPair<double , double> decodeSignal(const QByteArray& datagram);
};

#endif