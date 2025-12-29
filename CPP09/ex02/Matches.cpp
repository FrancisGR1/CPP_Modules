#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <sstream>

#include "utils.hpp"
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

std::ostream& operator<<(std::ostream& os, const Matches& m)
{
    size_t maxWidth = 0;

    std::stringstream oss;
    for (size_t i = 0; i < m.winners.size(); ++i)
        maxWidth = std::max(maxWidth, utils::num_width(m.winners[i]->value));
    for (size_t i = 0; i < m.losers.size(); ++i)
        maxWidth = std::max(maxWidth, utils::num_width(m.losers[i]->value));

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

void Matches::match(Player* p1, Player* p2)
{
	p1->set_adversary(p2);
	p2->set_adversary(p1);

	if (p1->value < p2->value)
	{
		p1->register_idx(losers.size());
		p2->register_idx(winners.size());
		winners.push_back(p2);
		losers.push_back(p1);
	}
	else
	{
		p1->register_idx(winners.size());
		p2->register_idx(losers.size());
		winners.push_back(p1);
		losers.push_back(p2);
	}
}

void Matches::match(Player *p1)
{
	p1->set_adversary(NULL);
	p1->register_idx(losers.size());
	losers.push_back(p1);
}
