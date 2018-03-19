#ifndef DANCERSIGNALDECODER_H
#define DANCERSIGNALDECODER_H
#include <QDebug>
#include <QDataStream>
#include <QUdpSocket>
#include <QList>
class DancerSignalDecoder
{
public:
	DancerSignalDecoder();
	~DancerSignalDecoder();
	QList<QVariant> decodeSignal(const QByteArray& datagram);
};

#endif