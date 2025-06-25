#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();

		virtual std::string getType() const;
		virtual void makeSound() const;

	protected:
		std::string type;

};
#endif /*DOG_HPP*/
