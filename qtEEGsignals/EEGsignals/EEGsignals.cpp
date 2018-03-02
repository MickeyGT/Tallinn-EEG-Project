#include "EEGsignals.h"
#include <QInputDialog>
#include "alphaSignalDecoder.h"

EEGsignals::EEGsignals(QWidget *parent):
	mAlphaUDPconnection(alphaChannel),	//channels are set by default to 25000(alpha) / 26000(theta)
	mThetaUDPconnection(thetaChannel),
	QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.alphaChannelPortChanger, SIGNAL(pressed()), this, SLOT(changeAlphaSignalPort()));
	connect(ui.thetaChannelPortChanger, SIGNAL(pressed()), this, SLOT(changeThetaSignalPort()));
	connect(ui.getvalue, SIGNAL(pressed()), this, SLOT(beginVisualization()));

	Barchart newBarchart;
	ui.gridLayout->addWidget(newBarchart.createChart(), 0, 0);
}

void EEGsignals::changeAlphaSignalPort()
{
	bool ok;
	int port = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
		tr("Port:"), 0, 0, 30000,1, &ok);
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

void EEGsignals::beginVisualization()
{
		AlphaSignalDecoder decoder;
		long long signalResult = decoder.decodeSignal(mAlphaUDPconnection.getCurrentValue());
		qDebug() << signalResult;
}