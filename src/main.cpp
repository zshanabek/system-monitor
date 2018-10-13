#include "../includes/monitor.hpp"

std::string getOsName()
{
    #ifdef _WIN64
    return "Windows 64-bit";
    #elif __unix || __unix__
    return "Unix";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #else
    return "Other";
    #endif
}      

void module1()
{
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];

	gethostname(hostname, HOST_NAME_MAX);
	getlogin_r(username, LOGIN_NAME_MAX);

	std::cout << hostname << std::endl;
	std::cout << username << std::endl;

	std::cout << getOsName() << std::endl;

	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	std::cout << (now->tm_hour) << ':'
		<< (now->tm_min) << ' '
		<< (now->tm_year + 1900) << '-' 
		<< (now->tm_mon + 1) << '-'
		<<  now->tm_mday
		<< "\n";
}


int main()
{
	module1();
	return 0;
}

