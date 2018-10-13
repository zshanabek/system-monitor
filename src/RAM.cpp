#include "RAM.hpp"

RAM::RAM()
{

}

RAM::~RAM()
{

}

RAM::RAM(RAM const & src)
{
	*this = src;
}

RAM & RAM::operator=(RAM const & copy)
{
	(void)copy;	
	return (*this);
}
