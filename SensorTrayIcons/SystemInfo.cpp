#include "SystemInfo.h"
#include <cmath>

CSystemInfo::CSystemInfo()
{
	InitCPU();

	UpdateDisksInfo();
	for (auto& iter : m_DisksInfo)
		InitHDDLoadCounter(iter.first);
}

CSystemInfo::~CSystemInfo()
{
	PdhCloseQuery(m_cpuQuery);
	for (auto& iter : m_HDDTotalLoad)
		PdhCloseQuery(iter.second.m_hddQuery);
}

std::vector<int8_t> CSystemInfo::GetDisks() const
{
	std::vector<int8_t> disks;
	for (auto& iter : m_DisksInfo)
		disks.push_back(iter.first);
	return disks;
}

std::vector<wchar_t> CSystemInfo::GetDiskVolumes(int8_t _disk) const
{
	if (m_DisksInfo.count(_disk))
		return m_DisksInfo.at(_disk);
	return {};
}

int8_t CSystemInfo::GetValue(Sensors::SSensorType _type) const
{
	switch (_type.type)
	{
	case Sensors::ESensorType::CPU_TOTAL_UTILIZATION:	return GetCPULoad();
	case Sensors::ESensorType::RAM_UTILIZATION:			return GetRAMLoad();
	case Sensors::ESensorType::HDD_UTILIZATION:			return GetHDDLoad(_type.index);
	}
	return {};
}

int8_t CSystemInfo::GetCPULoad() const
{
	PDH_FMT_COUNTERVALUE counter;
	PdhCollectQueryData(m_cpuQuery);
	PdhGetFormattedCounterValue(m_cpuTotalLoad, PDH_FMT_DOUBLE, nullptr, &counter);
	return static_cast<int8_t>(std::round(counter.doubleValue));
}

int8_t CSystemInfo::GetRAMLoad() const
{
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	const float usedFrac = 1.f - static_cast<float>(memInfo.ullAvailPhys) / memInfo.ullTotalPhys;
	return static_cast<int8_t>(std::round(usedFrac * 100));
}

int8_t CSystemInfo::GetHDDLoad(int8_t _disk) const
{
	if (!m_HDDTotalLoad.count(_disk)) return 0;	// counter for this disk does not exist
	PDH_FMT_COUNTERVALUE counter;
	PdhCollectQueryData(m_HDDTotalLoad.at(_disk).m_hddQuery);
	PdhGetFormattedCounterValue(m_HDDTotalLoad.at(_disk).m_hddTotalLoad, PDH_FMT_DOUBLE, nullptr, &counter);
	return static_cast<int8_t>(std::round(counter.doubleValue));
}

void CSystemInfo::UpdateDisksInfo()
{
	m_DisksInfo.clear();
	std::vector<wchar_t> vLetters = SystemVolumesLetters();
	for (wchar_t letter : vLetters)
		for (int8_t disk : SystemDiskNumbers(letter))
			m_DisksInfo[disk].push_back(letter);
}

void CSystemInfo::InitCPU()
{
	PdhOpenQuery(nullptr, 0, &m_cpuQuery);
	// You can also use L"\\Processor(*)\\% Processor Time" and get individual CPU values with PdhGetFormattedCounterArray()
	PdhAddEnglishCounter(m_cpuQuery, L"\\Processor(_Total)\\% Processor Time", 0, &m_cpuTotalLoad);
	PdhCollectQueryData(m_cpuQuery);
}

void CSystemInfo::InitHDDLoadCounter(int8_t _disk)
{
	if (!m_DisksInfo.count(_disk)) return;			// disk is not available
	if (m_HDDTotalLoad.count(_disk)) return;	// this counter already initialized
	// open query if necessary
	if(!m_HDDTotalLoad[_disk].m_hddQuery)
		PdhOpenQuery(nullptr, 0, &m_HDDTotalLoad[_disk].m_hddQuery);
	// construct query of format "\\PhysicalDisk(0 C: D: E:)\\% Disk Time"
	std::wstring queryName = L"\\PhysicalDisk(" + std::to_wstring(_disk);
	for (const wchar_t& name : m_DisksInfo[_disk])
		queryName += std::wstring(L" ") + std::wstring(1, name) + std::wstring(L":");
	queryName += L")\\% Disk Time";
	// add counter
	PdhAddEnglishCounter(m_HDDTotalLoad[_disk].m_hddQuery, queryName.data(), 0, &m_HDDTotalLoad[_disk].m_hddTotalLoad);
	PdhCollectQueryData(m_HDDTotalLoad[_disk].m_hddQuery);
}

std::vector<wchar_t> CSystemInfo::SystemVolumesLetters()
{
	std::wstring drives;	// list of drives
	size_t copied;			// number of copied symbols
	do
	{
		const size_t newSize = drives.size() + MAX_PATH;		// current size of the buffer
		drives.resize(newSize + 1);								// resize the buffer
		copied = GetLogicalDriveStrings(newSize, &drives[0]);	// get drives names in form "\\\\.\\C:"
		if (copied == 0) return {};								// error occured
	} while (copied >= drives.size());							// iterate untill the result fits the buffer
	drives.resize(copied);										// resize to the actually written size
	// get only drive names
	std::vector<wchar_t> res;
	for(const auto& wc : drives)
		if (wc != ':' && wc != '\\' && wc != '\0')
			res.push_back(wc);
	return res;
}

std::vector<int8_t> CSystemInfo::SystemDiskNumbers(wchar_t _volume)
{
	// proper logical disk name
	const std::wstring name = L"\\\\.\\" + std::wstring(1, _volume) + L':';
	// open the disk
	HANDLE hHandle = CreateFile(name.data(), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, 0, nullptr);
	if (hHandle == INVALID_HANDLE_VALUE) // can not open specified disk
		return {};

	VOLUME_DISK_EXTENTS vde;	// requested info
	DWORD temp = 0;				// bytes returned
	// get info about the disk
	const BOOL bResult = DeviceIoControl(hHandle, IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS, nullptr, 0, &vde, sizeof(vde), &temp, nullptr);
	if (!bResult)	// failed to get info
		return {};

	// get disks numbers
	std::vector<int8_t> disks;
	for (size_t i = 0; i < vde.NumberOfDiskExtents; ++i)
		disks.push_back(vde.Extents[i].DiskNumber);
	return disks;
}
