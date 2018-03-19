#include <QtWidgets/QApplication>

#include "EEGsignals.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EEGsignals w;
	w.show();
	return a.exec();
}
//windows.h creates problems with min() and max() from different classes !!