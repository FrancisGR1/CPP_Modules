#include "Cat.hpp"

Cat::Cat()
	: type("Cat") 
	, b(new Brain())
{ 
	std::cout << "<Cat> constructed" << std::endl; 
}

Cat::Cat(const Cat& other)
	: Animal(other)
	, type(other.type)
	, b(new Brain(*other.b))
{
	std::cout << "<Cat> copied" << std::endl;
};

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "<Cat> Assignment operator called" << std::endl;
	type = other.type;
	b = new Brain(*other.b);
	return *this;
};

Cat::~Cat() 
{ 
	delete b;
	std::cout << "<Cat> destructed" << std::endl; 
}

std::string Cat::getType() const { return type; }
void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

Cat* Cat::clone() const
{
	std::cout << "<Cat> clone" << std::endl; 
	return new Cat(*this);
};
