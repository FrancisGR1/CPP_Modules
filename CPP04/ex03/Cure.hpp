#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{

	public: 
		Cure();
		virtual ~Cure();
		Cure* clone() const;
		void use (ICharacter& target);
};

#endif /*CURE_HPP*/
