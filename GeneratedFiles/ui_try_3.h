/********************************************************************************
** Form generated from reading UI file 'try_3.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRY_3_H
#define UI_TRY_3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_try_3Class
{
public:
    QAction *openAction;
    QAction *saveAction;
    QAction *quitAction;
    QAction *undoAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *polygonCreate;
    QAction *circleCreate;
    QAction *ellipseCreate;
    QAction *namelist;
    QWidget *centralWidget;
    QOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *try_3Class)
    {
        if (try_3Class->objectName().isEmpty())
            try_3Class->setObjectName(QStringLiteral("try_3Class"));
        try_3Class->resize(600, 400);
        openAction = new QAction(try_3Class);
        openAction->setObjectName(QStringLiteral("openAction"));
        saveAction = new QAction(try_3Class);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        quitAction = new QAction(try_3Class);
        quitAction->setObjectName(QStringLiteral("quitAction"));
        undoAction = new QAction(try_3Class);
        undoAction->setObjectName(QStringLiteral("undoAction"));
        copyAction = new QAction(try_3Class);
        copyAction->setObjectName(QStringLiteral("copyAction"));
        pasteAction = new QAction(try_3Class);
        pasteAction->setObjectName(QStringLiteral("pasteAction"));
        polygonCreate = new QAction(try_3Class);
        polygonCreate->setObjectName(QStringLiteral("polygonCreate"));
        circleCreate = new QAction(try_3Class);
        circleCreate->setObjectName(QStringLiteral("circleCreate"));
        ellipseCreate = new QAction(try_3Class);
        ellipseCreate->setObjectName(QStringLiteral("ellipseCreate"));
        namelist = new QAction(try_3Class);
        namelist->setObjectName(QStringLiteral("namelist"));
        centralWidget = new QWidget(try_3Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(100, 50, 381, 251));
        try_3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(try_3Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        try_3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(try_3Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        try_3Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(try_3Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        try_3Class->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(openAction);
        menu->addAction(saveAction);
        menu->addAction(quitAction);
        menu_2->addAction(undoAction);
        menu_2->addAction(copyAction);
        menu_2->addAction(pasteAction);
        menu_3->addAction(polygonCreate);
        menu_3->addAction(circleCreate);
        menu_3->addAction(ellipseCreate);
        menu_4->addAction(namelist);

        retranslateUi(try_3Class);
        QObject::connect(quitAction, SIGNAL(triggered()), try_3Class, SLOT(close()));

        QMetaObject::connectSlotsByName(try_3Class);
    } // setupUi

    void retranslateUi(QMainWindow *try_3Class)
    {
        try_3Class->setWindowTitle(QApplication::translate("try_3Class", "try_3", Q_NULLPTR));
        openAction->setText(QApplication::translate("try_3Class", "\346\211\223\345\274\200", Q_NULLPTR));
        saveAction->setText(QApplication::translate("try_3Class", "\344\277\235\345\255\230", Q_NULLPTR));
        quitAction->setText(QApplication::translate("try_3Class", "\347\246\273\345\274\200", Q_NULLPTR));
        undoAction->setText(QApplication::translate("try_3Class", "\346\222\244\351\224\200", Q_NULLPTR));
        copyAction->setText(QApplication::translate("try_3Class", "\345\244\215\345\210\266", Q_NULLPTR));
        pasteAction->setText(QApplication::translate("try_3Class", "\347\262\230\350\264\264", Q_NULLPTR));
        polygonCreate->setText(QApplication::translate("try_3Class", "\345\244\232\350\276\271\345\275\242", Q_NULLPTR));
        circleCreate->setText(QApplication::translate("try_3Class", "\345\234\206", Q_NULLPTR));
        ellipseCreate->setText(QApplication::translate("try_3Class", "\346\244\255\345\234\206", Q_NULLPTR));
        namelist->setText(QApplication::translate("try_3Class", "\345\274\200\345\217\221\350\200\205\345\220\215\345\215\225", Q_NULLPTR));
        menu->setTitle(QApplication::translate("try_3Class", "\345\274\200\345\247\213", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("try_3Class", "\347\274\226\350\276\221", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("try_3Class", "\345\210\233\345\273\272", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("try_3Class", "\345\205\263\344\272\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class try_3Class: public Ui_try_3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRY_3_H
