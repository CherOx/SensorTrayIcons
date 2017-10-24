/********************************************************************************
** Form generated from reading UI file 'Settings.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CSettings
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelUpdate;
    QSpinBox *spinBoxUpdate;
    QLabel *labelSize;
    QSpinBox *spinBoxSize;
    QGroupBox *groupBoxIcons;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *CSettings)
    {
        if (CSettings->objectName().isEmpty())
            CSettings->setObjectName(QStringLiteral("CSettings"));
        CSettings->resize(187, 128);
        verticalLayout = new QVBoxLayout(CSettings);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelUpdate = new QLabel(CSettings);
        labelUpdate->setObjectName(QStringLiteral("labelUpdate"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUpdate);

        spinBoxUpdate = new QSpinBox(CSettings);
        spinBoxUpdate->setObjectName(QStringLiteral("spinBoxUpdate"));
        spinBoxUpdate->setMaximum(10000);
        spinBoxUpdate->setValue(1000);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxUpdate);

        labelSize = new QLabel(CSettings);
        labelSize->setObjectName(QStringLiteral("labelSize"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelSize);

        spinBoxSize = new QSpinBox(CSettings);
        spinBoxSize->setObjectName(QStringLiteral("spinBoxSize"));
        spinBoxSize->setMinimum(1);
        spinBoxSize->setMaximum(100);
        spinBoxSize->setValue(24);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxSize);


        verticalLayout->addLayout(formLayout);

        groupBoxIcons = new QGroupBox(CSettings);
        groupBoxIcons->setObjectName(QStringLiteral("groupBoxIcons"));
        gridLayout = new QGridLayout(groupBoxIcons);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBoxIcons);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(groupBoxIcons);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBoxIcons);


        retranslateUi(CSettings);

        QMetaObject::connectSlotsByName(CSettings);
    } // setupUi

    void retranslateUi(QDialog *CSettings)
    {
        CSettings->setWindowTitle(QApplication::translate("CSettings", "CSettings", Q_NULLPTR));
        labelUpdate->setText(QApplication::translate("CSettings", "Update interval [ms]", Q_NULLPTR));
        labelSize->setText(QApplication::translate("CSettings", "Icon size [px]", Q_NULLPTR));
        groupBoxIcons->setTitle(QApplication::translate("CSettings", "Icons", Q_NULLPTR));
        label->setText(QApplication::translate("CSettings", "CPU utilization", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CSettings", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CSettings: public Ui_CSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
