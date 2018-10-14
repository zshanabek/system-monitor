#include "../includes/monitor.hpp"
#include "../includes/Hostname.hpp"
#include "../includes/OSInfo.hpp"
#include "../includes/RAM.hpp"
#include "../includes/Datetime.hpp"
#include "../includes/CPU.hpp"
#include "../includes/Module.hpp"

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

	m.pushback(hname);
	m.pushback(os);
	m.pushback(ram);
	m.pushback(datetime);
	m.pushback(cpu);

	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);

	while (!exit)
	{
		m.updateData();
		m.showData();
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
