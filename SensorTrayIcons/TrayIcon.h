#pragma once

#include "Defines.h"
#include <QSystemTrayIcon>
#include <QPainter>

class CTrayIcon : public QSystemTrayIcon
{
	Q_OBJECT

private:
	QPixmap* m_pPixmap;
	QPainter* m_pPainter;

	QColor m_BackgroundColor;
	QColor m_FontColor;
	QFont m_Font;
	QString m_Text;

public:
	CTrayIcon(QObject *parent);
	~CTrayIcon();

	void SetBackgroundColor(const QColor& _color);
	QColor GetBackgroundColor() const;

	void SetFontColor(const QColor& _color);
	QColor GetFontColor() const;

	void SetFont(const QFont& _font);
	QFont GetFont() const;

	void SetIconSize(const QSize& _size);
	QSize GetIconSize() const;

	void SetText(const QString& _text);
	void SetText(const int8_t _val);
	QString GetText() const;

private:
	void Update();
};
