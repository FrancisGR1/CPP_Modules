#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string m_type;
	public:
		AMateria();
		AMateria(const AMateria&);
		AMateria(const std::string&);
		AMateria& operator=(const AMateria&);
		virtual ~AMateria();

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif /*AMATERIA_HPP*/
