#include "TrayIcon.h"

CTrayIcon::CTrayIcon(QObject *parent) : QSystemTrayIcon(parent)
{
	m_IconSize = Constants::defaultIconSize;
	m_BackgroundColor = Constants::defaultBackgroundColor;
	m_FontColor = Constants::defaultFontColor;
	m_FontSize = Constants::defaultFontSize;
	m_Text = Constants::defaultText;

	UpdatePainter();
	UpdateView();

	setToolTip(Constants::defaultToolTip);
}

CTrayIcon::~CTrayIcon()
{
	delete m_pPainter;
	delete m_pPixmap;
}

void CTrayIcon::SetType(Sensors::SSensorType _type)
{
	m_type = _type;
}

Sensors::SSensorType CTrayIcon::GetType() const
{
	return m_type;
}

void CTrayIcon::SetBackgroundColor(const QColor& _color)
{
	m_BackgroundColor = _color;
	UpdateView();
}

QColor CTrayIcon::GetBackgroundColor() const
{
	return m_BackgroundColor;
}

void CTrayIcon::SetFontColor(const QColor& _color)
{
	m_FontColor = _color;
	m_pPainter->setPen(m_FontColor);
	UpdateView();
}

QColor CTrayIcon::GetFontColor() const
{
	return m_FontColor;
}

void CTrayIcon::SetFont(const QFont& _font)
{
	m_Font = _font;
	m_pPainter->setFont(m_Font);
	UpdateView();
}

QFont CTrayIcon::GetFont() const
{
	return m_Font;
}

void CTrayIcon::SetIconSize(int _size)
{
	m_IconSize = _size;
	UpdatePainter();
	UpdateView();
}

QSize CTrayIcon::GetIconSize() const
{
	return m_pPixmap->size();
}

void CTrayIcon::SetValue(const int8_t _val)
{
	m_Text = QString::number(_val);
	UpdateView();
}

int8_t CTrayIcon::GetValue() const
{
	return m_Text.toShort();
}

void CTrayIcon::UpdatePainter()
{
	delete m_pPainter;
	delete m_pPixmap;

	m_pPixmap = new QPixmap(m_IconSize, m_IconSize);
	m_Font.setPixelSize(m_FontSize);
	m_pPainter = new QPainter(m_pPixmap);
	m_pPainter->setFont(m_Font);
	m_pPainter->setPen(m_FontColor);
}

void CTrayIcon::UpdateView()
{
	m_pPixmap->fill(m_BackgroundColor);
	m_pPainter->drawText(m_pPixmap->rect(), Qt::AlignCenter, m_Text);
	setIcon(*m_pPixmap);
}
