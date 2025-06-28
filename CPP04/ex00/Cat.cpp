#include "Cat.hpp"

Cat::Cat()
	: type("Cat") { std::cout << "<Cat> constructed" << std::endl; }

Cat::Cat(const Cat& other)
	: Animal(other)
	, type(other.type)
{
	std::cout << "<Cat> copy constructed" << std::endl;
};

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "<Cat> Assignment operator called" << std::endl;
	type = other.type;
	return *this;
};

Cat::~Cat() { std::cout << "<Cat> destroyed" << std::endl; }

std::string Cat::getType() const { return type; }

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }
