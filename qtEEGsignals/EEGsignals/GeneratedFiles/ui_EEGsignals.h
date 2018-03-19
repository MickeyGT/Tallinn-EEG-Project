/********************************************************************************
** Form generated from reading UI file 'EEGsignals.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EEGSIGNALS_H
#define UI_EEGSIGNALS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_EEGsignalsClass
{
public:
    QWidget *centralWidget;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QCustomPlot *CustomPlot;
    QCustomPlot *EEGAlphaSignalPlot;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EEGsignalsClass)
    {
        if (EEGsignalsClass->objectName().isEmpty())
            EEGsignalsClass->setObjectName(QStringLiteral("EEGsignalsClass"));
        EEGsignalsClass->resize(820, 527);
        centralWidget = new QWidget(EEGsignalsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        button1 = new QPushButton(centralWidget);
        button1->setObjectName(QStringLiteral("button1"));
        button1->setGeometry(QRect(40, 90, 101, 81));
        button2 = new QPushButton(centralWidget);
        button2->setObjectName(QStringLiteral("button2"));
        button2->setGeometry(QRect(40, 290, 101, 81));
        button3 = new QPushButton(centralWidget);
        button3->setObjectName(QStringLiteral("button3"));
        button3->setGeometry(QRect(160, 90, 101, 81));
        button4 = new QPushButton(centralWidget);
        button4->setObjectName(QStringLiteral("button4"));
        button4->setGeometry(QRect(160, 290, 101, 81));
        CustomPlot = new QCustomPlot(centralWidget);
        CustomPlot->setObjectName(QStringLiteral("CustomPlot"));
        CustomPlot->setGeometry(QRect(320, 240, 451, 231));
        EEGAlphaSignalPlot = new QCustomPlot(centralWidget);
        EEGAlphaSignalPlot->setObjectName(QStringLiteral("EEGAlphaSignalPlot"));
        EEGAlphaSignalPlot->setGeometry(QRect(320, 0, 451, 231));
        EEGsignalsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EEGsignalsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 820, 21));
        EEGsignalsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EEGsignalsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EEGsignalsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EEGsignalsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EEGsignalsClass->setStatusBar(statusBar);

        retranslateUi(EEGsignalsClass);

        QMetaObject::connectSlotsByName(EEGsignalsClass);
    } // setupUi

    void retranslateUi(QMainWindow *EEGsignalsClass)
    {
        EEGsignalsClass->setWindowTitle(QApplication::translate("EEGsignalsClass", "EEGsignals", nullptr));
        button1->setText(QApplication::translate("EEGsignalsClass", "setAlphaChannel", nullptr));
        button2->setText(QApplication::translate("EEGsignalsClass", "setThetaChannel", nullptr));
        button3->setText(QApplication::translate("EEGsignalsClass", "PushButton", nullptr));
        button4->setText(QApplication::translate("EEGsignalsClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EEGsignalsClass: public Ui_EEGsignalsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EEGSIGNALS_H
