#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP
# include <iostream>
# include <string>
# include "IMonitorModule.hpp"
# include "../includes/monitor.hpp"
# include "Module.hpp"

class Hostname : public Module
{
	public:
		Hostname ();
		~Hostname ();
		Hostname (Hostname const & copy);
		Hostname & operator=(Hostname const & copy);

		void showData();

		std::string getHostname();
		std::string getUsername();
	private:
		std::string _hostname;
		std::string _username;
};

#endif