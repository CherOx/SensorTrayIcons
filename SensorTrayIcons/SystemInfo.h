#pragma once

#include <Windows.h>
#include <cstdint>
#include <math.h>

#include "TCHAR.h"
#include "pdh.h"

class CSystemInfo
{
private:
	PDH_HQUERY m_cpuQuery;
	PDH_HCOUNTER m_cpuTotalLoad;

	PDH_HQUERY m_hddQuery;
	PDH_HCOUNTER m_hddTotalLoad;

public:
	CSystemInfo();
	~CSystemInfo();

	int8_t GetCPULoad() const;

	int8_t GetRAMLoad() const;

	int8_t GetHDDLoad() const;

private:
	void InitCPU();
	void InitHDD();
};

