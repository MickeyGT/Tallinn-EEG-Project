/********************************************************************************
** Form generated from reading UI file 'Signalifier.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALIFIER_H
#define UI_SIGNALIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
    QPushButton *button3;
    QPushButton *button1;
    QPushButton *button4;
    QCustomPlot *bitalinoDevice2;
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
        button3 = new QPushButton(centralWidget);
        button3->setObjectName(QStringLiteral("button3"));
        button3->setGeometry(QRect(20, 200, 101, 81));
        button1 = new QPushButton(centralWidget);
        button1->setObjectName(QStringLiteral("button1"));
        button1->setGeometry(QRect(20, 30, 101, 81));
        button4 = new QPushButton(centralWidget);
        button4->setObjectName(QStringLiteral("button4"));
        button4->setGeometry(QRect(160, 200, 101, 81));
        bitalinoDevice2 = new QCustomPlot(centralWidget);
        bitalinoDevice2->setObjectName(QStringLiteral("bitalinoDevice2"));
        bitalinoDevice2->setGeometry(QRect(300, 170, 451, 141));
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
        SignalifierClass->setWindowTitle(QApplication::translate("SignalifierClass", "Signalifier", Q_NULLPTR));
        button2->setText(QApplication::translate("SignalifierClass", "Sending Options", Q_NULLPTR));
        button3->setText(QApplication::translate("SignalifierClass", "RecevingPort", Q_NULLPTR));
        button1->setText(QApplication::translate("SignalifierClass", "RecevingPort", Q_NULLPTR));
        button4->setText(QApplication::translate("SignalifierClass", "Sending Options", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SignalifierClass: public Ui_SignalifierClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALIFIER_H
