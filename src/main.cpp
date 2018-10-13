#include <unistd.h>
#include <limits.h>
#include "../includes/monitor.hpp"

int main()
{
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];
	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);
	
	std::cout << hostname << std::endl;
	std::cout << username << std::endl;
	return 0;
}
