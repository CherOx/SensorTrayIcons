#include "SensorTrayIcons.h"
#include <QTime>

CSensorTrayIcons::CSensorTrayIcons(QWidget *parent /*= nullptr*/) : QMainWindow(parent)
{
	ui.setupUi(this);

	m_pSettings = new CSettings(&m_system);
	m_pSettingsTab = new CSettingsTab(this);

	for (size_t i = 0; i < m_pSettings->IconsCount(); ++i)
	{
		const SIconDescriptor icon = m_pSettings->GetIcon(i);
		if(icon.active)
		{
			m_pvIcons.push_back(new CTrayIcon(this));
			m_pvIcons.back()->SetType(icon.sensor);
			m_pvIcons.back()->SetBackgroundColor(icon.backgroundColor);
			m_pvIcons.back()->SetFont(icon.font);
			m_pvIcons.back()->SetFontColor(icon.fontColor);
			m_pvIcons.back()->setToolTip(icon.toolTip);
			m_pvIcons.back()->SetIconSize(m_pSettings->GetIconSize());
		}
	}

	QMenu* pMenu = CreateMenu();
	for (auto& i : m_pvIcons)
	{
		i->setContextMenu(pMenu);
		i->show();
	}

	connect(m_pSettingsTab, &CSettingsTab::accepted,	this, &CSensorTrayIcons::ApplySettings);
	connect(&m_updateTimer, &QTimer::timeout,			this, &CSensorTrayIcons::UpdateIcons);

	m_nUpdateInterval = m_pSettings->GetUpdateTime();
	m_updateTimer.start(m_nUpdateInterval);
}

QMenu* CSensorTrayIcons::CreateMenu()
{
	auto* pMenu = new QMenu(this);
	QAction* pActionSettings = new QAction("Settings", pMenu);
	QAction* pActionAbout = new QAction("About", pMenu);
	QAction* pActionExit = new QAction("Exit", pMenu);
	connect(pActionSettings,	&QAction::triggered, this, &CSensorTrayIcons::OpenSettings);
	connect(pActionAbout,		&QAction::triggered, this, &CSensorTrayIcons::OpenAbout);
	connect(pActionExit,		&QAction::triggered, this, &CSensorTrayIcons::close);
	pMenu->addAction(pActionSettings);
	pMenu->addSeparator();
	pMenu->addAction(pActionAbout);
	pMenu->addSeparator();
	pMenu->addAction(pActionExit);
	return pMenu;
}

void CSensorTrayIcons::OpenSettings() const
{
	m_pSettingsTab->show();
}

void CSensorTrayIcons::ApplySettings()
{
	//if (m_pSettingsTab->GetUpdateInterval() != m_nUpdateInterval)
	//{
	//	m_nUpdateInterval = m_pSettingsTab->GetUpdateInterval();
	//	m_updateTimer.setInterval(m_nUpdateInterval);
	//}
}

void CSensorTrayIcons::OpenAbout()
{

}

void CSensorTrayIcons::UpdateIcons()
{
	for(auto& icon : m_pvIcons)
		icon->SetValue(m_system.GetValue(icon->GetType()));
}
