#ifndef MODULE1_HPP
# define MODULE1_HPP
# include <iostream>
# include <string>
# include "IMonitorModule.hpp"

class Module1 : public IMonitorModule
{
	public:
		Module1 ();
		~Module1 ();
		Module1 (Module1 const & copy);
		Module1 & operator=(Module1 const & copy);
		std::string getHostname();
		std::string getUsername();
		std::string getOSName();
		std::string getDatetime();
	private:
		std::string _hostname;
		std::string _username;
		std::string _osname;
		std::string _datetime;

};

#endif