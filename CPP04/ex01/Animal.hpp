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

		virtual std::string getType() const;
		virtual void makeSound() const;
		virtual Animal* clone() const;
	protected:
		std::string type;

};
#endif /*ANIMAL_HPP*/
