#ifndef PMERGME_HPP
#define PMERGME_HPP

#include "Match.hpp"

#include <vector>
#include <deque>
#include <sstream>

//@TODO: tornar em estática
class PMergeMe
{
	public:
		PMergeMe();
		PMergeMe(int argc, char **argv);
		PMergeMe(const PMergeMe& other);
		PMergeMe& operator=(const PMergeMe& other);
		~PMergeMe();

		void merge_insert_sort();
		void print() const;
		void print_matches() const;
		void print_ranking() const;

	private:
		std::vector<Match>   m_tourney;
		std::vector<Player*> m_ranking;

		// utils
		void rearrange_player_position(Player* p, size_t bracket);
		bool is_number(const std::string& s) const;
		void error(const char *str);
};

#endif // PMERGME_HPP
