#include "Animal.hpp"

Animal::Animal()
	: type("Animal") { std::cout << "<Animal> constructed" << std::endl; }

Animal::Animal(const Animal& other) 
	: type(other.type)
{
	std::cout << "<Animal> copy constructed" << std::endl;
};

Animal& Animal::operator=(const Animal &other) 
{ 
	std::cout << "<Animal> Assignment operator called" << std::endl;
	type = other.type;
	return *this; 
};

Animal::~Animal() { std::cout << "<Animal> destroyed" << std::endl; }

std::string Animal::getType() const { return type; }

void Animal::makeSound() const { std::cout << "(What is the sound of an abstract category?)" << std::endl; }
