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
	void sendPercentageToGame(const QString& percentage);
	void updatePlot(const double& value);

private:
	QString getPercentage(const double& value);
	void	updateMinMaxValues(const double& value);
private:
	BITalino	_device;
	QString		_name;    // Name of a Bluetooth device
	double		_minValue = 10000;
	double		_maxValue = -10000;
};

using BitalinoDeviceListPtr = std::vector<BitalinoDevice*>;

#endif // BITALINODEVICE_H