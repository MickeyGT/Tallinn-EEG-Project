#include "BitalinoDeviceManager.h"
#include <qdebug.h>

void BitalinoDeviceManager::retrieveBluetoothDevices()
{
	BITalino::VDevInfo deviceList = BITalino::find();

	for (const BITalino::DevInfo& device : deviceList)
	{
		QString deviceName = QString::fromStdString(device.name);

		if (deviceName.contains("bitalino", Qt::CaseInsensitive))
		{
			BitalinoDevice* devicePtr = new BitalinoDevice(device);
			_deviceList.push_back(devicePtr);
		}
	}
}


void BitalinoDeviceManager::startDevices()
{
	if (_deviceList.empty())
	{
		qDebug() << "Couldnt start any device, list is empty";
		return;
	}

	for (BitalinoDevice* device : _deviceList)
	{
		QThread* deviceThread = new QThread;
		device->moveToThread(deviceThread);

		QObject::connect(device, SIGNAL(finished()), device, SLOT(deleteLater()));
		QObject::connect(deviceThread, SIGNAL(started()), device, SLOT(process()));
		QObject::connect(deviceThread, SIGNAL(finished()), deviceThread, SLOT(deleteLater()));

		deviceThread->start();
	}
}

BitalinoDeviceListPtr BitalinoDeviceManager::deviceList()
{
	return _deviceList;
}

BitalinoDeviceManager::~BitalinoDeviceManager()
{
}
