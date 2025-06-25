#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

class Karen 
{
	public:
		enum LEVELS {DEBUG, INFO, WARNING, ERROR, LEVELS};
		void complain( std::string );
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif /*KAREN_HPP*/
