#ifndef NETWORK_HPP
# define NETWORK_HPP
# include <iostream>
# include <string>
#include "../includes/monitor.hpp"
#include "../includes/Module.hpp"

class Network : public Module
{
	public:
		Network ();
		~Network ();
		Network (Network const & copy);
		Network & operator=(Network const & copy);	

		void updateData();
		void showGraphicData();
		void showData();
	private:
		std::string _raw[6]; 
};

#endif