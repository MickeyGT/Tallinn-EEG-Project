#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EEGsignals.h"
#include <qdebug.h>
#include <QHostAddress>
#include "udpconnection.h"
#include "barchart.h"


class EEGsignals : public QMainWindow
{
	Q_OBJECT

public:
	EEGsignals(QWidget *parent = Q_NULLPTR);

private:
	udpconnection alphaUDPconnection;
	udpconnection thetaUDPconnection;

	enum
	{
		alphaChannel = 25000,
		thetaChannel = 26000
	};

	Ui::EEGsignalsClass ui;

	public slots :
		void changeAlphaSignalPort();
		void beginVisualization();
		void changeThetaSignalPort();
	
};
