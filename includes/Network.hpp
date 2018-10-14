#ifndef NETWORK_HPP
# define NETWORK_HPP
# include <iostream>
# include <string>
#include "../includes/monitor.hpp"

class Network : public Module
{
	public:
		Network ();
		~Network ();
		Network (Network const & copy);
		Network & operator=(Network const & copy);	

		void showGraphicData();
	private:
		std::string _raw[4]; 
};

#endif