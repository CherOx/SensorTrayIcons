#include "Settings.h"
#include "TrayIcon.h"

CSettings::CSettings(const CSystemInfo* _pSystem)
{
	m_pSystem = _pSystem;

	m_nUpdateTime = Constants::defaultUpdateTime;
	m_nIconSize = Constants::defaultIconSize;

	// create all icons
	for (size_t i = 0; i < Sensors::sensorNumber; ++i)
		switch (Sensors::ESensorType(i))
		{
		case Sensors::ESensorType::CPU_TOTAL_UTILIZATION:
			AddIcon(Sensors::ESensorType(i));
			break;
		case Sensors::ESensorType::RAM_UTILIZATION:
			AddIcon(Sensors::ESensorType(i));
			break;
		case Sensors::ESensorType::HDD_UTILIZATION:
			for (size_t j = 0; j < m_pSystem->GetDisks().size(); ++j)
				AddIcon(Sensors::ESensorType(i), j);
			break;
		}

	// load active icons
	Load();
}

CSettings::~CSettings()
{
}

size_t CSettings::IconsCount() const
{
	return m_vIcons.size();
}

SIconDescriptor CSettings::GetIcon(size_t _index) const
{
	if (_index < m_vIcons.size())
		return m_vIcons[_index];
	return {};
}

unsigned CSettings::GetIconSize() const
{
	return m_nIconSize;
}

unsigned CSettings::GetUpdateTime() const
{
	return m_nUpdateTime;
}

void CSettings::Load()
{
	for (auto& icon : m_vIcons)
	{
		icon.active = true;
	}
}

void CSettings::Save()
{
}

void CSettings::AddIcon(Sensors::ESensorType _type, int8_t _index /*= -1*/)
{
	m_vIcons.push_back({});
	m_vIcons.back().active = false;
	m_vIcons.back().sensor = Sensors::SSensorType{ _type, _index };
	if(_index == -1)
	{
		m_vIcons.back().name = Sensors::sensorNames[static_cast<unsigned>(_type)];
		m_vIcons.back().toolTip = Sensors::sensorToolTips[static_cast<unsigned>(_type)];
	}
	else
	{
		m_vIcons.back().name = Sensors::sensorNames[static_cast<unsigned>(_type)] + QString(" #") + QString::number(_index);
		m_vIcons.back().toolTip = Sensors::sensorToolTips[static_cast<unsigned>(_type)] + QString(" #") + QString::number(_index);
	}
	m_vIcons.back().backgroundColor = Constants::defaultBackgroundColor;
	m_vIcons.back().fontColor = Constants::defaultFontColor;
	m_vIcons.back().font = QFont();
	m_vIcons.back().font.setPixelSize(Constants::defaultFontSize);
}
