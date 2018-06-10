/********************************************************************************
** Form generated from reading UI file 'SensorTrayIcons.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSORTRAYICONS_H
#define UI_SENSORTRAYICONS_H

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

QT_BEGIN_NAMESPACE

class Ui_CSensorTrayIconsClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CSensorTrayIconsClass)
    {
        if (CSensorTrayIconsClass->objectName().isEmpty())
            CSensorTrayIconsClass->setObjectName(QStringLiteral("CSensorTrayIconsClass"));
        CSensorTrayIconsClass->setEnabled(true);
        CSensorTrayIconsClass->resize(94, 69);
        centralWidget = new QWidget(CSensorTrayIconsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CSensorTrayIconsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CSensorTrayIconsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 94, 21));
        CSensorTrayIconsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CSensorTrayIconsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CSensorTrayIconsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CSensorTrayIconsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CSensorTrayIconsClass->setStatusBar(statusBar);

        retranslateUi(CSensorTrayIconsClass);

        QMetaObject::connectSlotsByName(CSensorTrayIconsClass);
    } // setupUi

    void retranslateUi(QMainWindow *CSensorTrayIconsClass)
    {
        CSensorTrayIconsClass->setWindowTitle(QApplication::translate("CSensorTrayIconsClass", "CSensorTrayIcons", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CSensorTrayIconsClass: public Ui_CSensorTrayIconsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSORTRAYICONS_H
