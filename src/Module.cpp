#include "../includes/Module.hpp"

Module::Module()
{

}

Module::~Module()
{

}

Module::Module(Module const & src)
{
	*this = src;
}

Module & Module::operator=(Module const & copy)
{
	(void)copy;
	return (*this);
}

void Module::pushback(Module ok)
{

	this->modules.push_back(ok);
}

void Module::updateData()
{
	for (it = modules.begin(); it != modules.end(); ++it)
	{
		it->updateData();
	}
}

void Module::showData()
{
	for (it = modules.begin(); it != modules.end(); ++it)
	{
		it->showData();
	}
}