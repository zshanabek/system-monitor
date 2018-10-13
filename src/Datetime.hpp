#ifndef DATETIME_HPP
# define DATETIME_HPP
# include <iostream>
# include <string>
# include "../includes/monitor.hpp"

class Datetime
{
	public:
		Datetime ();
		~Datetime ();
		Datetime (Datetime const & copy);
		Datetime & operator=(Datetime const & copy);

		std::string getDatetime();
	private:
		std::string _datetime;

};

#endif