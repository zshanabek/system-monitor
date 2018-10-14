#include "../includes/RAM.hpp"

#include <unistd.h>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <iostream>

void RAM::updateData()
{
	vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;

	int mib[2] = { CTL_HW, HW_MEMSIZE };
    u_int namelen = sizeof(mib) / sizeof(mib[0]);
    uint64_t size;
    size_t len = sizeof(size);
    if (sysctl(mib, namelen, &size, &len, NULL, 0) < 0)
    {
        perror("sysctl");
    }
    else
    {
        this->_total = size;
    }
    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    int usage;
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                        (host_info64_t)&vm_stats, &count))
    {
        long long free_memory = static_cast<int64_t>(vm_stats.free_count) *
                                static_cast<int64_t>(page_size);

		this->_unused = free_memory;

        long long used_memory = (static_cast<int64_t>(vm_stats.active_count) +
                                 static_cast<int64_t>(vm_stats.inactive_count) +
                                 static_cast<int64_t>(vm_stats.wire_count)) *
                                static_cast<int64_t>(page_size);
		this->_used = used_memory;
        double total = static_cast<double>(free_memory + used_memory);
        usage = static_cast<int>(used_memory / total * 100);
    }
}

RAM::RAM()
{
	updateData();
}

RAM::~RAM()
{

}

RAM::RAM(RAM const & src)
{
	*this = src;
}

RAM & RAM::operator=(RAM const & copy)
{
	(void)copy;	
	return (*this);
}

long long RAM::getUsedMemory()
{
	return this->_used;
}

long long RAM::getUnusedMemory()
{
	return this->_unused;
}

void RAM::showData()
{
	std::string u = std::to_string(this->getUsedMemory());
	std::string f = std::to_string(this->getUnusedMemory());
	std::string t = std::to_string(this->_total);

	attron(COLOR_PAIR(1));
	rectangle(17, 0, 22, 50);
	attroff(COLOR_PAIR(1));
	mvprintw(18, 25, "RAM");
	mvprintw(19, 2, "Used: ");
	mvprintw(19, 13, u.c_str());
	mvprintw(20, 2, "Unused: ");
	mvprintw(20, 13, f.c_str());
	mvprintw(21, 2, "Total: ");
	mvprintw(21, 13, t.c_str());
}

void RAM::showGraphicData()
{
	
}