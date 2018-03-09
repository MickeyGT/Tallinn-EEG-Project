#ifndef DATAMANAGEMENTTHREAD_H
#define DATAMANAGEMENTTHREAD_H
#include <QThread>
#include "UdpConnection.h"
#include "DynamicSpline.h"
#include <QtCore/QTimer>

class DataManagementThread : public QThread
{
	Q_OBJECT

public:
	DataManagementThread();
	DataManagementThread(DynamicSpline *spline , const int &port);
	~DataManagementThread();
	void run();

	public slots :
	void readyRead();

private:
	DynamicSpline* mMainWindowSpline;
	QUdpSocket* mUDPconnection;
	QByteArray mCurrentValue;
	
};
#endif