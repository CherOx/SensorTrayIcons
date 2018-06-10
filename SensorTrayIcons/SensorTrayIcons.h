#pragma once

#include "ui_SensorTrayIcons.h"
#include "SystemInfo.h"
#include "TrayIcon.h"
#include "Settings.h"
#include "SettingsTab.h"
#include <QTimer>

class CSensorTrayIcons : public QMainWindow
{
	Q_OBJECT

private:
	Ui::CSensorTrayIconsClass ui;

	CSettings* m_pSettings;
	CSettingsTab* m_pSettingsTab;
	CSystemInfo m_system;
	QTimer m_updateTimer;
	int m_nUpdateInterval;

	std::vector<CTrayIcon*> m_pvIcons;

public:
	CSensorTrayIcons(QWidget *parent = nullptr);

private:
	QMenu* CreateMenu();

private slots:
	void OpenSettings() const;
	void ApplySettings();
	void OpenAbout();
	void UpdateIcons();
};
