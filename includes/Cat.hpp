#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include <string>
# include "../includes/monitor.hpp"
# include "IMonitorModule.hpp"
# include "Module.hpp"
class Cat : public Module
{
	public:
		Cat ();
		~Cat ();
		Cat (Cat const & copy);
		Cat & operator=(Cat const & copy);

		void showData();
		void showGraphicData();
		
	private:

};


#endif