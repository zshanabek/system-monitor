#ifndef RAM_HPP
# define RAM_HPP
# include <iostream>
# include <string>
# include "IMonitorModule.hpp"
# include "Module.hpp"
# include "monitor.hpp"

class RAM : public Module
{
	public:
		RAM ();
		~RAM ();
		RAM (RAM const & copy);
		RAM & operator=(RAM const & copy);

		void updateData();
		void showData();

		long long getUsedMemory();
		long long getUnusedMemory();
	
	private:
		long long _used;
		long long _unused;
		unsigned long long _total;
};

#endif