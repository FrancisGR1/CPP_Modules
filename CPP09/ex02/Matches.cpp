#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <sstream>

#include "Player.hpp"
#include "Matches.hpp"

Matches::Matches() {}

Matches::Matches(const Matches& bracket)
	: winners(bracket.winners)
	, losers(bracket.losers) {}

Matches& Matches::operator=(const Matches& bracket)
{
	winners = bracket.winners;
	losers = bracket.losers;
	return *this;
}

Matches::~Matches() {}

static size_t numWidth(int n)
{
    std::ostringstream oss;
    oss << n;
    return oss.str().length();
}

std::ostream& operator<<(std::ostream& os, const Matches& m)
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

void Matches::match(Player* p1, size_t p1_idx, Player* p2, size_t p2_idx)
{
	p1->set_adversary(p2);
	p2->set_adversary(p1);

	p1->register_idx(p1_idx);
	p2->register_idx(p2_idx);

	if (p1->value < p2->value)
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

void Matches::match(Player *p1, size_t p1_idx)
{
	p1->set_adversary(NULL);
	p1->register_idx(p1_idx);
	losers.push_back(p1);
}

void Matches::match(Player *p1)
{
	p1->set_adversary(NULL);
	losers.push_back(p1);
}

void Matches::match(Player* p1, Player* p2)
{
	p1->set_adversary(p2);
	p2->set_adversary(p1);

	if (p1->value < p2->value)
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
