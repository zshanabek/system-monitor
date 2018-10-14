#ifndef GRAPHIC_HPP
# define GRAPHIC_HPP
# include <iostream>
# include <string>
# include "IMonitorDisplay.hpp"

class Graphic : public IMonitorDisplay
{
	public:
		Graphic ();
		~Graphic ();
		Graphic (Graphic const & copy);
		Graphic & operator=(Graphic const & copy);

		virtual void showGraphicData();
	private:

};

#endif