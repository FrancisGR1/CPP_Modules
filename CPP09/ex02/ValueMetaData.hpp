#ifndef VALUEMETADATA_HPP
# define VALUEMETADATA_HPP

#include <cstddef>

#include "Value.hpp"

enum Status
{
	LOSER,
	WINNER
};

struct Position
{
	Position(size_t i, Status st)
		: idx(i)
		, status(st) {}

	size_t idx;
	Status status;
};

struct ValueMetaData
{
	ValueMetaData(const Value& value);

	// @ASSUMPTION: position of each rank is only set once, so a push_back = new rank
	void set(size_t index, Status status);

	Value value;
	long rank_idx;
};

#endif // VALUEMETADATA_HPP
