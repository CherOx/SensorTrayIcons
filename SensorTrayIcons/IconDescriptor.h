#pragma once

#include <QFont>
#include <QColor>

class CIconDescriptor
{
private:
	bool m_active;
	//Sensors::ESensorType sensor;
	QString m_name;
	QString m_description;
	QColor m_backgroundColor;
	QColor m_textColor;
	QFont m_font;

public:
	CIconDescriptor();
	~CIconDescriptor();
};

