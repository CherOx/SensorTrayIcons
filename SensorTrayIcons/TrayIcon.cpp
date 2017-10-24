#include "TrayIcon.h"

const QSize CTrayIcon::m_cDefaultIconSize = QSize(24, 24);
const int CTrayIcon::m_cDefaultFontSize = 18;
const QColor CTrayIcon::m_cDefaultBackgroundColor = QColor(Qt::yellow);
const QString CTrayIcon::m_cDefaultText = "00";
const QString CTrayIcon::m_cDefaultToolTip = "";

CTrayIcon::CTrayIcon(QObject *parent) : QSystemTrayIcon(parent)
{
	m_BackgroundColor = m_cDefaultBackgroundColor;
	m_Text = m_cDefaultText;

	m_pPixmap = new QPixmap(m_cDefaultIconSize);
	m_pPixmap->fill(m_BackgroundColor);

	m_Font.setPixelSize(m_cDefaultFontSize);

	m_pPainter = new QPainter(m_pPixmap);
	m_pPainter->setFont(m_Font);
	m_pPainter->drawText(m_pPixmap->rect(), Qt::AlignCenter, m_Text);

	setIcon(*m_pPixmap);
	setToolTip(m_cDefaultToolTip);
}

CTrayIcon::~CTrayIcon()
{
	delete m_pPainter;
	delete m_pPixmap;
}

void CTrayIcon::SetBackgroundColor(const QColor& _color)
{
	m_BackgroundColor = _color;
	m_pPixmap->fill(m_BackgroundColor);
}

QColor CTrayIcon::GetBackgroundColor() const
{
	return m_BackgroundColor;
}

void CTrayIcon::SetFont(const QFont& _font)
{
	m_Font = _font;
	m_pPainter->setFont(m_Font);
}

QFont CTrayIcon::GetFont() const
{
	return m_Font;
}

void CTrayIcon::SetIconSize(const QSize& _size)
{
	delete m_pPixmap;
	m_pPixmap = new QPixmap(_size);
	SetBackgroundColor(m_BackgroundColor);
	SetText(m_Text);
}

QSize CTrayIcon::GetIconSize() const
{
	return m_pPixmap->size();
}

void CTrayIcon::SetText(const QString& _text)
{
	m_Text = _text;
	m_pPixmap->fill(m_BackgroundColor);
	m_pPainter->drawText(m_pPixmap->rect(), Qt::AlignCenter, m_Text);
	setIcon(*m_pPixmap);
}

void CTrayIcon::SetText(const int8_t _val)
{
	SetText(QString::number(_val));
}

QString CTrayIcon::GetText() const
{
	return m_Text;
}
