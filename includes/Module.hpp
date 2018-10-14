#ifndef MODULE_HPP
# define MODULE_HPP
# include <iostream>
# include <string>
# include <vector>
# include "IMonitorModule.hpp"
# include "monitor.hpp"

class Module : public IMonitorModule
{
	public:
		Module ();
		~Module ();
		Module (Module const & copy);
		Module & operator=(Module const & copy);
		void pushback(Module *ok);
		virtual void updateData();
		virtual void showData();
		virtual void showGraphicData();

		std::string getCMDOutput(const char *cmd);
	private:
		std::vector<Module *> modules;
		std::vector<Module *>::iterator it;
};

#endif