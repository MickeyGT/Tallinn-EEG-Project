#include "FftFactory.h"
#include <qprocess.h>
#include <qdebug.h>


void FftFactory::process()
{
	QStringList args;
	args << "E:\\Tallinn-EEG-Project\\Signalifier\\FFT-computor\\FFT.py";
	for (const auto& i : _data)
	{
		args << QString::number(i);
	}

	QProcess process;
	process.setProcessChannelMode(QProcess::MergedChannels);

	process.start(QString("python.exe"), args);

	process.waitForReadyRead();

	QString result(process.readAllStandardOutput());
//	qDebug() << result;

	QPair<double, double> alphaThetaPair = parsePythonScriptResponse(result);

	emit sendResult(alphaThetaPair);

	process.waitForFinished();
	emit isFftFactoryRunning(false);
}

QPair<double, double> FftFactory::parsePythonScriptResponse(const QString& response)
{
	QString auxString1 = response.section(':', 1, 1);
	QString thetaSignal = auxString1.section(',', 0, 0);
	QString auxString2 = response.section(':', 2, 2);
	QString alphaSignal = auxString2.section('}', 0, 0);

	return qMakePair(thetaSignal.toDouble(), alphaSignal.toDouble());
}
