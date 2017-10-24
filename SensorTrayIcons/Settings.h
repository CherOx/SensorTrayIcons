#pragma once

#include <QDialog>
#include "ui_Settings.h"

class CSettings : public QDialog
{
	Q_OBJECT

public:
	CSettings(QWidget *parent = Q_NULLPTR);
	~CSettings();

private:
	Ui::CSettings ui;
};
