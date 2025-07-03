#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "========== BASE ==========" << std::endl;
	const Animal* meta = new Animal();
	const WrongAnimal* wmeta = new WrongCat();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << wmeta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	wmeta->makeSound();
	delete meta;
	delete wmeta;
	delete i;
	delete j;

	return 0;
}
