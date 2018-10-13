#include "Hostname.hpp"

Hostname::Hostname()
{
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];

	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);

	this->_hostname = hostname;
	this->_username = username;
}

Hostname::~Hostname()
{

}

Hostname::Hostname(Hostname const & src)
{
	*this = src;
}

Hostname & Hostname::operator=(Hostname const & copy)
{
	(void)copy;
	return (*this);
}

std::string Hostname::getHostname()
{
	return this->_hostname;
};

std::string Hostname::getUsername()
{
	return this->_username;
};
