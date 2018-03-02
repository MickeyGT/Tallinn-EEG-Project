#ifndef DATAGRAMDECODER_H
#define DATAGRAMDECODER_H
#include <QUdpSocket>
class datagramDecoder
{
public:
	datagramDecoder();
	~datagramDecoder();
	virtual long long decodeSignal(const QByteArray &datagram) = 0;
};
#endif
