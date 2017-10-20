/********************************************************************************
** Form generated from reading UI file 'SensorTrayIcons.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QLabel>
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CSensorTrayIconsClass)
    {
        if (CSensorTrayIconsClass->objectName().isEmpty())
            CSensorTrayIconsClass->setObjectName(QStringLiteral("CSensorTrayIconsClass"));
        CSensorTrayIconsClass->resize(600, 400);
        centralWidget = new QWidget(CSensorTrayIconsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 80, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 120, 47, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 160, 47, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 200, 47, 13));
        CSensorTrayIconsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CSensorTrayIconsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
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
        label->setText(QApplication::translate("CSensorTrayIconsClass", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("CSensorTrayIconsClass", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("CSensorTrayIconsClass", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("CSensorTrayIconsClass", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("CSensorTrayIconsClass", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CSensorTrayIconsClass: public Ui_CSensorTrayIconsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSORTRAYICONS_H
