#include "WrongCat.hpp"

WrongCat::WrongCat()
	: type("WrongCat") { std::cout << "<WrongCat> constructed" << std::endl; }

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
	, type(other.type) 
{ 
	std::cout << "<WrongCat> copy constructed" << std::endl; 
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "<WrongCat> Assignment operator called" << std::endl;
	type = other.type;
	return (*this);
}

WrongCat::~WrongCat() { std::cout << "<WrongCat> destructed" << std::endl; }

std::string WrongCat::getType() const { return type; }

void WrongCat::makeSound() const { std::cout << "Wrong Meow!" << std::endl; }
