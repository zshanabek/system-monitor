#include <unistd.h>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <iostream>

int read_mem_usage_percent()
{
    vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;

    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    int usage;
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                        (host_info64_t)&vm_stats, &count))
    {
        long long free_memory = static_cast<int64_t>(vm_stats.free_count) *
                                static_cast<int64_t>(page_size);

		std::cout << free_memory << std::endl;

        long long used_memory = (static_cast<int64_t>(vm_stats.active_count) +
                                 static_cast<int64_t>(vm_stats.inactive_count) +
                                 static_cast<int64_t>(vm_stats.wire_count)) *
                                static_cast<int64_t>(page_size);
		std::cout << used_memory << std::endl;
        double total = static_cast<double>(free_memory + used_memory);
        usage = static_cast<int>(used_memory / total * 100);
    }
    return usage;

}

void ok()
{

	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
	vm_statistics_data_t vmstat;
	double total = vmstat.wire_count + vmstat.active_count + vmstat.inactive_count + vmstat.free_count;
	double wired = vmstat.wire_count / total;
	double active = vmstat.active_count / total;
	double inactive = vmstat.inactive_count / total;
	double free = vmstat.free_count / total;

	int t = static_cast<int>(total);
	int w = static_cast<int>(wired);
	std::cout << t << std::endl;
	std::cout << w << std::endl;
}

int main()
{

	ok();
	// while(1)
	// {
	// 	std::cout << read_mem_usage_percent() << std::endl;

	// }
}