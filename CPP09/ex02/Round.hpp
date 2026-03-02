#ifndef ROUND_HPP
#define ROUND_HPP

#include <iostream>

#include "ValueMetaData.hpp"
#include "Value.hpp"

//@ASSUMPTION: Must store Value struct
template <typename Container>
struct Round
{
	Round();

	void match_and_save(const Value& v1, size_t v1_index, const Value& v2, size_t v2_index, std::vector<ValueMetaData>& values_info);
	void add_and_save(const Value& loser, size_t index, std::vector<ValueMetaData>& values_info);

	Container winners;
	Container losers;
};

template <typename Container>
Round<Container>::Round() {}

// matches two values and saves the result in values_info
template <typename Container>
void Round<Container>::match_and_save(const Value& v1, size_t v1_index, const Value& v2, size_t v2_index, std::vector<ValueMetaData>& values_info)
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
template <typename Container>
void Round<Container>::add_and_save(const Value& loser, size_t index, std::vector<ValueMetaData>& values_info)
{
	losers.push_back(loser);
	values_info[loser.unique_id].set(index, LOSER);
}


#endif // ROUND_HPP
