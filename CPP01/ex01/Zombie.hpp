#include <iostream>

class Zombie {
	public:
		Zombie(void);
		Zombie(std::string);
		void announce(void) ;
		~Zombie(void) ;
	private:
		std::string m_name;
};


Zombie*	zombieHorde(size_t n, std::string name);
