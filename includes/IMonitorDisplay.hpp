#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP
# include <iostream>
# include <string>
# include "monitor.hpp"

class IMonitorDisplay
{
	public:
		IMonitorDisplay ();
		~IMonitorDisplay ();
		IMonitorDisplay (IMonitorDisplay const & copy);
		IMonitorDisplay & operator=(IMonitorDisplay const & copy);
	
		virtual void showData() = 0;
	private:



};


#endif