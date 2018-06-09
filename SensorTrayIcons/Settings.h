#pragma once

#include <QFont>
#include "Defines.h"

class CSettings
{
private:
	struct SIconDescriptor
	{
		bool active;
		Sensors::ESensorType sensor;
		QString name;
		QColor backgroundColor;
		QColor fontColor;
		QFont font;
		QString toolTip;
	};

	unsigned m_nUpdateTime;
	unsigned m_nIconSize;
	std::vector<SIconDescriptor> m_vIcons;

public:
	CSettings();
	~CSettings();
};

