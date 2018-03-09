#include "EEGsignals.h"
#include <QInputDialog>
#include "AlphaSignalDecoder.h"
#include <QRandomGenerator>

EEGsignals::EEGsignals(QWidget *parent):
	QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.getvalue, SIGNAL(pressed()), this, SLOT(beginVisualization()));
	
	spline = new DynamicSpline;
	spline->legend()->hide();
	spline->setAnimationOptions(QChart::AllAnimations);
	chartView = new QChartView(spline);
	chartView->setRenderHint(QPainter::Antialiasing);
	ui.gridLayout->addWidget(chartView, 0, 0);


	spline2 = new DynamicSpline;
	spline2->legend()->hide();
	spline2->setAnimationOptions(QChart::AllAnimations);
	chartView2 = new QChartView(spline2);
	chartView2->setRenderHint(QPainter::Antialiasing);
	ui.gridLayout_2->addWidget(chartView2, 0, 0);
}

void EEGsignals::beginVisualization()
{
		DataManagementThread* newThread = new DataManagementThread(spline , 25000);
		newThread->start();

		DataManagementThread* newThread2 = new DataManagementThread(spline2, 26000);
		newThread2->start();
}

void EEGsignals::sendData(const QByteArray &data)
{
	int port = 56789;
	QHostAddress address("192.168.0.5");
	mAlphaUDPconnection.sendValues(data, address, port);
}

void EEGsignals::changeAlphaSignalPort()
{
	bool ok;
	int port = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
		tr("Port:"), 0, 0, 30000, 1, &ok);
	if (ok)
		mAlphaUDPconnection.setPort(port);
}

void EEGsignals::changeThetaSignalPort()
{
	bool ok;
	int port = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
		tr("Port:"), 0, 0, 30000, 1, &ok);
	if (ok)
		mThetaUDPconnection.setPort(port);
}