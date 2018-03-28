//This class represents the main window of the application
#ifndef EEGSIGNALS_H
#define EEGSIGNALS_H
#include <QMainWindow>
#include <QDebug>
#include <QHostAddress>

#include "DancerThread.h"
#include "GameThread.h"
#include "AlphaThetaGameThread.h"
#include "ui_EEGsignals.h"
class EEGsignals : public QMainWindow
{
	Q_OBJECT

public:
	EEGsignals(QWidget *parent = Q_NULLPTR);

private:
	
	void setUpRealTimePlot(QCustomPlot *widget);

	DancerThread *mDancerThread;
	GameThread *mGameThread;
	AlphaThetaGameThread *mAlphaThetaThread;
	
	Ui::EEGsignalsClass ui;

	public slots :
		void changeDancerSignalRecevingPort();
		void changeDancerSignalSendingValues();
		void alphaSignalPlot(const QString &data);
		void alphaThetaSignalPlot(const QString &data);
};
#endif