#include "Zombie.hpp"

Zombie*	zombieHorde(size_t N, std::string name)
{
	Zombie* horde = new Zombie[N];
	for (size_t i = 0; i < N; i++)
	{
		horde[i] = Zombie(name);
	}
	return (horde);
}

