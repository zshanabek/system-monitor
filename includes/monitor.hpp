#ifndef MONITOR_HPP
# define MONITOR_HPP
# include <iostream>
# include <string>
# include <unistd.h>
# include <limits.h>
# include <sys/utsname.h>
# include <ctime>
# include <sstream> 
# include <ncurses.h>
# include <sys/types.h>
# include <sys/sysctl.h>

// cpu load
# include <mach/mach_init.h>
# include <mach/mach_error.h>
# include <mach/mach_host.h>
# include <mach/vm_map.h>

#define HOST_NAME_MAX 42
#define LOGIN_NAME_MAX 42

#endif