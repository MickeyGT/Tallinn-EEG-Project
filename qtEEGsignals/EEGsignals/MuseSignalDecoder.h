#ifndef MUSESIGNALDECODER_H
#define MUSESIGNALDECODER_H
#include <QDataStream>
#include <QList>

class MuseSignalDecoder
{
public:
	MuseSignalDecoder();
	~MuseSignalDecoder();
	QList<QVariant> decodeSignal(const QByteArray &datagram);
};

#endif