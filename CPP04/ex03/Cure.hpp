#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{

	public: 
		Cure();
		Cure(const Cure&);
		Cure& operator=(const Cure&);
		virtual ~Cure();

		Cure* clone() const;
		void use (ICharacter& target);
};

#endif /*CURE_HPP*/
