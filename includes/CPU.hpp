#ifndef CPU_HPP
# define CPU_HPP
# include <iostream>
# include <string>
# include "../includes/monitor.hpp"
# include "IMonitorModule.hpp"
# include "Module.hpp"

class CPU : public Module
{
	public:
		CPU ();
		~CPU ();
		CPU (CPU const & copy);
		CPU & operator=(CPU const & copy);

		void updateData();
		void showData();

		int getCoresNumber();
		float getClockSpeed();
		std::string getModel();
	private:
		std::string _model;
		float _clock_speed;
		int _cores;
};


#endif