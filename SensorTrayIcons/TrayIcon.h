#pragma once

#include "Defines.h"
#include <QSystemTrayIcon>
#include <QPainter>

class CTrayIcon : public QSystemTrayIcon
{
	//Q_OBJECT

private:
	QPixmap* m_pPixmap{};
	QPainter* m_pPainter{};

	Sensors::SSensorType m_type;
	int m_IconSize;
	QColor m_BackgroundColor;
	QColor m_FontColor;
	QFont m_Font;
	int m_FontSize;
	QString m_Text;

public:
	CTrayIcon(QObject *parent);
	~CTrayIcon();

	void SetType(Sensors::SSensorType _type);
	Sensors::SSensorType GetType() const;

	void SetBackgroundColor(const QColor& _color);
	QColor GetBackgroundColor() const;

	void SetFontColor(const QColor& _color);
	QColor GetFontColor() const;

	void SetFont(const QFont& _font);
	QFont GetFont() const;

	void SetIconSize(int _size);
	QSize GetIconSize() const;

	void SetValue(int8_t _val);
	int8_t GetValue() const;

private:
	void UpdatePainter();
	void UpdateView();
};
