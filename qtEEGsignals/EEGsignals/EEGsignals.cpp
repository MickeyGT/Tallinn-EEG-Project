#include <QInputDialog>

#include "AlphaSignalDecoder.h"
#include "EEGsignals.h"

EEGsignals::EEGsignals(QWidget *parent) :
	QMainWindow(parent)
{
	ui.setupUi(this);
	
	connect(ui.button3, SIGNAL(pressed()), this, SLOT(changeAlphaSignalPort()));
	connect(ui.button4, SIGNAL(pressed()), this, SLOT(changeSkinConductorSignalPort()));

	connect(ui.button1, SIGNAL(pressed()), this, SLOT(beginAlphaSignalTransmission()));
	connect(ui.button2, SIGNAL(pressed()), this, SLOT(beginSkinConductorSignalTransmission()));

	setUpRealTimePlot(ui.EEGAlphaSignalPlot);
	setUpRealTimePlot(ui.CustomPlot);

	mAlphaSignalThread = new DataManagementThread(12345);

	connect(mAlphaSignalThread, SIGNAL(updatePlot(QString)), this, SLOT(realtimePlot(QString)));
}

void EEGsignals::changeAlphaSignalPort()
{
	bool ok;
	int port = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
		tr("Port:"), 0, 0, 30000, 1, &ok);
	if (ok)
		mAlphaSignalThread->setUpConnection(port);
}

void EEGsignals::changeSkinConductorSignalPort()
{
	bool ok;
	int port = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
		tr("Port:"), 0, 0, 30000, 1, &ok);
	if (ok)
		mSkinConductorSignalThread->setUpConnection(port);
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

void EEGsignals::realtimePlot(const QString &value)
{
	static QTime time(QTime::currentTime());
	double key = time.elapsed() / 1000.0;
	static double lastPointKey = 0;
	if (key - lastPointKey > 0.002)
	{
		ui.EEGAlphaSignalPlot->graph(0)->addData(key, value.toDouble());
		/*ui.CustomPlot->graph(0)->addData(key, value.toDouble());*/
		lastPointKey = key;
	}

	/* make key axis range scroll right with the data at a constant range of 8. */
	ui.EEGAlphaSignalPlot->graph(0)->rescaleValueAxis();
	ui.EEGAlphaSignalPlot->xAxis->setRange(key, 8, Qt::AlignRight);
	ui.EEGAlphaSignalPlot->replot();

	/*ui.CustomPlot->graph(0)->rescaleValueAxis();
	ui.CustomPlot->xAxis->setRange(key, 8, Qt::AlignRight);
	ui.CustomPlot->replot();*/
}
