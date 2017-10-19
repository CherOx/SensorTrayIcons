#pragma once

#include <Windows.h>
#include <cstdint>

#include "TCHAR.h"
#include "pdh.h"

class CSystemInfo
{
private:
	PDH_HQUERY cpuQuery;
	PDH_HCOUNTER cpuTotal;

public:
	CSystemInfo();
	~CSystemInfo();

	int8_t GetCPULoad() const;

private:
	uint64_t Filetime2UInt64(const FILETIME& _val) const;
};

