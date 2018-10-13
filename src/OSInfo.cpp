#include "OSInfo.hpp"

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

OSInfo::OSInfo()
{
	this->_osname = getOsName();
}

OSInfo::~OSInfo()
{

}

OSInfo::OSInfo(OSInfo const & src)
{
	*this = src;
}

OSInfo & OSInfo::operator=(OSInfo const & copy)
{
	(void)copy;	
	return (*this);
}

std::string OSInfo::getOSName()
{
	return this->_osname;
};