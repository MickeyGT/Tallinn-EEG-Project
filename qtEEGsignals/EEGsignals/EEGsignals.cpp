#include "EEGsignals.h"
#include <QInputDialog>
#include "alphaSignalDecoder.h"

EEGsignals::EEGsignals(QWidget *parent):
	alphaUDPconnection(alphaChannel),	//channels are set by default to 25000 / 26000
	thetaUDPconnection(thetaChannel),
	QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.alphaChannelPortChanger, SIGNAL(pressed()), this, SLOT(changeAlphaSignalPort()));
	connect(ui.thetaChannelPortChanger, SIGNAL(pressed()), this, SLOT(changeThetaSignalPort()));
	connect(ui.getvalue, SIGNAL(pressed()), this, SLOT(beginVisualization()));

	barchart newBarchart;
	ui.gridLayout->addWidget(newBarchart.createChart(), 0, 0);
}


void EEGsignals::changeAlphaSignalPort()
{
	bool ok;
	int port = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
		tr("Port:"), 0, 0, 30000,1, &ok);
	if (ok)
		alphaUDPconnection.setPort(port);

	
}

void EEGsignals::changeThetaSignalPort()
{
	bool ok;
	int port = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
		tr("Port:"), 0, 0, 30000, 1, &ok);
	if (ok)
		thetaUDPconnection.setPort(port);
}

void EEGsignals::beginVisualization()
{
		alphaSignalDecoder decoder;
		long long signalResult = decoder.decodeSignal(alphaUDPconnection.getCurrentValue());
		qDebug() << signalResult;
}