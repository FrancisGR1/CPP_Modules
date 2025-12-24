#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cassert>

#include "CmpCounter.hpp"
#include "Player.hpp"
#include "Match.hpp"
#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("./PMergeMe <nums>");

	// por pares, inserir ou em m_main ou em m_losers
	Match m;
	for (int i = 1; i < argc; i+= 2)
	{

		int n1;
		Player* p1 = NULL;
		if (is_number(argv[i]))
		{
			n1 = atoi(argv[i]);
			p1 = new Player(n1, i);
		}
		else
		{
			error(argv[i]);
		}

		if (i + 1 < argc)
		{ 
			if (is_number(argv[i + 1]))
			{
				int n2 = atoi(argv[i + 1]);
				Player* p2 = new Player(n2, i + 1);
				m.match(p1, p2);
			}
			else
			{
				error(argv[i + 1]);
			}
		}
		else
		{
			m.match(p1);
		}
	}
	m_tourney.push_back(m);
	merge_insert_sort();
	print_matches();
	print_ranking();
}

PMergeMe::PMergeMe(const PMergeMe& other)
	: m_tourney(other.m_tourney) {}

PMergeMe& PMergeMe::operator=(const PMergeMe& other)
{ 
	m_tourney = other.m_tourney;
	return *this;
}

PMergeMe::~PMergeMe()
{
	for (size_t i = 0; i < m_tourney.size(); ++i)
	{
		for (size_t j = 0; j < m_tourney[i].winners.size(); ++j)
		{
			delete m_tourney[i].winners[j];
		}
		for (size_t j = 0; j < m_tourney[i].losers.size(); ++j)
		{
			delete m_tourney[i].losers[j];
		}
	}
}

// https://www.geeksforgeeks.org/dsa/binary-insertion-sort/
static int binary_search(const std::vector<Player*>& v, int target, int low, int high)
{
	CmpCounter::comparisons++;

	if (high <= low)
		return (target > v[low]->value) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (target == v[mid]->value)
		return mid + 1;
	if (target > v[mid]->value)
		return binary_search(v, target, mid + 1, high);
	return binary_search(v, target, low, mid - 1);
}

//@TODO: implementar template
void PMergeMe::merge_insert_sort()
{
	Match prev = m_tourney.back();
	size_t winners = prev.winners.size();
	while (winners > 1)
	{
		Match m;
		for (size_t i = 0; i < winners; i += 2)
		{
			Player* p1 = new Player(prev.winners[i]->value, i);
			if (i + 1 < winners)
			{ 
				Player* p2 = new Player(prev.winners[i + 1], i + 1);
				m.match(p1, i, p2, i + 1);
			}
			else
			{
				m.match(p1);
			}
		}
		m_tourney.push_back(m);

		prev = m_tourney.back();
		winners = m.winners.size();
	}

	print_matches();
	// Create m_ranking with first two numbers
	m_ranking.push_back(prev.losers[0]);
	m_ranking.push_back(prev.winners[0]);

	int bracket = m_tourney.size() - 2; // Last before last bracket
	while(bracket >= 0)
	{
		std::cout << "brack: " << bracket << "\n";
		//em função do m_ranking, reordenar pares do novo nível
		for (size_t i = 0; i < m_ranking.size(); ++i)
		{
			Player* p = m_ranking.at(i);
			assert((p != NULL));
			if (p->swapped)
				continue;
			size_t prev_w_idx = p->bracket_idx.back();
			size_t prev_l_idx;
			if (p->adversary) 
			{
				prev_l_idx  = p->adversary->bracket_idx.back();
			}
			else
			{
				continue;
			}
			Player* w = m_tourney[bracket].winners[prev_w_idx];
			std::cout << "W: b" << bracket << " p_idx" << prev_w_idx << " " << w->value << "\n";
			Player* l = m_tourney[bracket].winners[prev_l_idx];
			std::cout << "L: b" << bracket << " p_idx" << prev_l_idx << " " << l->value << "\n";
			if (!w || !l)
				std::cout << "NULL\n";
			std::cout << "swap: " << w->value << " - " << l->value << "\n";;
			std::cout << "swap: " << w->adversary->value << " - " << l->adversary->value << "\n";;
			p->swapped = true;
			p->adversary->swapped = true;
			std::swap(*w, *l);
			std::swap(*w->adversary, *l->adversary);
		}
		for (size_t i = 0; i < m_ranking.size(); ++i)
		{
			m_ranking[i]->swapped = false;
		}

		//inserir losers
		//@TODO: por agora: brute force; implementar jacobsthal idx  + bs no futuro
		std::cout << "test\n";
		//@TODO: implementar jacobsthal
		//binary search
		for (size_t i = 0; i < m_tourney[bracket].losers.size(); ++i)
		{
			Player* target = m_tourney[bracket].losers[i];
			int insert = binary_search(m_ranking, target->value, 0, m_ranking.size());
			m_ranking.insert(m_ranking.begin() + insert, target);
		}

		--bracket;
	}
}

void PMergeMe::print() const
{

}

void PMergeMe::print_matches() const
{
	std::cout << "\nTourney:\n";
	for (size_t i = 0; i < m_tourney.size(); ++i)
	{
		std::cout << "Bracket: " << i << " ";
		Match m = m_tourney.at(i);
		std::cout << m << " ";
		std::cout << "\n";
	}
}

void PMergeMe::print_ranking() const
{
	std::cout << "\nRanking:\n[";
	for (size_t i = 0; i < m_ranking.size(); ++i)
	{
		std::cout << m_ranking.at(i)->value;
		if (i + 1 < m_ranking.size())
			std::cout << ", ";
	}
	std::cout << "]\n";
}

//@TODO: mudar bracket para int
void PMergeMe::rearrange_player_position(Player* p, size_t bracket)
{
	assert((bracket > 0));

	size_t w_idx = p->get_prev_bracket_idx(bracket);
	size_t l_idx;
	if (p->adversary)
		l_idx  = p->adversary->get_prev_bracket_idx(bracket);
	else
		return;

	--bracket;

	std::cout << bracket << " swap: " << w_idx << " - " << l_idx << "\n";
	Player* w = m_tourney[bracket].winners[w_idx];
	Player* l = m_tourney[bracket].winners[l_idx];
	std::cout << bracket << " swap: " << w->value << " - " << l->value << "\n";

	std::swap(*w, *l);
	std::swap(*w->adversary, *l->adversary);
}

bool PMergeMe::is_number(const std::string& s) const
{
	std::istringstream iss(s);
	double d;
	return iss >> std::noskipws >> d && iss.eof();
}

void PMergeMe::error(const char *str)
{
	throw std::runtime_error("Error: Not a number: " + std::string(str));

}
