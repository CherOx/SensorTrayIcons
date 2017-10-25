#pragma once

#include <QDialog>
#include "ui_SettingsTab.h"

class CSettingsTab : public QDialog
{
	Q_OBJECT

private:
	Ui::CSettingsTab ui;

public:
	CSettingsTab(QWidget *parent = nullptr);
	~CSettingsTab();

	int GetUpdateInterval() const;
	unsigned GetIconSize() const;
};
