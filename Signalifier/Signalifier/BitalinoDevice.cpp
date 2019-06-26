#include "BitalinoDevice.h"
#include "FftFactory.h"
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
	_device.start(1000, { 0 });   // start acquisition of channel 0 at 1000 Hz
	//dev.trigger({ true, false });  // for original BITalino
	
	BITalino::VFrame frames(100); // initialize the frames vector with 100 frames 
	do
	{
		_device.read(frames); // get 100 frames from device
		const BITalino::Frame &f = frames[0];  // get a reference to the first frame of each 100 frames block

		QVector<int> analogValues;

		analogValuesFromVFrame(frames, analogValues);

		emit updatePlot(f.analog[0]);
		emit timeDomainValues(analogValues);

	//	qDebug() << f.analog[0];

	} while (1);
}


void BitalinoDevice::analogValuesFromVFrame(const BITalino::VFrame& in, QVector<int>& out)
{
	for (const auto& i : in)
	{
		out.push_back(i.analog[0]);
	}
}