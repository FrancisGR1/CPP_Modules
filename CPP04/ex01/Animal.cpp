#include "Animal.hpp"

Animal::Animal()
	: type("Animal") { std::cout << "<Animal> constructed" << std::endl; }

Animal::~Animal() { std::cout << "<Animal> destructed" << std::endl; }

std::string Animal::getType() const { return type; }

void Animal::makeSound() const { std::cout << "(What is the sound of an abstract category?)" << std::endl; }

Animal* Animal::clone() const
{
	return new Animal(*this);
};
