#include "SensorTrayIcons.h"

CSensorTrayIcons::CSensorTrayIcons(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(&m_updateTimer, &QTimer::timeout, this, &CSensorTrayIcons::UpdateIcons);

	m_updateTimer.start(1000);


	QPixmap pixmap(QSize(24, 24));
	pixmap.fill(Qt::white);

	QFont font;
	font.setPixelSize(20);

	QPainter painter(&pixmap);
	painter.setFont(font);
	painter.drawText(pixmap.rect(), Qt::AlignCenter, "00");

	QIcon icon(pixmap);

	QSystemTrayIcon* trayIcon = new QSystemTrayIcon(this);
	trayIcon->setIcon(icon);
	trayIcon->setToolTip("Icon");
	trayIcon->show();
}

CSensorTrayIcons::~CSensorTrayIcons()
{

}

void CSensorTrayIcons::UpdateIcons()
{
	ui.label->setText(QString::number(m_system.GetCPULoad()));
	ui.label_2->setText(QString::number(m_system.GetCPULoad2()));
	ui.label_3->setText(QString::number(m_system.GetRAMLoad()));
	ui.label_4->setText(QString::number(m_system.GetHDDLoad()));
}
