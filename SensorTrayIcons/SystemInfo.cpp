#include "SystemInfo.h"

CSystemInfo::CSystemInfo()
{

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
	return static_cast<int8_t>(busyFrac * 100);
}

uint64_t CSystemInfo::Filetime2UInt64(const FILETIME& _val) const
{
	return static_cast<uint64_t>(_val.dwHighDateTime) << 32 | static_cast<uint64_t>(_val.dwLowDateTime);
}
