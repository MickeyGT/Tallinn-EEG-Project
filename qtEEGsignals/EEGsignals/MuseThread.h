/*Work in progress , still haven't figured out how the format of the datagram that the deivce sends.*/
#ifndef MUSETHREAD_H
#define MUSETHREAD_H
#include "DataReceivingThread.h"
class MuseThread : public DataReceivingThread
{
public:
	MuseThread(const int &receivePort);
	~MuseThread();

	public slots:
	void processDatagram();
};

#endif