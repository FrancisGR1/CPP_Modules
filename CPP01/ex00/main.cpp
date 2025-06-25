#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie* z1 = newZombie("Frederico");
	z1->announce();
	randomChump("Joana");
	delete z1;
}

