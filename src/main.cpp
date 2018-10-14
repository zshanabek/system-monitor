#include <stdio.h>

#include "../includes/Graphic.hpp"

#include <iostream>

#include "../includes/monitor.hpp"
#include "../includes/Hostname.hpp"
#include "../includes/OSInfo.hpp"
#include "../includes/RAM.hpp"
#include "../includes/Datetime.hpp"
#include "../includes/CPU.hpp"
#include "../includes/Module.hpp"
#include "../includes/Cat.hpp"
#include <ctime>

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
	Cat cat = Cat();

	m.pushback(&hname);
	m.pushback(&datetime);
	m.pushback(&os);
	m.pushback(&ram);
	m.pushback(&cpu);
	m.pushback(&net);
	m.pushback(&cat);

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
		graphical();
	return 0;
}
