#pragma once

#include <QColor>

enum class ESensorType : unsigned
{
	CPU_TOTAL_UTILIZATION,
	RAM_UTILIZATION,
	HDD_C_UTILIZATION
};

const char* const SensorNames[3] =
{
	"CPU Utilization",
	"RAM Utilization",
	"Drive C: Utilization"
};
const char* const SensorToolTips[3] =
{
	"CPU Utilization",
	"RAM Utilization",
	"Drive C: Utilization"
};

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

