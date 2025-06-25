#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("WrongAnimal") { std::cout << "<WrongAnimal> constructed" << std::endl; }

WrongAnimal::~WrongAnimal() { std::cout << "<WrongAnimal> destructed" << std::endl; }

std::string WrongAnimal::getType() const { return type; }
void WrongAnimal::makeSound() const { std::cout << "(What is the sound of an abstract category?)" << std::endl; }

