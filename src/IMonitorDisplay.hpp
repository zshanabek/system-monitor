#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP
# include <iostream>
# include <string>

class IMonitorDisplay
{
	public:
		IMonitorDisplay ();
		~IMonitorDisplay ();
		IMonitorDisplay (IMonitorDisplay const & copy);
		IMonitorDisplay & operator=(IMonitorDisplay const & copy);

	private:

};


#endif