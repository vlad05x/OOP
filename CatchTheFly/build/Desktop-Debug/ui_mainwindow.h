/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *l_fly;
    QLabel *l_trap;
    QLabel *l_cactus;
    QLabel *l_cactus_2;
    QLabel *l_cactus_3;
    QLabel *l_cactus_4;
    QLabel *l_cactus_5;
    QLabel *l_cactus_6;
    QLabel *l_cactus_7;
    QLabel *l_fly2;
    QLabel *l_fly3;
    QLabel *l_window;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1089, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        l_fly = new QLabel(centralwidget);
        l_fly->setObjectName("l_fly");
        l_fly->setGeometry(QRect(50, 370, 91, 71));
        l_fly->setPixmap(QPixmap(QString::fromUtf8("fly.png")));
        l_trap = new QLabel(centralwidget);
        l_trap->setObjectName("l_trap");
        l_trap->setGeometry(QRect(929, 10, 151, 111));
        l_trap->setPixmap(QPixmap(QString::fromUtf8("trap.png")));
        l_cactus = new QLabel(centralwidget);
        l_cactus->setObjectName("l_cactus");
        l_cactus->setGeometry(QRect(430, 340, 101, 61));
        l_cactus->setPixmap(QPixmap(QString::fromUtf8("cactus.png")));
        l_cactus_2 = new QLabel(centralwidget);
        l_cactus_2->setObjectName("l_cactus_2");
        l_cactus_2->setGeometry(QRect(330, 90, 91, 61));
        l_cactus_2->setPixmap(QPixmap(QString::fromUtf8("cactus.png")));
        l_cactus_3 = new QLabel(centralwidget);
        l_cactus_3->setObjectName("l_cactus_3");
        l_cactus_3->setGeometry(QRect(810, 140, 101, 61));
        l_cactus_3->setPixmap(QPixmap(QString::fromUtf8("cactus.png")));
        l_cactus_4 = new QLabel(centralwidget);
        l_cactus_4->setObjectName("l_cactus_4");
        l_cactus_4->setGeometry(QRect(710, 340, 91, 61));
        l_cactus_4->setPixmap(QPixmap(QString::fromUtf8("cactus.png")));
        l_cactus_5 = new QLabel(centralwidget);
        l_cactus_5->setObjectName("l_cactus_5");
        l_cactus_5->setGeometry(QRect(610, 10, 91, 61));
        l_cactus_5->setPixmap(QPixmap(QString::fromUtf8("cactus.png")));
        l_cactus_6 = new QLabel(centralwidget);
        l_cactus_6->setObjectName("l_cactus_6");
        l_cactus_6->setGeometry(QRect(540, 170, 91, 61));
        l_cactus_6->setPixmap(QPixmap(QString::fromUtf8("cactus.png")));
        l_cactus_7 = new QLabel(centralwidget);
        l_cactus_7->setObjectName("l_cactus_7");
        l_cactus_7->setGeometry(QRect(900, 350, 91, 61));
        l_cactus_7->setPixmap(QPixmap(QString::fromUtf8("cactus.png")));
        l_fly2 = new QLabel(centralwidget);
        l_fly2->setObjectName("l_fly2");
        l_fly2->setGeometry(QRect(60, 410, 61, 51));
        l_fly2->setPixmap(QPixmap(QString::fromUtf8("fly2.png")));
        l_fly3 = new QLabel(centralwidget);
        l_fly3->setObjectName("l_fly3");
        l_fly3->setGeometry(QRect(70, 450, 61, 51));
        l_fly3->setPixmap(QPixmap(QString::fromUtf8("fly3.png")));
        l_window = new QLabel(centralwidget);
        l_window->setObjectName("l_window");
        l_window->setGeometry(QRect(620, 450, 91, 81));
        l_window->setPixmap(QPixmap(QString::fromUtf8("window.png")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1089, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        l_fly->setText(QString());
        l_trap->setText(QString());
        l_cactus->setText(QString());
        l_cactus_2->setText(QString());
        l_cactus_3->setText(QString());
        l_cactus_4->setText(QString());
        l_cactus_5->setText(QString());
        l_cactus_6->setText(QString());
        l_cactus_7->setText(QString());
        l_fly2->setText(QString());
        l_fly3->setText(QString());
        l_window->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
