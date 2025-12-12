#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base 
{
	public:
		virtual ~Base();

		static Base* generate();
		static void identify(Base* p);
		static void identify(Base& p);

	private:
};

#endif /*BASE_HPP*/
