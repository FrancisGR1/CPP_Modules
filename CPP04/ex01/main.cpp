#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

//https://www.fluentcpp.com/2017/09/08/make-polymorphic-copy-modern-cpp/
int main()
{
	Animal* d = new Dog();
	Animal* c = new Cat();

	size_t size = 4;
	Animal* animals[size];

	for (size_t i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = d->clone();
		else
			animals[i] = c->clone();
	}
	delete d;
	delete c;
	for (size_t i = 0; i < size; i++)
	{
		delete animals[i];
	}
}
