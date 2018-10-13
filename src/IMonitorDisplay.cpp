#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay()
{

}

IMonitorDisplay::~IMonitorDisplay()
{

}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const & src)
{
	*this = src;
}

IMonitorDisplay & IMonitorDisplay::operator=(IMonitorDisplay const & copy)
{
	(void)copy;
	return (*this);
}
