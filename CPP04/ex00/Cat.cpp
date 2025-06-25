#include "Cat.hpp"

Cat::Cat()
	: type("Cat") { std::cout << "<Cat> constructed" << std::endl; }

Cat::~Cat() { std::cout << "<Cat> destructed" << std::endl; }

std::string Cat::getType() const { return type; }
void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }
