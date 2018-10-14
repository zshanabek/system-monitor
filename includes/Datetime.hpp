#ifndef DATETIME_HPP
# define DATETIME_HPP
# include <iostream>
# include <string>
# include "../includes/monitor.hpp"
#include "IMonitorModule.hpp"
# include "Module.hpp"

class Datetime : public Module
{
	public:
		Datetime ();
		~Datetime ();
		Datetime (Datetime const & copy);
		Datetime & operator=(Datetime const & copy);

		void updateData();
		void showData();

		std::string getDatetime();
	private:
		std::string _datetime;

};

#endif