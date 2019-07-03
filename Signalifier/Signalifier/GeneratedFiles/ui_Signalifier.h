/********************************************************************************
** Form generated from reading UI file 'Signalifier.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALIFIER_H
#define UI_SIGNALIFIER_H

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

class Ui_SignalifierClass
{
public:
    QWidget *centralWidget;
    QPushButton *button2;
    QCustomPlot *bitalinoDevice1;
    QPushButton *button1;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SignalifierClass)
    {
        if (SignalifierClass->objectName().isEmpty())
            SignalifierClass->setObjectName(QStringLiteral("SignalifierClass"));
        SignalifierClass->resize(822, 479);
        centralWidget = new QWidget(SignalifierClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        button2 = new QPushButton(centralWidget);
        button2->setObjectName(QStringLiteral("button2"));
        button2->setGeometry(QRect(160, 30, 101, 81));
        bitalinoDevice1 = new QCustomPlot(centralWidget);
        bitalinoDevice1->setObjectName(QStringLiteral("bitalinoDevice1"));
        bitalinoDevice1->setGeometry(QRect(300, 10, 451, 141));
        button1 = new QPushButton(centralWidget);
        button1->setObjectName(QStringLiteral("button1"));
        button1->setGeometry(QRect(20, 30, 101, 81));
        SignalifierClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SignalifierClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 822, 21));
        SignalifierClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SignalifierClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SignalifierClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SignalifierClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SignalifierClass->setStatusBar(statusBar);

        retranslateUi(SignalifierClass);

        QMetaObject::connectSlotsByName(SignalifierClass);
    } // setupUi

    void retranslateUi(QMainWindow *SignalifierClass)
    {
        SignalifierClass->setWindowTitle(QApplication::translate("SignalifierClass", "Signalifier", nullptr));
        button2->setText(QApplication::translate("SignalifierClass", "Sending Options", nullptr));
        button1->setText(QApplication::translate("SignalifierClass", "Start Device", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignalifierClass: public Ui_SignalifierClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALIFIER_H
