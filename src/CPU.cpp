#include "../includes/CPU.hpp"

void CPU::updateData()
{
	_ok[0] = getCMDOutput("top -l 1 | grep -E \"^CPU\"| cut -d \" \" -f 3");
	_ok[1] = getCMDOutput("top -l 1 | grep -E \"^CPU\"| cut -d \" \" -f 5");
	_ok[2] = getCMDOutput("top -l 1 | grep -E \"^CPU\"| cut -d \" \" -f 7");

	_ok[0].resize(_ok[0].length() - 1);
	_ok[1].resize(_ok[1].length() - 1);
	_ok[2].resize(_ok[2].length() - 1);
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


void CPU::showData()
{
	std::string l = std::to_string(this->getCoresNumber());

	attron(COLOR_PAIR(1));
	rectangle(10, 0, 16, 50);
	attroff(COLOR_PAIR(1));
	mvprintw(11, 25, "CPU");
	mvprintw(12, 2, "Model: ");	
	mvprintw(12, 9, getModel().c_str());
	mvprintw(13, 2, "CPU Load: ");	
	mvprintw(14, 2, "User: ");
	mvprintw(14, 8, _ok[0].c_str());
	mvprintw(14, 14, "Sys: ");
	mvprintw(14, 19, _ok[1].c_str());
	mvprintw(14, 25, "Total: ");
	mvprintw(14, 32, _ok[2].c_str());
	mvprintw(15, 2, "Number of cores: ");	
	mvprintw(15, 19, l.c_str());
}

void CPU::showGraphicData()
{
	
}