//This class represents the main window of the application
#ifndef EEGSIGNALS_H
#define EEGSIGNALS_H
#include <QMainWindow>
#include "ui_EEGsignals.h"
#include <qdebug.h>
#include <QHostAddress>
#include "UdpConnection.h"
#include "Barchart.h"
#include "DynamicSpline.h"
#include "DataManagementThread.h"

class EEGsignals : public QMainWindow
{
	Q_OBJECT

public:
	EEGsignals(QWidget *parent = Q_NULLPTR);

private:
	
	UdpConnection mAlphaUDPconnection;
	UdpConnection mThetaUDPconnection;
	QChartView* chartView;
	QChartView* chartView2;
	DynamicSpline* spline;
	DynamicSpline* spline2;

	Ui::EEGsignalsClass ui;

	public slots :
		void changeAlphaSignalPort();
		void changeThetaSignalPort();
		void beginVisualization();
		void sendData(const QByteArray &data);
};
#endif