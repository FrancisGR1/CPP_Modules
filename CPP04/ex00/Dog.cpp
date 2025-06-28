#include "Dog.hpp"

Dog::Dog()
	: type("Dog") { std::cout << "<Dog> constructed" << std::endl; }

Dog::Dog(const Dog& other)
	: Animal(other)
	, type(other.type)
{
	std::cout << "<Dog> copy constructed" << std::endl;
};

Dog& Dog::operator=(const Dog& other) 
{
	std::cout << "<Dog> Assignment operator called" << std::endl;
	type = other.type;
	return (*this);
};

Dog::~Dog() { std::cout << "<Dog> destroyed" << std::endl; }

std::string Dog::getType() const { return type; }
void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }
