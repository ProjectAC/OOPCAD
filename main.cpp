#include "stdafx.h"
#include "try_3.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	try_3 w;
	w.show();
	return a.exec();
}
