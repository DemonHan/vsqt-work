#include "harddisksearch.h"
#include <QtWidgets/QApplication>
#define my_Debug
#ifdef my_Debug
#include <io.h>
#include <fcntl.h>
#include <afx.h>
void InitConsole()
{
	int nRet= 0;
	FILE* fp;
	AllocConsole();
	nRet= _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	fp = _fdopen(nRet, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
}
#endif

int main(int argc, char *argv[])
{
#ifdef my_Debug
	InitConsole();
#endif
	QApplication a(argc, argv);
	HardDiskSearch w;
	w.show();
	return a.exec();
}
