#include "../includes/monitor.hpp"
#include "../includes/Hostname.hpp"
#include "../includes/OSInfo.hpp"
#include "../includes/RAM.hpp"
#include "../includes/Datetime.hpp"
#include "../includes/CPU.hpp"
#include "../includes/Network.hpp"
#include "../includes/Module.hpp"
#include <ctime>

unsigned int cat = 0;

void drawcat()
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

void terminal()
{
	int		command;
	bool	exit = false;

	initscr();
	Module m = Module();
	Hostname hname = Hostname();
	OSInfo os = OSInfo();
	RAM ram = RAM();
	Datetime datetime = Datetime();
	CPU cpu = CPU();
	Network net = Network();

	m.pushback(&hname);
	m.pushback(&datetime);
	m.pushback(&os);
	m.pushback(&ram);
	m.pushback(&cpu);
	m.pushback(&net);
	int frametime = 1000 / 200;

	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	nodelay(stdscr, true);
	while (!exit)
	{
		clock_t time = clock();
		command = getch();
		if (27 == command)
			exit = true;
		m.updateData();
		m.showData();
		drawcat();
		refresh();
		while (clock() < time + frametime)
  		 ;

	}
	
	endwin();
}

int main()
{
	std::string choice;
	std::cout << "n for ncurses\n";
	std::cout << "s for SDL\n";
	std::cout << "Enter your choice: ";
	std::getline(std::cin, choice);
	if (choice == "n")
		terminal();
	else
		std::cout << "SDL\n";
	return 0;
}
