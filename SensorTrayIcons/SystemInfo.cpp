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
	static const int8_t errResult = -1;

	FILETIME currIdleTime;
	FILETIME currKernTime;
	FILETIME currUserTime;
	BOOL res = GetSystemTimes(&currIdleTime, &currKernTime, &currUserTime);
	if (res == 0) return errResult;

	static uint64_t prevIdleTicks = 0;
	static uint64_t prevBusyTicks = 0;

	uint64_t currIdleTicks = Filetime2UInt64(currIdleTime);
	uint64_t currBusyTicks = Filetime2UInt64(currKernTime) + Filetime2UInt64(currUserTime);

	uint64_t dIdleTicks = currIdleTicks - prevIdleTicks;
	uint64_t dBusyTicks = currBusyTicks - prevBusyTicks;

	prevIdleTicks = currIdleTicks;
	prevBusyTicks = currBusyTicks;

	if (dBusyTicks == 0) return errResult;

	float busyFrac = 1.f - (float)dIdleTicks / dBusyTicks;
	return static_cast<int8_t>(round(busyFrac * 100));
}

int8_t CSystemInfo::GetCPULoad2()
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

uint64_t CSystemInfo::Filetime2UInt64(const FILETIME& _val) const
{
	return static_cast<uint64_t>(_val.dwHighDateTime) << 32 | static_cast<uint64_t>(_val.dwLowDateTime);
}
