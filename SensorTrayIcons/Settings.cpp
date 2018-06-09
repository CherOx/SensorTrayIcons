#include "Settings.h"

CSettings::CSettings()
{
	m_nUpdateTime = Constants::defaultUpdateTime;
	m_nIconSize = Constants::defaultIconSize;

	for (size_t i = 0; i < Sensors::sensorNumber; ++i)
	{
		SIconDescriptor descr;
		descr.sensor = static_cast<Sensors::ESensorType>(i);
		descr.name = Sensors::sensorNames[i];
		descr.toolTip = Sensors::sensorToolTips[i];
	}
}

CSettings::~CSettings()
{
}
