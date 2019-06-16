#include "BitalinoDevice.h"
#include <qdebug.h>

BitalinoDevice::BitalinoDevice(const BITalino::DevInfo& device):
	_device(device.macAddr.c_str())
{
	_device.battery(10);
	_name = QString(device.name.c_str());
}


BitalinoDevice::~BitalinoDevice()
{
}

QString BitalinoDevice::name()
{
	return _name;
}

void BitalinoDevice::process()
{
	_device.start(1000, { 0, 1, 2, 3, 4, 5 });   // start acquisition of all channels at 1000 Hz
	//dev.trigger({ true, false });  // for original BITalino

	BITalino::VFrame frames(100); // initialize the frames vector with 100 frames 
	do
	{
		_device.read(frames); // get 100 frames from device
		const BITalino::Frame &f = frames[0];  // get a reference to the first frame of each 100 frames block

		updateMinMaxValues(f.analog[0]);
		QString percentage = getPercentage(f.analog[0]);

		emit updatePlot(f.analog[0]);
		emit sendPercentageToGame(percentage);

		qDebug() << percentage;

	} while (1);
}

QString BitalinoDevice::getPercentage(const double& value)
{
	double minValue = value - _minValue;
	double maxValue = _maxValue - _minValue;
	if (minValue == 0)
	{
		return "0";
	}
	else
	{
		double percentage = (minValue * 100) / maxValue;
		int integerPercentage = (int)percentage;
		QString valueAsString = QString::number(integerPercentage);
		return valueAsString;
	}
}

void BitalinoDevice::updateMinMaxValues(const double& value)
{
	if (value > _maxValue)
	{
		_maxValue = value;
	}
	else if (value < _minValue)
	{
		_minValue = value;
	}
}