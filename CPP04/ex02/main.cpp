#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

//https://www.fluentcpp.com/2017/09/08/make-polymorphic-copy-modern-cpp/
int main()
{
	Animal* d = new Dog();
	Animal* c = new Cat();

	size_t size = 4;
	Animal* animals[size];

	std::cout << "deep copies: " << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "construct loop: " << i << std::endl;
		if (i < size / 2)
			animals[i] = d->clone();
		else
			animals[i] = c->clone();
	}
	std::cout << "type: " + d->getType() << std::endl;
	d->makeSound();
	animals[1]->makeSound();
	std::cout << "type: " + c->getType() << std::endl;
	c->makeSound();
	animals[3]->makeSound();
	delete d;//should not create a leak
	delete c;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "delete loop: " << i << std::endl;
		delete animals[i];
	}
}
