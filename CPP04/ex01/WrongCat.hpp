#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat&);
		WrongCat& operator=(const WrongCat&);
		~WrongCat();

		std::string getType() const;
		void makeSound() const;

	protected:
		std::string type;

};
#endif /*WRONGCAT_HPP*/
