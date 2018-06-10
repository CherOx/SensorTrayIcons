#pragma once

#include <QFont>
#include "SystemInfo.h"

class CSettings
{
private:
	const CSystemInfo* m_pSystem;
	unsigned m_nUpdateTime{};
	unsigned m_nIconSize{};
	std::vector<SIconDescriptor> m_vIcons;

public:
	CSettings(const CSystemInfo* _pSystem);
	~CSettings();

	/// Returns total number of available icons.
	size_t IconsCount() const;
	/// Rerurns descriptor of the specified icon.
	SIconDescriptor GetIcon(size_t _index) const;
	/// Returns the icon size.
	unsigned GetIconSize() const;
	/// Returns update time.
	unsigned GetUpdateTime() const;

private:
	void Load();
	void Save();

	/// Adds icon to the list
	void AddIcon(Sensors::ESensorType _type, int8_t _index = -1);
};

