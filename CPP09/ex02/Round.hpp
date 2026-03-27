#ifndef ROUND_HPP
#define ROUND_HPP

#include "Value.hpp"

//@ASSUMPTION: Must store Value struct
template <typename C1, typename C2>
struct Round
{
	Round();
	Round(const Round<C1, C2>& other);
	Round<C1,C2>& operator=(const Round<C1, C2>& other);
	~Round();

	void match_and_save(const Value& v1, const Value& v2);
	void add_and_save(const Value& loser);

	C1 winners;
	C1 losers;
};

template <typename C1, typename C2>
Round<C1, C2>::Round() {}

template <typename C1, typename C2>
Round<C1, C2>::Round(const Round<C1, C2>& other) 
	: winners(other.winners)
	, losers(other.losers) {}

template <typename C1, typename C2>
Round<C1,C2>& Round<C1, C2>::operator=(const Round<C1, C2>& other) 
{
	if (this != &other)
	{
		winners = other.winners;
		losers = other.losers;
	}

	return *this;
}

template <typename C1, typename C2>
Round<C1, C2>::~Round(){}

// matches two values and saves the result in values_info
template <typename C1, typename C2>
void Round<C1, C2>::match_and_save(const Value& v1, const Value& v2)
{

	if (v1 > v2)
	{
		winners.push_back(v1);
		losers.push_back(v2);
	}
	else
	{
		winners.push_back(v2);
		losers.push_back(v1);
	}
}

// no match = pushed to losers
template <typename C1, typename C2>
void Round<C1, C2>::add_and_save(const Value& loser)
{
	losers.push_back(loser);
}

#endif // ROUND_HPP
