#ifndef SHELL_HPP
# define SHELL_HPP
# include <iostream>
# include <string>
# include "IMonitorDisplay.hpp"

class Shell : public IMonitorDisplay
{
	public:
		Shell ();
		~Shell ();
		Shell (Shell const & copy);
		Shell & operator=(Shell const & copy);

		virtual void showShellData();
	private:
		Hostname h;
		OSInfo os;
		CPU cpu;

};

#endif