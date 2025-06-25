#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie* h1 = zombieHorde(5, "Frederico");

	for (size_t i = 0; i < 5; i++)
		h1[i].announce();

	delete[] h1;
}

