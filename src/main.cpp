#include "../includes/monitor.hpp"
#include "Module1.hpp"

int main()
{
	Module1 m1 = Module1();
	std::cout << m1.getHostname() << std::endl;
	std::cout << m1.getUsername() << std::endl;
	std::cout << m1.getOSName() << std::endl;
	std::cout << m1.getDatetime() << std::endl;
	return 0;
}

