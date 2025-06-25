#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

class Karen;

struct Levels
{
	std::string s[4];
	void (Karen::*f[4])();
};

class Karen 
{
	public:
		void complain( std::string );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif /*KAREN_HPP*/
