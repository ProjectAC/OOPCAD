#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_try_3.h"

class try_3 : public QMainWindow
{
	Q_OBJECT

public:
	try_3(QWidget *parent = Q_NULLPTR);

private:
	Ui::try_3Class ui;
};
