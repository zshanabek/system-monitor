#ifndef OSINFO_HPP
# define OSINFO_HPP
# include <iostream>
# include <string>

class OSInfo
{
	public:
		OSInfo ();
		~OSInfo ();
		OSInfo (OSInfo const & copy);
		OSInfo & operator=(OSInfo const & copy);
		std::string getOSName();

	private:
		std::string _osname;

};

#endif