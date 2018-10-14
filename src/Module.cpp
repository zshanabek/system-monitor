#include "../includes/Module.hpp"

Module::Module()
{

}

Module::~Module()
{

}

std::string					Module::getCMDOutput(const char *cmd)
{
	FILE					*pipe;
	char					buff[128];
	std::string				output;
	
	if ((pipe = popen(cmd, "r")))
	{
		while (fgets(buff, 128, pipe) != NULL)
			output += buff;
		pclose(pipe);
	}
	return output;
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

void Module::pushback(Module* ok)
{
	this->modules.push_back(ok);
}

void Module::updateData()
{
	for (it = modules.begin(); it != modules.end(); ++it)
	{
		(*it)->updateData();
	}
}

void Module::showData()
{
	for (it = modules.begin(); it != modules.end(); ++it)
	{
		(*it)->showData();
	}
}

void Module::showGraphicData()
{
	for (it = modules.begin(); it != modules.end(); ++it)
	{
		(*it)->showGraphicData();
	}
}