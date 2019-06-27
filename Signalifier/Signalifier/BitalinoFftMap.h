#ifndef BITALINOFFTMAP_H
#define BITALINOFFTMAP_H
#include <qdebug.h>

class BitalinoFftMap : public QObject
{
	Q_OBJECT

public:
	inline BitalinoFftMap() = default;
	inline BitalinoFftMap(const QString& deviceName) { _deviceName = deviceName; _isFftScriptRunning = false; };

	bool isFftScriptRunning();

public slots:
	void setIsFftFactoryRunningFlag(const bool&);

signals:


private:
	QString _deviceName;
	bool	_isFftScriptRunning;
};

#endif