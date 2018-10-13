#include "Datetime.hpp"

Datetime::Datetime()
{
	std::stringstream ss;
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	ss << (now->tm_hour) << ':'
		<< (now->tm_min) << ' '
		<< (now->tm_year + 1900) << '-' 
		<< (now->tm_mon + 1) << '-'
		<<  now->tm_mday;
	this->_datetime = ss.str();
}

Datetime::~Datetime()
{

}

Datetime::Datetime(Datetime const & src)
{
	*this = src;
}

Datetime & Datetime::operator=(Datetime const & copy)
{
	(void)copy;	
	return (*this);
}

std::string Datetime::getDatetime()
{
	return this->_datetime;
};