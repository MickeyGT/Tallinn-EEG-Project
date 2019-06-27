#ifndef SIGNALIFIER_H
#define SIGNALIFIER_H

#include <QtWidgets/QMainWindow>

#include "BitalinoDeviceManager.h"
#include "ShooterGameConnection.h"
#include "ui_Signalifier.h"


class Signalifier : public QMainWindow
{
	Q_OBJECT

public:
	Signalifier(QWidget *parent = Q_NULLPTR);

private:
	void setUpRealTimePlot(QCustomPlot *widget);
	void connectBitalinoToPlot();
	void connectBitalinoToGame();

private slots:
	void updateBitalinoDevice1Plot(const double& value);
	void updateBitalinoDevice2Plot(const double& value);

signals:
	void test();

private:
	ShooterGameConnection*	_gameConnection;
	
	Ui::SignalifierClass	_ui;
};

#endif // SIGNALIFIER_H