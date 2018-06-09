#pragma once

#include <QColor>

namespace Sensors
{
	enum class ESensorType : unsigned
	{
		CPU_TOTAL_UTILIZATION = 0,
		RAM_UTILIZATION = 1,
		HDD_C_UTILIZATION = 2
	};

	const unsigned sensorNumber = 3;

	const char* const sensorNames[sensorNumber] =
	{
		"CPU Utilization",
		"RAM Utilization",
		"Drive C: Utilization"
	};
	const char* const sensorToolTips[sensorNumber] =
	{
		"CPU Utilization",
		"RAM Utilization",
		"Drive C: Utilization"
	};
}


namespace Constants
{
	static const unsigned defaultIconSize = 24;
	static const int defaultFontSize = 18;
	static const QColor defaultBackgroundColor = QColor(Qt::white);
	static const QColor defaultFontColor = QColor(Qt::black);
	static const QString defaultText = "00";
	static const QString defaultToolTip = "";
	static const unsigned defaultUpdateTime = 1000;
}

