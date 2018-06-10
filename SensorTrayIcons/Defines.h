#pragma once

#include <QColor>
#include <QFont>

namespace Sensors
{
	enum class ESensorType : unsigned
	{
		CPU_TOTAL_UTILIZATION = 0,
		RAM_UTILIZATION       = 1,
		HDD_UTILIZATION       = 2
	};

	struct SSensorType
	{
		ESensorType type;	// type itself
		int8_t index;		// index of the device, if applicable
		SSensorType() : type(ESensorType::CPU_TOTAL_UTILIZATION), index(0) {}
		SSensorType(ESensorType _type, int8_t _index = 0) : type(_type), index(_index) {}
	};

	const unsigned sensorNumber = 3;

	const char* const sensorNames[sensorNumber] =
	{
		"CPU Utilization",
		"RAM Utilization",
		"HDD Utilization"
	};
	const char* const sensorToolTips[sensorNumber] =
	{
		"CPU Utilization",
		"RAM Utilization",
		"HDD Utilization"
	};
}

struct SIconDescriptor
{
	bool active{};
	Sensors::SSensorType sensor;
	QString name;
	QColor backgroundColor;
	QColor fontColor;
	QFont font;
	QString toolTip;
};

namespace Constants
{
	static const int defaultIconSize = 24;
	static const int defaultFontSize = 18;
	static const QColor defaultBackgroundColor = QColor(Qt::white);
	static const QColor defaultFontColor = QColor(Qt::black);
	static const QString defaultText = "00";
	static const QString defaultToolTip = "";
	static const unsigned defaultUpdateTime = 1000;
}
