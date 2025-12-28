#ifndef MATCHES_HPP
#define MATCHES_HPP

#include "Player.hpp"
#include <vector>
#include <ostream>


struct Matches
{
	public:
		std::vector<Player*> winners;
		std::vector<Player*> losers;

		Matches();
		Matches(const Matches& bracket);
		Matches& operator=(const Matches& bracket);
		~Matches();

		void match(Player* p1, size_t p1_idx, Player* p2, size_t p2_idx);
		void match(Player* p1, size_t p1_idx);
		void match(Player* p1, Player* p2);
		void match(Player *p1);
};

std::ostream& operator<<(std::ostream& os, const Matches& m);

#endif //MATCHES_HPP
