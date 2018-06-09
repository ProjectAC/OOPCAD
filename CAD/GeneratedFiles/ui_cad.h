/********************************************************************************
** Form generated from reading UI file 'cad.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAD_H
#define UI_CAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "my_qopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_CADClass
{
public:
    QWidget *centralWidget;
    my_QOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CADClass)
    {
        if (CADClass->objectName().isEmpty())
            CADClass->setObjectName(QStringLiteral("CADClass"));
        CADClass->resize(600, 400);
        centralWidget = new QWidget(CADClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new my_QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(20, 20, 531, 311));
        CADClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CADClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        CADClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CADClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CADClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CADClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CADClass->setStatusBar(statusBar);

        retranslateUi(CADClass);

        QMetaObject::connectSlotsByName(CADClass);
    } // setupUi

    void retranslateUi(QMainWindow *CADClass)
    {
        CADClass->setWindowTitle(QApplication::translate("CADClass", "CAD", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CADClass: public Ui_CADClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAD_H
