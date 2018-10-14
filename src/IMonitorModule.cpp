#include "../includes/IMonitorModule.hpp"

IMonitorModule::IMonitorModule()
{

}

IMonitorModule::~IMonitorModule()
{

}

IMonitorModule::IMonitorModule(IMonitorModule const & src)
{
	*this = src;
}

IMonitorModule & IMonitorModule::operator=(IMonitorModule const & copy)
{
	(void)copy;	
	return (*this);
}
