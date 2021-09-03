/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_triangle;
    QAction *actionAdd_rectangle;
    QAction *actionAdd_circle;
    QAction *actionConnect_the_figures;
    QAction *actionMove_a_figure;
    QAction *actionDelete_a_figure;
    QAction *actionSave;
    QAction *actionOpen;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(539, 416);
        actionAdd_triangle = new QAction(MainWindow);
        actionAdd_triangle->setObjectName(QString::fromUtf8("actionAdd_triangle"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_triangle->setIcon(icon);
        actionAdd_rectangle = new QAction(MainWindow);
        actionAdd_rectangle->setObjectName(QString::fromUtf8("actionAdd_rectangle"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/square.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_rectangle->setIcon(icon1);
        actionAdd_circle = new QAction(MainWindow);
        actionAdd_circle->setObjectName(QString::fromUtf8("actionAdd_circle"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_circle->setIcon(icon2);
        actionConnect_the_figures = new QAction(MainWindow);
        actionConnect_the_figures->setObjectName(QString::fromUtf8("actionConnect_the_figures"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/diagonal_line.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect_the_figures->setIcon(icon3);
        actionMove_a_figure = new QAction(MainWindow);
        actionMove_a_figure->setObjectName(QString::fromUtf8("actionMove_a_figure"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/hand.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove_a_figure->setIcon(icon4);
        actionDelete_a_figure = new QAction(MainWindow);
        actionDelete_a_figure->setObjectName(QString::fromUtf8("actionDelete_a_figure"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_a_figure->setIcon(icon5);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/floppy_disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon6);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon7);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 539, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionAdd_triangle);
        toolBar->addAction(actionAdd_rectangle);
        toolBar->addAction(actionAdd_circle);
        toolBar->addSeparator();
        toolBar->addAction(actionConnect_the_figures);
        toolBar->addAction(actionMove_a_figure);
        toolBar->addAction(actionDelete_a_figure);
        toolBar->addSeparator();
        toolBar->addAction(actionSave);
        toolBar->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdd_triangle->setText(QCoreApplication::translate("MainWindow", "Add triangle", nullptr));
#if QT_CONFIG(tooltip)
        actionAdd_triangle->setToolTip(QCoreApplication::translate("MainWindow", "Add triangle", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAdd_rectangle->setText(QCoreApplication::translate("MainWindow", "Add rectangle", nullptr));
#if QT_CONFIG(tooltip)
        actionAdd_rectangle->setToolTip(QCoreApplication::translate("MainWindow", "Add rectangle", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAdd_circle->setText(QCoreApplication::translate("MainWindow", "Add circle", nullptr));
#if QT_CONFIG(tooltip)
        actionAdd_circle->setToolTip(QCoreApplication::translate("MainWindow", "Add circle", nullptr));
#endif // QT_CONFIG(tooltip)
        actionConnect_the_figures->setText(QCoreApplication::translate("MainWindow", "Connect the figures", nullptr));
#if QT_CONFIG(tooltip)
        actionConnect_the_figures->setToolTip(QCoreApplication::translate("MainWindow", "Connect the figures", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMove_a_figure->setText(QCoreApplication::translate("MainWindow", "Move a figure", nullptr));
#if QT_CONFIG(tooltip)
        actionMove_a_figure->setToolTip(QCoreApplication::translate("MainWindow", "Move a figure", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDelete_a_figure->setText(QCoreApplication::translate("MainWindow", "Delete a figure", nullptr));
#if QT_CONFIG(tooltip)
        actionDelete_a_figure->setToolTip(QCoreApplication::translate("MainWindow", "Delete a figure", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "Save", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "Open", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
