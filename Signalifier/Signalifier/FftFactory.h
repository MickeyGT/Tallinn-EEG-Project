#ifndef FFTFACTORY_H
#define FFTFACTORY_H

#include "bitalino.h"
#include <qvector.h>
#include <qthread.h>

class FftFactory : public QObject
{
	Q_OBJECT

public:
	inline FftFactory(const QVector<int>& data) { _data = data; };

	public slots:
		void process();

	signals:
		void sendResult(const QPair<double, double>&);
		void isFftFactoryRunning(const bool&);

private:
	QPair<double, double> parsePythonScriptResponse(const QString& response);

private:
	QVector<int> _data;

};

#endif