#include "Signalifier.h"
#include <QProcess>
#include "FftFactory.h"
#include "BitalinoFftMap.h"

Signalifier::Signalifier(QWidget *parent)
	: QMainWindow(parent)
{
	_ui.setupUi(this);
	connect(_ui.button1, SIGNAL(pressed()), this, SLOT(startDevice()));
	connect(_ui.button2, SIGNAL(pressed()), this, SLOT(changeUDPSendingIp()));

	setUpRealTimePlot(_ui.bitalinoDevice1);

	BitalinoDeviceManager::Instance().retrieveBluetoothDevices();
}

void Signalifier::setUpRealTimePlot(QCustomPlot *widget)
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

void Signalifier::connectBitalinoToPlot()
{
	BitalinoDeviceListPtr deviceList = BitalinoDeviceManager::Instance().deviceList();
	QObject::connect(deviceList[0], SIGNAL(updatePlot(double)), this, SLOT(updateBitalinoDevice1Plot(double)));
//	QObject::connect(deviceList[1], SIGNAL(dataReceived(int)), this, SLOT(updateBitalinoDevice2Plot(double)));
//	TO DO : 2nd device connection
}

void Signalifier::connectBitalinoToGame()
{
	BitalinoDeviceListPtr deviceList = BitalinoDeviceManager::Instance().deviceList();

	BitalinoDevice* device1 = deviceList[0];
	BitalinoFftMap* fftMap = new BitalinoFftMap(device1->name());
	device1->setFftMap(fftMap);

	QObject::connect(device1, SIGNAL(timeDomainValues(const QVector<int>&)), _gameConnection, SLOT(processTimeDomainValues(const QVector<int>&)));
	QObject::connect(_gameConnection, SIGNAL(updateBitalinoDeviceFftFlag(const bool&)), fftMap, SLOT(setIsFftFactoryRunningFlag(const bool&)));
}

void Signalifier::updateBitalinoDevice1Plot(const double& value)
{
	static QTime time(QTime::currentTime());
	double key = time.elapsed() / 1000.0;
	static double lastPointKey = 0;

	if (key - lastPointKey > 0.002)
	{
		_ui.bitalinoDevice1->graph(0)->addData(key, value);
		lastPointKey = key;
	}

	_ui.bitalinoDevice1->graph(0)->rescaleValueAxis();
	_ui.bitalinoDevice1->xAxis->setRange(key, 8, Qt::AlignRight);
	_ui.bitalinoDevice1->replot();
}


void Signalifier::changeUDPSendingIp()
{
	bool ok;
	QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
		tr("Ip address:"), QLineEdit::Normal,
		QDir::home().dirName(), &ok);

	if (ok && !text.isEmpty())
		_gameConnection->changeUdpConnectionAddress(text);
}

void Signalifier::startDevice()
{
	_gameConnection = new ShooterGameConnection();

	connectBitalinoToPlot();
	connectBitalinoToGame();

	BitalinoDeviceManager::Instance().startDevices();
}