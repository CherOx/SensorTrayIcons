/********************************************************************************
** Form generated from reading UI file 'SettingsTab.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSTAB_H
#define UI_SETTINGSTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CSettingsTab
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
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CSettingsTab)
    {
        if (CSettingsTab->objectName().isEmpty())
            CSettingsTab->setObjectName(QStringLiteral("CSettingsTab"));
        CSettingsTab->resize(255, 157);
        verticalLayout = new QVBoxLayout(CSettingsTab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelUpdate = new QLabel(CSettingsTab);
        labelUpdate->setObjectName(QStringLiteral("labelUpdate"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUpdate);

        spinBoxUpdate = new QSpinBox(CSettingsTab);
        spinBoxUpdate->setObjectName(QStringLiteral("spinBoxUpdate"));
        spinBoxUpdate->setMaximum(10000);
        spinBoxUpdate->setValue(1000);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxUpdate);

        labelSize = new QLabel(CSettingsTab);
        labelSize->setObjectName(QStringLiteral("labelSize"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelSize);

        spinBoxSize = new QSpinBox(CSettingsTab);
        spinBoxSize->setObjectName(QStringLiteral("spinBoxSize"));
        spinBoxSize->setMinimum(1);
        spinBoxSize->setMaximum(100);
        spinBoxSize->setValue(24);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxSize);


        verticalLayout->addLayout(formLayout);

        groupBoxIcons = new QGroupBox(CSettingsTab);
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

        buttonBox = new QDialogButtonBox(CSettingsTab);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CSettingsTab);

        QMetaObject::connectSlotsByName(CSettingsTab);
    } // setupUi

    void retranslateUi(QDialog *CSettingsTab)
    {
        CSettingsTab->setWindowTitle(QApplication::translate("CSettingsTab", "CSettings", Q_NULLPTR));
        labelUpdate->setText(QApplication::translate("CSettingsTab", "Update interval [ms]", Q_NULLPTR));
        labelSize->setText(QApplication::translate("CSettingsTab", "Icon size [px]", Q_NULLPTR));
        groupBoxIcons->setTitle(QApplication::translate("CSettingsTab", "Icons", Q_NULLPTR));
        label->setText(QApplication::translate("CSettingsTab", "CPU utilization", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CSettingsTab", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CSettingsTab: public Ui_CSettingsTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSTAB_H
