#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal&);
		Animal& operator=(const Animal&);
		virtual ~Animal();

		virtual std::string getType() const = 0;
		virtual void makeSound() const = 0;
		virtual Animal* clone() const = 0;
	protected:
		std::string type;

};
#endif /*ANIMAL_HPP*/
