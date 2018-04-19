//This class represents the main window of the application
#ifndef EEGSIGNALS_H
#define EEGSIGNALS_H
#include <QMainWindow>
#include <QDebug>
#include <QHostAddress>

#include "MuseThread.h"
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
	
	/*sets up the options of the plot , all plots currently have the same properties*/
	void setUpRealTimePlot(QCustomPlot *widget);

	/*Separate thread currently in use for the dancer project - to be updated*/
	DancerThread *mDancerThread;

	/*2 threads for each game mode*/

	GameThread *mGameThread;
	AlphaThetaGameThread *mAlphaThetaThread;
	
	//Thread for MUSE device.
	MuseThread *mMuseThread;

	Ui::EEGsignalsClass ui;

	public slots :											/*Utility methods*/
		void changeDancerSignalRecevingPort();				//-change the udp port from which the dancer thread reads data
		void changeDancerSignalSendingValues();				//-change the udp port and ip address to which the dancer thread sends data after proccessing
		void changeAlphaSignalRecevingPort();
		void changeAlphaSignalSendingValues();
		void changeAlphaThetaSignalRecevingPort();
		void changeAlphaThetaSignalSendingValues();
		void alphaSignalPlot(const QString &data);			/*Methods that update the plot for each signal*/
		void alphaThetaSignalPlot(const QString &data);
		void dancerPlot(const QString &data);
};
#endif