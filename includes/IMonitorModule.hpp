#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP
# include <iostream>
# include <string>
#include "Graphic.hpp"

class IMonitorModule
{
	public:
		IMonitorModule ();
		~IMonitorModule ();
		IMonitorModule (IMonitorModule const & copy);
		IMonitorModule & operator=(IMonitorModule const & copy);

		virtual void updateData() = 0;
		virtual void showData() = 0;
		virtual void showGraphicData() = 0;
	private:

};

#endif