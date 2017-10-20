#pragma once

#include "ui_SensorTrayIcons.h"
#include <QTimer>
#include <QSystemTrayIcon>
#include <QPainter>
#include "SystemInfo.h"

class CSensorTrayIcons : public QMainWindow
{
	Q_OBJECT

private:
	Ui::CSensorTrayIconsClass ui;

	CSystemInfo m_system;
	QTimer m_updateTimer;

public:
	CSensorTrayIcons(QWidget *parent = 0);
	~CSensorTrayIcons();

private slots:
	void UpdateIcons();
};