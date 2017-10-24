#pragma once

#include "ui_SensorTrayIcons.h"
#include <QTimer>
#include <QTime>
#include <QSystemTrayIcon>
#include "SystemInfo.h"
#include "TrayIcon.h"

class CSensorTrayIcons : public QMainWindow
{
	Q_OBJECT

private:
	Ui::CSensorTrayIconsClass ui;

	CSystemInfo m_system;
	QTimer m_updateTimer;

	std::vector<CTrayIcon*> m_pvIcons;

public:
	CSensorTrayIcons(QWidget *parent = 0);
	~CSensorTrayIcons();

private:
	QMenu* CreateMenu();

private slots:
	void OpenSettings();
	void OpenAbout();
	void UpdateIcons();
};