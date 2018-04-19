#ifndef DANCERTHREAD_H
#define DANCERTHREAD_H
#include <QThread>
#include <QTimer>
#include <QUdpsocket>
#include <QPair>

#include "DataReceivingThread.h"
#include "Utility.h"

class DancerThread : public DataReceivingThread
{
	#define MINIMUMBORDER  -1000
	#define MAXIMUMBORDER	1000

	Q_OBJECT

public:
	
	DancerThread(const int &receivePort);
	~DancerThread();

	public slots :
	void processDatagram();

private:

	QList < QPair<QVariant, QVariant> > signalMinMaxValues;
	void initSignalMinMaxValue();
	void updateSignalMinMaxValues(const QList<QVariant> &list);
	QString getPercentage(const QList<QVariant> &list);
};
#endif