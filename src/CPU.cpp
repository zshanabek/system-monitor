#include "CPU.hpp"

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
	unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
	float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
	_previousTotalTicks = totalTicks;
	_previousIdleTicks  = idleTicks;
	return ret;
}

float GetCPULoad()
{
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
		return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
	}
	else return -1.0f;
}

CPU::CPU()
{
	char buffer[42];
    size_t bufferlen = 42;
    sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);

	this->_clock_speed = GetCPULoad();
	this->_model = buffer;
	this->_cores = sysconf(_SC_NPROCESSORS_ONLN);
}

CPU::~CPU()
{

}

CPU::CPU(CPU const & src)
{
	*this = src;
}

CPU & CPU::operator=(CPU const & copy)
{
	(void)copy;
	return (*this);
}

int CPU::getCoresNumber()
{
	return this->_cores;
}

std::string CPU::getModel()
{
	return this->_model;
}

float CPU::getClockSpeed()
{
	return this->_clock_speed;	
}