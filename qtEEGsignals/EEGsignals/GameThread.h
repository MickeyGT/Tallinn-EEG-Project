#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <QThread>
#include <QTimer>
#include <QUdpsocket>

#include "DataReceivingThread.h"
#include "qcustomplot.h"
#include "Utility.h"

class GameThread : public DataReceivingThread
{
	Q_OBJECT

public:
	GameThread(const int &receivePort);
	~GameThread();

	public slots :
		void processDatagram();

private:
	double mMinValue;
	double mMaxValue;

	void updateMinMaxValue(const double &value);
	QString getPercentage(const double &value);
};
#endif