#include "WrongCat.hpp"

WrongCat::WrongCat()
	: type("WrongCat") { std::cout << "<WrongCat> constructed" << std::endl; }

WrongCat::~WrongCat() { std::cout << "<WrongCat> destructed" << std::endl; }

std::string WrongCat::getType() const { return type; }
void WrongCat::makeSound() const { std::cout << "Meow!" << std::endl; }
