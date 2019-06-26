#include "Signalifier.h"
#include <QProcess>
#include "FftFactory.h"


Signalifier::Signalifier(QWidget *parent)
	: QMainWindow(parent)
{
	_ui.setupUi(this);

	setUpRealTimePlot(_ui.bitalinoDevice1);

	/*QStringList args;
	args << "E:/Tallinn-EEG-Project/Signalifier/FFT-computor/testFile.py"
		<< "123"
		<< "asdf";*/

	/////*QProcess process;
	////process.setProcessChannelMode(QProcess::MergedChannels);
	////process.start("E:\\Tallinn-EEG-Project\\Signalifier\\FFT-computor\\dist\\testFile.exe", QStringList() << "asd" << "123" );
	////process.waitForReadyRead();
	////qDebug() << QString(process.readAllStandardOutput());*/




	/*QProcess process;
	process.setProcessChannelMode(QProcess::MergedChannels);
	QString exe = "E:\Tallinn-EEG-Project\Signalifier\FFT-computor\dist\asdf\asdf.exe";
	process.execute(exe);
	process.waitForFinished();
	QByteArray output = process.readAllStandardOutput();
	std::string value = output.toStdString();
	QString aaaa = QString::fromStdString(value);

	qDebug() << aaaa << endl;*/

	_gameConnection = new ShooterGameConnection();

	BitalinoDeviceManager::Instance().retrieveBluetoothDevices();

	connectBitalinoToPlot();
	connectBitalinoToGame();

	BitalinoDeviceManager::Instance().startDevices();
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
	QObject::connect(deviceList[0], SIGNAL(timeDomainValues(const QVector<int>&)), _gameConnection, SLOT(processTimeDomainValues(const QVector<int>&)));

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

void Signalifier::sendPercentageToGame(const QVector<int>& value)
{
//	BITalino::VFrame frames2(100);
//	QVector<int> asdf = { 1,2,3,4 };
////	FftFactory::Instance().timeToFrequencyDomain(value, asdf);
//
//	QByteArray dataByteArray;
//	//dataByteArray.append(value);
//
//	_udpConnection->writeDatagram(dataByteArray, _address, 25000);
}