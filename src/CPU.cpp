#include "../includes/CPU.hpp"

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

void CPU::updateData()
{
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
		this->_clock_speed = CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
	}
	this->_clock_speed = -1.0f;
}

CPU::CPU()
{
	char buffer[42];
    size_t bufferlen = 42;
    sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);
	updateData();
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

void CPU::showData()
{
	std::string l = std::to_string(this->getCoresNumber());
	std::string cs = std::to_string(this->getClockSpeed());

	attron(COLOR_PAIR(1));
	// rectangle(10, 0, 16, 50);
	attroff(COLOR_PAIR(1));
	mvprintw(11, 25, "CPU");
	mvprintw(12, 2, "Model: ");	
	mvprintw(12, 9, getModel().c_str());
	mvprintw(13, 2, "CPU Load: ");	
	mvprintw(13, 12, cs.c_str());
	mvprintw(14, 2, "Number of cores: ");	
	mvprintw(14, 19, l.c_str());
}