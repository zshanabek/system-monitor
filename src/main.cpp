#include "../includes/monitor.hpp"
#include "Hostname.hpp"
#include "OSInfo.hpp"
#include "RAM.hpp"
#include "Datetime.hpp"
#include "CPU.hpp"

void rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void terminal()
{
	int		command;
	bool	exit = false;

	initscr();
	Hostname hname = Hostname();
	OSInfo os = OSInfo();
	RAM ram = RAM();
	Datetime datetime = Datetime();
	CPU cpu = CPU();

	refresh();

	rectangle(0, 0, 3, 30);

	mvprintw(1, 2, "Hostname: ");
	mvprintw(1, 12, hname.getHostname().c_str());
	mvprintw(2, 2, "Username: ");
	mvprintw(2, 12, hname.getUsername().c_str());

	rectangle(4, 0, 6, 30);
	mvprintw(5, 2, "OS name: ");
	mvprintw(5, 11, os.getOSName().c_str());

	rectangle(7, 0, 9, 30);
	mvprintw(8, 2, "Date time: ");
	mvprintw(8, 13, datetime.getDatetime().c_str());

	rectangle(10, 0, 16, 30);
	std::string l = std::to_string(cpu.getCoresNumber());
	mvprintw(11, 2, "Number of cores: ");	
	mvprintw(11, 19, l.c_str());
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

