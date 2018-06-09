#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_cad.h"

class CAD : public QMainWindow
{
	Q_OBJECT

public:
	CAD(QWidget *parent = Q_NULLPTR);

private:
	Ui::CADClass ui;
};
