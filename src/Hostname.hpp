#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP
# include <iostream>
# include <string>
# include "IMonitorModule.hpp"
# include "../includes/monitor.hpp"

class Hostname : public IMonitorModule
{
	public:
		Hostname ();
		~Hostname ();
		Hostname (Hostname const & copy);
		Hostname & operator=(Hostname const & copy);
		std::string getHostname();
		std::string getUsername();
	private:
		std::string _hostname;
		std::string _username;
};

#endif