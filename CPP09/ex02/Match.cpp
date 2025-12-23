#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <sstream>

#include "CmpCounter.hpp"
#include "Player.hpp"
#include "Match.hpp"

Match::Match() {}

Match::Match(int n1)
{
	(void) n1;
	//losers.push_back(n1);
}

Match::Match(int n1, int n2)
{
	if (CmpCounter::less(n1, n2))
	{
		//winners.push_back(n2);
		//losers.push_back(n1);
	}
	else
	{
		//winners.push_back(n1);
		//losers.push_back(n2);
	}
}

Match::Match(const Match& g1)
	: winners(g1.winners)
	, losers(g1.losers) {}

Match::Match(const Match& g1, const Match& g2)
{
	//@TODO: Não é preciso isto
	if (CmpCounter::less(g1, g2))
		merge(g1, g2);
	else
		merge(g2, g1);
}

Match& Match::operator=(const Match& g1)
{
	winners = g1.winners;
	losers = g1.losers;
	return *this;
}

bool Match::operator<(const Match& g) const
{
	return largest < g.largest;
}

//@TODO: colocar em namespace utils.hpp
static size_t numWidth(int n)
{
    std::ostringstream oss;
    oss << n;
    return oss.str().length();
}

std::ostream& operator<<(std::ostream& os, const Match& m)
{
    size_t maxWidth = 0;

    std::stringstream oss;
    for (size_t i = 0; i < m.winners.size(); ++i)
        maxWidth = std::max(maxWidth, numWidth(m.winners[i]->value));
    for (size_t i = 0; i < m.losers.size(); ++i)
        maxWidth = std::max(maxWidth, numWidth(m.losers[i]->value));

    os << "\n\tWinners: [";
    for (size_t i = 0; i < m.winners.size(); ++i)
    {
        os << std::setw(maxWidth) << m.winners[i]->value;
        if (i + 1 < m.winners.size())
            os << ", ";
    }
    os << "]\n";

    os << "\tLosers:  [";
    for (size_t i = 0; i < m.losers.size(); ++i)
    {
        os << std::setw(maxWidth) << m.losers[i]->value;
        if (i + 1 < m.losers.size())
            os << ", ";
    }
    os << "]\n";

    return os;
}
Match::~Match() {}

void Match::merge(const Match& larger, const Match& smaller)
{
	nums.clear();
	nums.reserve(larger.nums.size() + smaller.nums.size());

	nums.insert(nums.end(), larger.nums.begin(), larger.nums.end());
	nums.insert(nums.end(), smaller.nums.begin(), smaller.nums.end());

	largest  = CmpCounter::less(larger.largest, smaller.largest) ? smaller.largest : larger.largest;
	smallest = CmpCounter::less(larger.largest, smaller.largest) ? larger.largest : smaller.largest;
}




void Match::match(Player* p1, size_t p1_idx, Player* p2, size_t p2_idx)
{
	p1->set_adversary(p2);
	p2->set_adversary(p1);

	p1->register_idx(p1_idx);
	p2->register_idx(p2_idx);

	if (CmpCounter::less(p1->value, p2->value))
	{
		winners.push_back(p2);
		losers.push_back(p1);
	}
	else
	{
		winners.push_back(p1);
		losers.push_back(p2);
	}
}

void Match::match(Player *p1, size_t p1_idx)
{
	p1->set_adversary(NULL);
	p1->register_idx(p1_idx);
	losers.push_back(p1);
}

void Match::match(Player *p1)
{
	p1->set_adversary(NULL);
	losers.push_back(p1);
}

void Match::match(Player* p1, Player* p2)
{
	p1->set_adversary(p2);
	p2->set_adversary(p1);

	if (CmpCounter::less(p1->value, p2->value))
	{
		winners.push_back(p2);
		losers.push_back(p1);
	}
	else
	{
		winners.push_back(p1);
		losers.push_back(p2);
	}
}
