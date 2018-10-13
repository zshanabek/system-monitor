#include "Module1.hpp"
#include "../includes/monitor.hpp"

std::string getOsName()
{
    #ifdef _WIN64
    return "Windows 64-bit";
    #elif __unix || __unix__
    return "Unix";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #else
    return "Other";
    #endif
}   

Module1::Module1()
{
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];

	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);

	this->_hostname = hostname;
	this->_username = username;

	this->_osname = getOsName();

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

Module1::~Module1()
{

}

Module1::Module1(Module1 const & src)
{
	*this = src;
}

Module1 & Module1::operator=(Module1 const & copy)
{
	(void)copy;
	return (*this);
}

std::string Module1::getHostname()
{
	return this->_hostname;
};

std::string Module1::getUsername()
{
	return this->_username;
};

std::string Module1::getOSName()
{
	return this->_osname;
};

std::string Module1::getDatetime()
{
	return this->_datetime;
};