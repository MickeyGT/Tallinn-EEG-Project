#ifndef BITALINODEVICEMANAGER_H
#define BITALINODEVICEMANAGER_H

#include "BitalinoDevice.h"
#include "FftFactory.h"

class BitalinoDeviceManager
{
public:
	static BitalinoDeviceManager& Instance()
	{
		static BitalinoDeviceManager instance;

		return instance;
	}


	void					retrieveBluetoothDevices();
	void					startDevices();
	BitalinoDeviceListPtr	deviceList();

	~BitalinoDeviceManager();

private:
	BitalinoDeviceManager() {}
	BitalinoDeviceManager(const BitalinoDeviceManager&);
	BitalinoDeviceManager& operator=(const BitalinoDeviceManager&);

private:
	BitalinoDeviceListPtr		_deviceList;
};

#endif // BITALINODEVICEMANAGER_H