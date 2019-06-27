#include "Signalifier.h"
#include <QtWidgets/QApplication>

typedef QVector<int> qvector_int;
typedef QPair<double, double> alphaThetaDouple;

int main(int argc, char *argv[])
{
	qRegisterMetaType<qvector_int>("qvector_int");
	qRegisterMetaType<alphaThetaDouple>("alphaThetaDouple");
	QApplication a(argc, argv);
	Signalifier w;
	w.show();
	return a.exec();
}
