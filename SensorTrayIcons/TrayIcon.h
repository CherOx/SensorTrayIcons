#pragma once

#include <QSystemTrayIcon>
#include <QPainter>

class CTrayIcon : public QSystemTrayIcon
{
	Q_OBJECT

private:
	static const QSize m_cDefaultIconSize;
	static const int m_cDefaultFontSize;
	static const QColor m_cDefaultBackgroundColor;
	static const QString m_cDefaultText;
	static const QString m_cDefaultToolTip;

	QPixmap* m_pPixmap;
	QPainter* m_pPainter;

	QColor m_BackgroundColor;
	QFont m_Font;
	QString m_Text;

public:
	CTrayIcon(QObject *parent);
	~CTrayIcon();

	void SetBackgroundColor(const QColor& _color);
	QColor GetBackgroundColor() const;

	void SetFont(const QFont& _font);
	QFont GetFont() const;

	void SetIconSize(const QSize& _size);
	QSize GetIconSize() const;

	void SetText(const QString& _text);
	void SetText(const int8_t _val);
	QString GetText() const;
};
