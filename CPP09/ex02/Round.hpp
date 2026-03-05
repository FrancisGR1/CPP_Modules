#ifndef ROUND_HPP
#define ROUND_HPP

#include "ValueMetaData.hpp"
#include "Value.hpp"

//@ASSUMPTION: Must store Value struct
template <typename C1, typename C2>
struct Round
{
	Round();
	Round(const Round<C1, C2>& other);
	Round<C1,C2>& operator=(const Round<C1, C2>& other);
	~Round();

	void match_and_save(const Value& v1, size_t v1_index, const Value& v2, size_t v2_index, C2& values_info);
	void add_and_save(const Value& loser, size_t index, C2& values_info);

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
void Round<C1, C2>::match_and_save(const Value& v1, size_t v1_index, const Value& v2, size_t v2_index, C2& values_info)
{

	if (v1.number > v2.number)
	{
		winners.push_back(v1);
		losers.push_back(v2);
		values_info[v1.unique_id].set(v1_index, WINNER);
		values_info[v2.unique_id].set(v2_index, LOSER);
	}
	else
	{
		winners.push_back(v2);
		losers.push_back(v1);
		values_info[v1.unique_id].set(v1_index, LOSER);
		values_info[v2.unique_id].set(v2_index, WINNER);
	}
}

// no match = pushed to losers
template <typename C1, typename C2>
void Round<C1, C2>::add_and_save(const Value& loser, size_t index, C2& values_info)
{
	losers.push_back(loser);
	values_info[loser.unique_id].set(index, LOSER);
}

#endif // ROUND_HPP
