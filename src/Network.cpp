#include "../includes/Network.hpp"

Network::Network()
{
	_raw[0] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"IP address\"|cut -d \" \" -f3");
    _raw[1] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"Subnet\"|cut -d \" \" -f3");
    _raw[2] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"Router\"|cut -d \" \" -f2");
    _raw[3] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"Ethernet\"|cut -d \" \" -f3");
}

Network::~Network()
{

}

Network::Network(Network const & src)
{
	*this = src;
}

Network & Network::operator=(Network const & copy)
{
	(void)copy;
	return (*this);
}

void Network::showGraphicData()
{
	
}

void Network::showData()
{
	attron(COLOR_PAIR(1));
	rectangle(23, 0, 30, 50);
	attroff(COLOR_PAIR(1));
	mvprintw(24, 25, "Network");
	mvprintw(25, 2, "IP address: ");
	mvprintw(25, 13, _raw[0].c_str());
	mvprintw(26, 2, "Subnet: ");
	mvprintw(26, 13, _raw[1].c_str());
	mvprintw(27, 2, "Router: ");
	mvprintw(27, 13, _raw[2].c_str());
	mvprintw(28, 2, "Ethernet: ");
	mvprintw(29, 13, _raw[2].c_str());	
}