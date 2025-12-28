#ifndef PMERGME_HPP
#define PMERGME_HPP

#include "Matches.hpp"
#include "Time.hpp"
#include "utils.hpp"

#include <vector>
#include <iostream>
#include <cassert>
#include <cstdlib>

template <typename C1, typename C2>
class PMergeMe
{
	public:
		PMergeMe();
		PMergeMe(const PMergeMe& other);
		PMergeMe& operator=(const PMergeMe& other);
		~PMergeMe();

		void sort(int argc, char **argv);
		size_t size() const;
		double time() const;

		void print_matches() const;
		void print_ranking() const;

	private:
		C1 m_tourney;
		C2 m_ranking;
		size_t m_size;
		double m_time;

		// utils
		size_t jacobsthal(size_t n);
		std::vector<size_t> build_jacobsthal_order(size_t n);
		void error(const char *str);
};

template <typename C1, typename C2>
PMergeMe<C1, C2>::PMergeMe()
	: m_size(0)
	, m_time(0) {}



template <typename C1, typename C2>
std::vector<size_t> PMergeMe<C1, C2>::build_jacobsthal_order(size_t n)
{
    std::vector<size_t> order;
    size_t prev = 0;
    size_t k = 1;

    while (true)
    {
        size_t J = jacobsthal(k);
        if (J > n)
            J = n;

        for (size_t i = J; i > prev; --i)
            order.push_back(i - 1);

        if (J == n)
            break;

        prev = J;
        ++k;
    }
    return order;
}


template <typename C1, typename C2>
PMergeMe<C1, C2>::PMergeMe(const PMergeMe& other)
	: m_tourney(other.m_tourney)
	, m_ranking(other.m_ranking)
	, m_size(other.m_size)
	, m_time(other.m_time) {}

template <typename C1, typename C2>
PMergeMe<C1, C2>& PMergeMe<C1, C2>::operator=(const PMergeMe& other)
{ 
	m_tourney = other.m_tourney;
	m_ranking = other.m_ranking;
	m_size = other.m_size;
	m_time = other.m_time;
	return *this;
}

template <typename C1, typename C2>
PMergeMe<C1, C2>::~PMergeMe()
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

template <typename C1, typename C2>
void PMergeMe<C1, C2>::sort(int argc, char **argv)
{

	Time::start();

	if (argc < 2)
		throw std::runtime_error("./PMergeMe <nums>");

	Matches m;
	for (int i = 1; i < argc; i+= 2)
	{

		int n1;
		Player* p1 = NULL;
		if (utils::is_valid_number(argv[i]))
		{
			n1 = atoi(argv[i]);
			p1 = new Player(n1, i);
			m_size++;
		}
		else
		{
			error(argv[i]);
		}

		if (i + 1 < argc)
		{ 
			if (utils::is_valid_number(argv[i + 1]))
			{
				int n2 = atoi(argv[i + 1]);
				Player* p2 = new Player(n2, i + 1);
				m.match(p1, p2);
				m_size++;
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

	Matches prev = m_tourney.back();
	size_t winners = prev.winners.size();
	while (winners > 1)
	{
		Matches m;
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

	// Create m_ranking with first two numbers
	m_ranking.push_back(prev.losers[0]);
	m_ranking.push_back(prev.winners[0]);

	int bracket = m_tourney.size() - 2; // Last before last bracket
	while (bracket >= 0)
	{
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
			Player* l = m_tourney[bracket].winners[prev_l_idx];

			p->swapped = true;
			p->adversary->swapped = true;

			std::swap(*w, *l);
			std::swap(*w->adversary, *l->adversary);
		}

		std::vector<size_t> order = build_jacobsthal_order(m_tourney[bracket].losers.size());
		for (size_t i = 0; i < order.size(); ++i)
		{
			Player* target = m_tourney[bracket].losers[order[i]];
			int end = target->adversary
				? target->adversary->bracket_idx[bracket] 
				: m_ranking.size();
			int insert_idx = utils::binary_search(m_ranking, target->value, 0, end);
			m_ranking.insert(m_ranking.begin() + insert_idx, target);
		}
		--bracket;
	}

	Time::stop();
	m_time = Time::elapsed();
}

template <typename C1, typename C2>
size_t PMergeMe<C1, C2>::size() const
{
	return m_size;
}

template <typename C1, typename C2>
double PMergeMe<C1, C2>::time() const
{
	return m_time;
}

template <typename C1, typename C2>
size_t PMergeMe<C1, C2>::jacobsthal(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

template <typename C1, typename C2>
void PMergeMe<C1, C2>::print_matches() const
{
	std::cout << "\nTourney:\n";
	for (size_t i = 0; i < m_tourney.size(); ++i)
	{
		std::cout << "Bracket: " << i << " ";
		Matches m = m_tourney.at(i);
		std::cout << m << " ";
		std::cout << "\n";
	}
}

template <typename C1, typename C2>
void PMergeMe<C1, C2>::print_ranking() const
{
	for (size_t i = 0; i < m_ranking.size(); ++i)
	{
		std::cout << m_ranking.at(i)->value;
		std::cout << " ";
	}
	std::cout << "\n";
}

	template <typename C1, typename C2>
void PMergeMe<C1, C2>::error(const char *str)
{
	throw std::runtime_error("Error: Not a valid number: " + std::string(str));
}

#endif // PMERGME_HPP
