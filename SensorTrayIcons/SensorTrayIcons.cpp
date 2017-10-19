#include "SensorTrayIcons.h"

CSensorTrayIcons::CSensorTrayIcons(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(&m_updateTimer, &QTimer::timeout, this, &CSensorTrayIcons::UpdateIcons);

	m_updateTimer.start(1000);

	QSystemTrayIcon* icon1 = new QSystemTrayIcon(this);
	icon1->show();
}

CSensorTrayIcons::~CSensorTrayIcons()
{

}

void CSensorTrayIcons::UpdateIcons()
{
	ui.label->setText(QString::number(m_system.GetCPULoad()));
}
