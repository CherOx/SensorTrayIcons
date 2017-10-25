#include "TrayIcon.h"

CTrayIcon::CTrayIcon(QObject *parent) : QSystemTrayIcon(parent)
{
	m_BackgroundColor = Constants::defaultBackgroundColor;
	m_FontColor = Constants::defaultFontColor;
	m_Text = Constants::defaultText;

	m_pPixmap = new QPixmap(Constants::defaultIconSize, Constants::defaultIconSize);
	m_pPixmap->fill(m_BackgroundColor);

	m_Font.setPixelSize(Constants::defaultFontSize);

	m_pPainter = new QPainter(m_pPixmap);
	m_pPainter->setFont(m_Font);
	m_pPainter->setPen(m_FontColor);
	m_pPainter->drawText(m_pPixmap->rect(), Qt::AlignCenter, m_Text);

	setIcon(*m_pPixmap);
	setToolTip(Constants::defaultToolTip);
}

CTrayIcon::~CTrayIcon()
{
	delete m_pPainter;
	delete m_pPixmap;
}

void CTrayIcon::SetBackgroundColor(const QColor& _color)
{
	m_BackgroundColor = _color;
	Update();
}

QColor CTrayIcon::GetBackgroundColor() const
{
	return m_BackgroundColor;
}

void CTrayIcon::SetFontColor(const QColor& _color)
{
	m_FontColor = _color;
	m_pPainter->setPen(m_FontColor);
	Update();
}

QColor CTrayIcon::GetFontColor() const
{
	return m_FontColor;
}

void CTrayIcon::SetFont(const QFont& _font)
{
	m_Font = _font;
	m_pPainter->setFont(m_Font);
	Update();
}

QFont CTrayIcon::GetFont() const
{
	return m_Font;
}

void CTrayIcon::SetIconSize(const QSize& _size)
{
	delete m_pPixmap;
	m_pPixmap = new QPixmap(_size);
	Update();
}

QSize CTrayIcon::GetIconSize() const
{
	return m_pPixmap->size();
}

void CTrayIcon::SetText(const QString& _text)
{
	m_Text = _text;
	Update();
}

void CTrayIcon::SetText(const int8_t _val)
{
	SetText(QString::number(_val));
}

QString CTrayIcon::GetText() const
{
	return m_Text;
}

void CTrayIcon::Update()
{
	m_pPixmap->fill(m_BackgroundColor);
	m_pPainter->drawText(m_pPixmap->rect(), Qt::AlignCenter, m_Text);
	setIcon(*m_pPixmap);
}
