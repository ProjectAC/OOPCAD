#include "stdafx.h"
#include "cad.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CAD w;
	w.show();
	return a.exec();
}
