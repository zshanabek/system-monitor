#include "../includes/Network.hpp"

unsigned int counter2 = 0;

void Network::updateData()
{
	if (counter2 == 0)
	{
		_raw[0] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"IP address\"|cut -d \" \" -f3");
		_raw[1] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"Subnet\"|cut -d \" \" -f3");
		_raw[2] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"Router\"|cut -d \" \" -f2");
		_raw[3] = getCMDOutput("networksetup -getinfo Ethernet|grep -m 1 \"Ethernet\"|cut -d \" \" -f3");
		_raw[4] = getCMDOutput("top -l 1 | grep -E \"^Net\"|cut -d \" \" -f3");
		_raw[5] = getCMDOutput("top -l 1 | grep -E \"^Net\"|cut -d \" \" -f5");

		_raw[0].resize(_raw[0].length() - 1);
		_raw[1].resize(_raw[1].length() - 1);
		_raw[2].resize(_raw[2].length() - 1);
		_raw[3].resize(_raw[3].length() - 1);
		_raw[4].resize(_raw[4].length() - 1);
		_raw[5].resize(_raw[5].length() - 1);
		counter2 = 1;

	}
	else if (counter2 == 60)
		counter2 = 0;
	else
		counter2++;

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
	if (show_network)
	{
		ImGui::Begin("Network Info!", &show_os);
		ImGui::TextWrapped("IP address: %s\nSubnet: %s\n%sRouter: %s\nEthernet: %s\nIn: %s\nOut: %s\n", _raw[0].c_str(), _raw[1].c_str(), _raw[2].c_str(), _raw[3].c_str(), _raw[4].c_str(), _raw[5].c_str());
		ImGui::End();
	}
}

void Network::showData()
{
	attron(COLOR_PAIR(1));
	rectangle(23, 0, 31, 50);
	attroff(COLOR_PAIR(1));
	mvprintw(24, 23, "Network");
	mvprintw(25, 2, "IP address: ");
	mvprintw(25, 14, _raw[0].c_str());
	mvprintw(26, 2, "Subnet: ");
	mvprintw(26, 14, _raw[1].c_str());
	mvprintw(27, 2, "Router: ");
	mvprintw(27, 14, _raw[2].c_str());
	mvprintw(28, 2, "Ethernet: ");
	mvprintw(28, 14, _raw[3].c_str());	
	mvprintw(29, 2, "In: ");
	mvprintw(29, 14, _raw[4].c_str());
	mvprintw(30, 2, "Out: ");
	mvprintw(30, 14, _raw[5].c_str());	
}