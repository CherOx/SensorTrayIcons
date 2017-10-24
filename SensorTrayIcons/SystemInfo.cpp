#include "SystemInfo.h"

CSystemInfo::CSystemInfo()
{
	InitCPU();
	InitHDD();
}

CSystemInfo::~CSystemInfo()
{
}

int8_t CSystemInfo::GetCPULoad() const
{
	PDH_FMT_COUNTERVALUE counter;
	PdhCollectQueryData(m_cpuQuery);
	PdhGetFormattedCounterValue(m_cpuTotalLoad, PDH_FMT_DOUBLE, NULL, &counter);
	return static_cast<int8_t>(round(counter.doubleValue));
}

int8_t CSystemInfo::GetRAMLoad() const
{
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);

	float usedFrac = 1.f - (float)memInfo.ullAvailPhys / memInfo.ullTotalPhys;
	return static_cast<int8_t>(round(usedFrac * 100));
}

int8_t CSystemInfo::GetHDDLoad() const
{
	PDH_FMT_COUNTERVALUE counter;
	PdhCollectQueryData(m_hddQuery);
	PdhGetFormattedCounterValue(m_hddTotalLoad, PDH_FMT_DOUBLE, NULL, &counter);
	return static_cast<int8_t>(round(counter.doubleValue));
}

void CSystemInfo::InitCPU()
{
	PdhOpenQuery(NULL, NULL, &m_cpuQuery);
	// You can also use L"\\Processor(*)\\% Processor Time" and get individual CPU values with PdhGetFormattedCounterArray()
	PdhAddEnglishCounter(m_cpuQuery, L"\\Processor(_Total)\\% Processor Time", NULL, &m_cpuTotalLoad);
	PdhCollectQueryData(m_cpuQuery);
}

void CSystemInfo::InitHDD()
{
	PdhOpenQuery(NULL, NULL, &m_hddQuery);
	PdhAddEnglishCounter(m_hddQuery, L"\\PhysicalDisk(0 C:)\\% Disk Time", NULL, &m_hddTotalLoad);
	PdhCollectQueryData(m_hddQuery);
}
