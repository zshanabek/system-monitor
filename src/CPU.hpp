#ifndef CPU_HPP
# define CPU_HPP
# include <iostream>
# include <string>
# include "../includes/monitor.hpp"

class CPU
{
	public:
		CPU ();
		~CPU ();
		CPU (CPU const & copy);
		CPU & operator=(CPU const & copy);
		int getCoresNumber();
	private:
		std::string model;
		// float _clock_speed;
		int _cores;
};


#endif