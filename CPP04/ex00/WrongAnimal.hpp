#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();

		std::string getType() const;
		void makeSound() const;

	protected:
		std::string type;

};
#endif /*WRONGANIMAL_HPP*/
