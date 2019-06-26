#ifndef BITALINODEVICE_H
#define BITALINODEVICE_H

#include <QThread>
#include <vector>
#include "bitalino.h"


// Wrapper class around BITalino.h
class BitalinoDevice : public QObject
{
	Q_OBJECT

public:
	BitalinoDevice() = default;
	BitalinoDevice(const BITalino::DevInfo& device);
	~BitalinoDevice();

	QString name();

public slots:
	void process();

signals:
	void timeDomainValues(const QVector<int>&);
	void updatePlot(const double& value);

private:

	void	analogValuesFromVFrame(const BITalino::VFrame& in, QVector<int>& out);
private:
	BITalino	_device;
	QString		_name;    // Name of a Bluetooth device

};

using BitalinoDeviceListPtr = std::vector<BitalinoDevice*>;

#endif // BITALINODEVICE_H