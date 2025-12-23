#ifndef MATCH_HPP
#define MATCH_HPP

#include "Player.hpp"
#include <vector>
#include <ostream>


//@TODO: mudar para Matches
class Match
{
	public:
		//@TODO mudar para privado
		std::vector<Player*> winners;
		std::vector<Player*> losers;
		//@TODO: remover
		std::vector<int> nums;
		int largest;
		int smallest;

		Match();
		Match(int n1);
		Match(int n1, int n2);
		Match(const Match& g1);
		Match(const Match& g1, const Match& g2);
		Match& operator=(const Match& g1);
		bool operator<(const Match& g) const;
		~Match();

		void merge(const Match& larger, const Match& smaller);

		void match(Player* p1, size_t p1_idx, Player* p2, size_t p2_idx);
		void match(Player* p1, size_t p1_idx);
		void match(Player* p1, Player* p2);
		void match(Player *p1);
		void match(int n1, int n2);
		void match(int n1);

	private:
		size_t m_players;
};
std::ostream& operator<<(std::ostream& os, const Match& m);

#endif //GROUP_HPP
