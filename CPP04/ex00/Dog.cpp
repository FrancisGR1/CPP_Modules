#include "Dog.hpp"

Dog::Dog()
	: type("Dog") { std::cout << "<Dog> constructed" << std::endl; }

Dog::~Dog() { std::cout << "<Dog> destructed" << std::endl; }

std::string Dog::getType() const { return type; }
void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }
