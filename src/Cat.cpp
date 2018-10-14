#include "../includes/Cat.hpp"
unsigned int cat = 0;

Cat::Cat()
{

}

Cat::~Cat()
{

}

Cat::Cat(Cat const & src)
{
	*this = src;
}

Cat & Cat::operator=(Cat const & copy)
{
	(void)copy;
	return (*this);
}

void Cat::showData()
{
	cat = (cat == 3) ? 0 : cat + 1; 
	attron(COLOR_PAIR(1));
	rectangle(32, 0, 40, 50);
	attroff(COLOR_PAIR(1));
	std::string array[50];

	int i;
	i = 0;

	int a;
	a = 33;
	if (cat == 0)
	{
		array[0] = "  )\\._.,--....,'``.       ";
		array[1] = " /,   _.. \\   _\\  (`._ ,.";
		array[2] = "`._.-(,_..'--(,_..'`-.;.'  ";
		array[3] = "                           ";

		while(i < 4)
		{
			mvprintw(a + i, 2, array[i].c_str());
			i++;
		}
	}
	else if (cat == 1)
	{
		array[0] = "  |\\      _,,,---,,_      ";
		array[1] = "  /,`.-'`'    -.  ;-;;,_   ";
		array[2] = " |,4-  ) )-,_..;\\ (  `'-' ";
		array[3] = "'---''(_/--'  `-'\\_)      ";
		i = 0;
		while(i < 4)
		{
			mvprintw(a + i, 2, array[i].c_str());
			i++;
		}
	}
	else if (cat == 2)
	{
		array[0] = "  |\\      _,,,,--,,_      ";
		array[1] = "  /,`.-'`'    -,  ;-;,     ";
		array[2] = " |,4-  ) ),,__ ) /;  ;;    ";
		array[3] = "'---''(.'--'  (.'`.) `'    ";
		i = 0;
		while(i < 4)
		{
			mvprintw(a + i, 2, array[i].c_str());
			i++;
		}
	}
	else if (cat == 3)
	{
		array[0] = "  |\\      _,,,,--,,_      ";
		array[1] = "  /,`.-'`'    -,  \\-;,    ";
		array[2] = " |,4-  ) ),,__ ,\\ (  ;;   ";
		array[3] = "'---''(.'--'  `-'`.)`'     ";
		i = 0;
		while(i < 4)
		{
			mvprintw(a + i, 2, array[i].c_str());
			i++;
		}
	}
}

void Cat::showGraphicData()
{
	
}