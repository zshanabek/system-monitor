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
		void showGraphicData();

		int getCoresNumber();
		std::string getModel();
	private:
		std::string _model;
		std::string _ok[6]; 		
		int _cores;
};


#endif