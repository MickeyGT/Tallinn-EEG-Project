#include "Signalifier.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Signalifier w;
	w.show();
	qRegisterMetaType<QVector<int> >("QVector<int>");
	qRegisterMetaType<QPair<double, double> >("QPair<double, double>");
	return a.exec();
}
