#include "Signalifier.h"

Signalifier::Signalifier(QWidget *parent)
	: QMainWindow(parent)
{
	_ui.setupUi(this);

	_udpConnection = new QUdpSocket(this);

	_address.setAddress("192.168.1.2");

	BitalinoDeviceManager::Instance().retrieveBluetoothDevices();
	BitalinoDeviceManager::Instance().startDevices();
	
	setUpRealTimePlot(_ui.bitalinoDevice1);

	connectBitalinoToPlot();
	connectBitalinoToGame();
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
}

void Signalifier::connectBitalinoToGame()
{
	BitalinoDeviceListPtr deviceList = BitalinoDeviceManager::Instance().deviceList();
	QObject::connect(deviceList[0], SIGNAL(sendPercentageToGame(QString)), this, SLOT(sendPercentageToGame(QString)));

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

void Signalifier::updateBitalinoDevice2Plot(const double& value)
{
	static QTime time(QTime::currentTime());
	double key = time.elapsed() / 1000.0;
	static double lastPointKey = 0;

	if (key - lastPointKey > 0.002)
	{
		_ui.bitalinoDevice2->graph(0)->addData(key, value);
		lastPointKey = key;
	}

	_ui.bitalinoDevice2->graph(0)->rescaleValueAxis();
	_ui.bitalinoDevice2->xAxis->setRange(key, 8, Qt::AlignRight);
	_ui.bitalinoDevice2->replot();
}

void Signalifier::sendPercentageToGame(const QString& value)
{
	QString asdf = QString::number(70);

	QByteArray dataByteArray;
	dataByteArray.append(value);

	_udpConnection->writeDatagram(dataByteArray, _address, 25000);
}