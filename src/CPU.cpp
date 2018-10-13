#include "CPU.hpp"

CPU::CPU()
{
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
