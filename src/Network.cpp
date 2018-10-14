#include "../includes/Network.hpp"

void Network::updateData()
{
	_raw[0] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"IP address\"|cut -d \" \" -f3");
    _raw[1] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"Subnet\"|cut -d \" \" -f3");
    _raw[2] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"Router\"|cut -d \" \" -f2");
    _raw[3] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"Ethernet\"|cut -d \" \" -f3");
	_raw[4] = getCMDOutput("top -l 1 | grep -E \"^Net\"|cut -d \" \" -f3");
	_raw[5] = getCMDOutput("top -l 1 | grep -E \"^Net\"|cut -d \" \" -f5");
}

Network::Network()
{
	updateData();
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
	rectangle(23, 0, 34, 50);
	attroff(COLOR_PAIR(1));
	mvprintw(24, 25, "Network");
	mvprintw(25, 2, "IP address: ");
	mvprintw(25, 13, _raw[0].c_str());
	mvprintw(26, 2, "Subnet: ");
	mvprintw(26, 13, _raw[1].c_str());
	mvprintw(27, 2, "Router: ");
	mvprintw(27, 13, _raw[2].c_str());
	mvprintw(28, 2, "Ethernet: ");
	mvprintw(28, 13, _raw[3].c_str());	
	mvprintw(29, 2, "N1: ");
	mvprintw(29, 13, _raw[4].c_str());
	mvprintw(30, 2, "N2: ");
	mvprintw(30, 13, _raw[5].c_str());	
}