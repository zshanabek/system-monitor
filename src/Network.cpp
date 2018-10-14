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
	
	return (*this);
}

void Network::showGraphicData()
{
	
}