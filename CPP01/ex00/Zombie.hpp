#include <iostream>

class Zombie {
	public:
		Zombie(std::string);
		void announce(void) ;
		~Zombie(void) ;
	private:
		std::string m_name;
};


Zombie*	newZombie( std::string name);
void	randomChump( std::string name);
