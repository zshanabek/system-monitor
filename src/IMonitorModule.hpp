#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP
# include <iostream>
# include <string>

class IMonitorModule
{
	public:
		IMonitorModule ();
		~IMonitorModule ();
		IMonitorModule (IMonitorModule const & copy);
		IMonitorModule & operator=(IMonitorModule const & copy);

	private:

};

#endif