#include "Dog.hpp"

Dog::Dog()
	: type("Dog") 
	, b(new Brain())
{ 
	std::cout << "<Dog> constructed" << std::endl; 
};

Dog::~Dog()
{ 
	delete b;
	std::cout << "<Dog> destructed" << std::endl; 
}

std::string Dog::getType() const { return type; }
void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }

Dog::Dog(const Dog& other)
{
	type = other.type;
	b = new Brain(*other.b);
	std::cout << "<Dog> copied" << std::endl;
};

Dog* Dog::clone() const
{
	std::cout << "<Dog> clone" << std::endl; 
	return new Dog(*this);
};
