#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <iostream>

class IMateriaSource
{
	public:
		IMateriaSource() {};
		IMateriaSource(const IMateriaSource&) {};
		virtual ~IMateriaSource() {};

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif /*IMATERIASOURCE_HPP*/
