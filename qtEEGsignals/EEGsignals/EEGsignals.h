//This class represents the main window of the application
#ifndef EEGSIGNALS_H
#define EEGSIGNALS_H
#include <QMainWindow>
#include <QDebug>
#include <QHostAddress>

#include "DataManagementThread.h"
#include "ui_EEGsignals.h"
class EEGsignals : public QMainWindow
{
	Q_OBJECT

public:
	EEGsignals(QWidget *parent = Q_NULLPTR);

private:
	
	void setUpRealTimePlot(QCustomPlot *widget);

	QTimer timer_plot;

	DataManagementThread *mAlphaSignalThread;
	DataManagementThread *mSkinConductorSignalThread;
	
	Ui::EEGsignalsClass ui;

	public slots :
		void changeAlphaSignalPort();
		void changeSkinConductorSignalPort();
		void realtimePlot(const QString &data);
};
#endif