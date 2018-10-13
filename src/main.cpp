#include "../includes/monitor.hpp"
#include "Module1.hpp"
# include <ncurses.h>

void terminal()
{
	initscr();
	int		command;
	bool	exit = false;

	Module1 m1 = Module1();
	mvprintw(0, 1, m1.getHostname().c_str());
	mvprintw(1, 1, m1.getUsername().c_str());
	mvprintw(2, 1, m1.getOSName().c_str());
	mvprintw(3, 1, m1.getDatetime().c_str());
	while (!exit) {
		command = getch();
		if (27 == command)
			exit = true;
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

