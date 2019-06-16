#include "Signalifier.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Signalifier w;
	w.show();
	return a.exec();
}
