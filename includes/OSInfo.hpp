#ifndef OSINFO_HPP
# define OSINFO_HPP
# include <iostream>
# include <string>
# include "monitor.hpp"
# include "Module.hpp"

class OSInfo : public Module
{
	public:
		OSInfo ();
		~OSInfo ();
		OSInfo (OSInfo const & copy);
		OSInfo & operator=(OSInfo const & copy);

		void showData();
		void showGraphicData();

		std::string getOSName();

	private:
		std::string _osname;

};

#endif