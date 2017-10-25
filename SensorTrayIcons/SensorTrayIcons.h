#pragma once

#include "ui_SensorTrayIcons.h"
#include <QTimer>
#include <QTime>
#include <QSystemTrayIcon>
#include "SystemInfo.h"
#include "TrayIcon.h"
#include "Settings.h"
#include "SettingsTab.h"

class CSensorTrayIcons : public QMainWindow
{
	Q_OBJECT

private:
	Ui::CSensorTrayIconsClass ui;

	CSettingsTab* m_pSettingsTab;
	CSystemInfo m_system;
	QTimer m_updateTimer;
	int m_nUpdateInterval;

	std::vector<CTrayIcon*> m_pvIcons;

public:
	CSensorTrayIcons(QWidget *parent = nullptr);
	~CSensorTrayIcons();

private:
	QMenu* CreateMenu();

private slots:
	void OpenSettings();
	void ApplySettings();
	void OpenAbout();
	void UpdateIcons();
};