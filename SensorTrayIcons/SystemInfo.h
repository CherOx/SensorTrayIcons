#pragma once

#include "Defines.h"
#include "Pdh.h"
#include <cstdint>
#include <vector>
#include <map>

class CSystemInfo
{
private:
	struct SHDDCounter
	{
		PDH_HQUERY m_hddQuery{};		/// Query for HDD counters.
		PDH_HCOUNTER m_hddTotalLoad{};	/// HDD total load counter.
	};

	PDH_HQUERY m_cpuQuery{};
	PDH_HCOUNTER m_cpuTotalLoad{};

	std::map<int8_t, SHDDCounter> m_HDDTotalLoad;	/// HDD counter for each physical disk.

	std::map<int8_t, std::vector<wchar_t>> m_DisksInfo;	/// Correspondence between no. of physical disks and logical volumes.

public:
	CSystemInfo();
	~CSystemInfo();

	/// Returns list of available physical disks.
	std::vector<int8_t> GetDisks() const;
	/// Returns list of volumes on the specified physical disk.
	std::vector<wchar_t> GetDiskVolumes(int8_t _disk) const;

	/// Returns value of the corresponding sensor.
	int8_t GetValue(Sensors::SSensorType _type) const;

	/// Returns CPU load in %.
	int8_t GetCPULoad() const;
	/// Returns RAM load in %.
	int8_t GetRAMLoad() const;
	/// Returns HDD load in % for the specified disk.
	int8_t GetHDDLoad(int8_t _disk) const;

	/// Updates information about available disks.
	void UpdateDisksInfo();

private:
	void InitCPU();

	/// Initialize HDD load counter for specified disk.
	void InitHDDLoadCounter(int8_t _disk);

	/// Returns the letters for all available logical volumes.
	static std::vector<wchar_t> SystemVolumesLetters();

	/// Returns the no. of physical disks where the specified volume is placed. The _volume in format 'C', 'D', etc. If the disk can not be determined, returns empty list.
	static std::vector<int8_t> SystemDiskNumbers(wchar_t _volume);
};

