//This class represents the main window of the application
#ifndef EEGSIGNALS_H
#define EEGSIGNALS_H
#include <QMainWindow>
#include <QDebug>
#include <QHostAddress>

#include "DancerThread.h"
#include "GameThread.h"
#include "ui_EEGsignals.h"
class EEGsignals : public QMainWindow
{
	Q_OBJECT

public:
	EEGsignals(QWidget *parent = Q_NULLPTR);

private:
	
	void setUpRealTimePlot(QCustomPlot *widget);

	QTimer timer_plot;

	DancerThread *mDancerThread;
	GameThread *mGameThread;
	
	Ui::EEGsignalsClass ui;

	public slots :
		void changeDancerSignalRecevingPort();
		void changeDancerSignalSendingValues();
		void realtimePlot(const QString &data);
};
#endif