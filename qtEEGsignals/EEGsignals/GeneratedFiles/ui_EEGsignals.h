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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EEGsignalsClass
{
public:
    QWidget *centralWidget;
    QPushButton *alphaChannelPortChanger;
    QPushButton *thetaChannelPortChanger;
    QPushButton *getvalue;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
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
        alphaChannelPortChanger = new QPushButton(centralWidget);
        alphaChannelPortChanger->setObjectName(QStringLiteral("alphaChannelPortChanger"));
        alphaChannelPortChanger->setGeometry(QRect(40, 40, 191, 81));
        thetaChannelPortChanger = new QPushButton(centralWidget);
        thetaChannelPortChanger->setObjectName(QStringLiteral("thetaChannelPortChanger"));
        thetaChannelPortChanger->setGeometry(QRect(40, 190, 191, 81));
        getvalue = new QPushButton(centralWidget);
        getvalue->setObjectName(QStringLiteral("getvalue"));
        getvalue->setGeometry(QRect(40, 350, 191, 81));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(300, 40, 501, 391));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
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
        alphaChannelPortChanger->setText(QApplication::translate("EEGsignalsClass", "setAlphaChannel", nullptr));
        thetaChannelPortChanger->setText(QApplication::translate("EEGsignalsClass", "setThetaChannel", nullptr));
        getvalue->setText(QApplication::translate("EEGsignalsClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EEGsignalsClass: public Ui_EEGsignalsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EEGSIGNALS_H