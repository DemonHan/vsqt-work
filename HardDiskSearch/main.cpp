#include "harddisksearch.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HardDiskSearch w;
	w.show();
	return a.exec();
}
