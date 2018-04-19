#include <QInputDialog>

#include "AlphaSignalDecoder.h"
#include "EEGsignals.h"
#include "customMultipleInputsDialog.h"

EEGsignals::EEGsignals(QWidget *parent) :
	QMainWindow(parent)
{
	ui.setupUi(this);
	
	connect(ui.button1, SIGNAL(pressed()), this, SLOT(changeAlphaSignalRecevingPort()));
	connect(ui.button2, SIGNAL(pressed()), this, SLOT(changeAlphaSignalSendingValues()));

	connect(ui.button3, SIGNAL(pressed()), this, SLOT(changeAlphaThetaSignalRecevingPort()));
	connect(ui.button4, SIGNAL(pressed()), this, SLOT(changeAlphaThetaSignalSendingValues()));

	connect(ui.button5, SIGNAL(pressed()), this, SLOT(changeDancerSignalRecevingPort()));
	connect(ui.button6, SIGNAL(pressed()), this, SLOT(changeDancerSignalSendingValues()));

	setUpRealTimePlot(ui.EEGAlphaSignalPlot);
	setUpRealTimePlot(ui.EEGAlphaThetaPlot);
	setUpRealTimePlot(ui.EEGDancerPlot);

	mDancerThread = new DancerThread(12345);
	mGameThread = new GameThread(25000);
	mAlphaThetaThread = new AlphaThetaGameThread(28000);
//	mMuseThread = new MuseThread(28000);

	connect(mGameThread, SIGNAL(updatePlot(QString)), this, SLOT(alphaSignalPlot(QString)));
	connect(mAlphaThetaThread, SIGNAL(updatePlot(QString)), this, SLOT(alphaThetaSignalPlot(QString)));
	connect(mDancerThread, SIGNAL(updatePlot(QString)), this, SLOT(dancerPlot(QString)));
}

void EEGsignals::changeDancerSignalRecevingPort()
{
	bool ok;
	int port = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
		tr("Port:"), 0, 0, 3000000, 1, &ok);
	if (ok)
		mDancerThread->changeRecevingPort(port);
}

void EEGsignals::changeDancerSignalSendingValues()
{
	customMultipleInputsDialog *dial = new customMultipleInputsDialog;
	QString ip = dial->getIp();
	QString port = dial->getPort();
	mDancerThread->setSendAddressAndPort(ip, port);
}

void EEGsignals::changeAlphaSignalRecevingPort()
{
	bool ok;
	int port = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
		tr("Port:"), 0, 0, 3000000, 1, &ok);
	if (ok)
		mGameThread->changeRecevingPort(port);
}

void EEGsignals::changeAlphaSignalSendingValues()
{
	customMultipleInputsDialog *dial = new customMultipleInputsDialog;
	QString ip = dial->getIp();
	QString port = dial->getPort();
	mGameThread->setSendAddressAndPort(ip, port);
}

void EEGsignals::changeAlphaThetaSignalRecevingPort()
{
	bool ok;
	int port = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
		tr("Port:"), 0, 0, 3000000, 1, &ok);
	if (ok)
		mAlphaThetaThread->changeRecevingPort(port);
}

void EEGsignals::changeAlphaThetaSignalSendingValues()
{
	customMultipleInputsDialog *dial = new customMultipleInputsDialog;
	QString ip = dial->getIp();
	QString port = dial->getPort();
	mAlphaThetaThread->setSendAddressAndPort(ip, port);
}


void EEGsignals::setUpRealTimePlot(QCustomPlot *widget)
{
	/* Add graph and set the curve line color to green */
	widget->addGraph();
	widget->graph(0)->setPen(QPen(Qt::red));
	widget->graph(0)->setAntialiasedFill(false);

	/* Configure x-Axis as time in secs */
	QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
	timeTicker->setTimeFormat("%s");
	widget->xAxis->setTicker(timeTicker);
	widget->axisRect()->setupFullAxesBox();

	/* Configure x and y-Axis to display Labels */
	widget->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
	widget->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
	widget->xAxis->setLabel("Time(s)");
	widget->yAxis->setLabel("ADC Raw Counts");

	/* Make top and right axis visible, but without ticks and label */
	widget->xAxis2->setVisible(true);
	widget->yAxis->setVisible(true);
	widget->xAxis2->setTicks(false);
	widget->yAxis2->setTicks(false);
	widget->xAxis2->setTickLabels(false);
	widget->yAxis2->setTickLabels(false);
}

void EEGsignals::alphaSignalPlot(const QString &value)
{
	static QTime time(QTime::currentTime());
	double key = time.elapsed() / 1000.0;
	static double lastPointKey = 0;

	if (key - lastPointKey > 0.002)
	{
		ui.EEGAlphaSignalPlot->graph(0)->addData(key, value.toDouble());
		lastPointKey = key;
	}

	ui.EEGAlphaSignalPlot->graph(0)->rescaleValueAxis();
	ui.EEGAlphaSignalPlot->xAxis->setRange(key, 8, Qt::AlignRight);
	ui.EEGAlphaSignalPlot->replot();
}


void EEGsignals::alphaThetaSignalPlot(const QString &value)
{
	static QTime time(QTime::currentTime());
	double key = time.elapsed() / 1000.0;
	static double lastPointKey = 0;

	if (key - lastPointKey > 0.002)
	{
		ui.EEGAlphaThetaPlot->graph(0)->addData(key, value.toDouble());
		lastPointKey = key;
	}

	ui.EEGAlphaThetaPlot->graph(0)->rescaleValueAxis();
	ui.EEGAlphaThetaPlot->xAxis->setRange(key, 8, Qt::AlignRight);
	ui.EEGAlphaThetaPlot->replot();
}


void EEGsignals::dancerPlot(const QString &value)
{
	static QTime time(QTime::currentTime());
	double key = time.elapsed() / 1000.0;
	static double lastPointKey = 0;

	if (key - lastPointKey > 0.002)
	{
		ui.EEGDancerPlot->graph(0)->addData(key, value.toDouble());
		lastPointKey = key;
	}

	ui.EEGDancerPlot->graph(0)->rescaleValueAxis();
	ui.EEGDancerPlot->xAxis->setRange(key, 8, Qt::AlignRight);
	ui.EEGDancerPlot->replot();
}