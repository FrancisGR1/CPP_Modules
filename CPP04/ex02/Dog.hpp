#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog& other);
		virtual ~Dog();

		std::string getType() const;
		void makeSound() const;
		Dog* clone() const;

	protected:
		std::string type;

	private:
		Brain* b;
};
#endif /*DOG_HPP*/
