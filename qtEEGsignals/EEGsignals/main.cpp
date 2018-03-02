#include "EEGsignals.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EEGsignals w;
 //   barchart asdf;
//	w.setCentralWidget((asdf.createChart()));
	w.show();
	return a.exec();
}
//windows.h creates problems with min and max !!