#ifndef ALPHATHETAGAMETHREAD_H
#define ALPHATHETAGAMETHREAD_H
#include "DataReceivingThread.h"

class AlphaThetaGameThread : public DataReceivingThread
{
public:
	AlphaThetaGameThread(const int &receivePort);
	~AlphaThetaGameThread();

	public slots :
		void processDatagram();


private:
	double mMinValue;
	double mMaxValue;

	void updateMinMaxValue(const double &value);
	QString getPercentage(const double &value);
};

#endif