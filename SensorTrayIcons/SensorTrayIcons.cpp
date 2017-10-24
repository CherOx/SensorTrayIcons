#include "SensorTrayIcons.h"

CSensorTrayIcons::CSensorTrayIcons(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(&m_updateTimer, &QTimer::timeout, this, &CSensorTrayIcons::UpdateIcons);

	m_updateTimer.start(1000);

	m_pvIcons.push_back(new CTrayIcon(this));
	m_pvIcons.push_back(new CTrayIcon(this));
	m_pvIcons.push_back(new CTrayIcon(this));

	m_pvIcons[0]->setToolTip("CPU");

	QTime dieTime = QTime::currentTime().addMSecs(100);

	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

	m_pvIcons[1]->setToolTip("RAM");

	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

	m_pvIcons[2]->setToolTip("HDD");

	m_pvIcons[0]->SetBackgroundColor(Qt::red);
	m_pvIcons[1]->SetBackgroundColor(Qt::green);
	m_pvIcons[2]->SetBackgroundColor(Qt::blue);

	QMenu* pMenu = CreateMenu();
	for (auto& i : m_pvIcons)
	{
		i->setContextMenu(pMenu);
		i->show();
	}

	QTimer::singleShot(250, this, SLOT(hide()));
}

CSensorTrayIcons::~CSensorTrayIcons()
{

}

QMenu* CSensorTrayIcons::CreateMenu()
{
	QMenu* pMenu = new QMenu(this);
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

void CSensorTrayIcons::OpenSettings()
{

}

void CSensorTrayIcons::OpenAbout()
{

}

void CSensorTrayIcons::UpdateIcons()
{
	m_pvIcons[0]->SetText(m_system.GetCPULoad());
	m_pvIcons[1]->SetText(m_system.GetRAMLoad());
	m_pvIcons[2]->SetText(m_system.GetHDDLoad());
}
