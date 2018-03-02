//This class represents the interface for a datagram decoder.
//Every decoder (currently alpha , theta) should implement this class and rewrite the decodeSignal() method.
//Future signal decoders should also use this interface .
#ifndef DATAGRAMDECODER_H
#define DATAGRAMDECODER_H
#include <QUdpSocket>
class DatagramDecoder
{
public:
	DatagramDecoder();
	~DatagramDecoder();
	virtual long long decodeSignal(const QByteArray &datagram) = 0;
};
#endif
