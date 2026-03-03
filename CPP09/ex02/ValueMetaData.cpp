#include "ValueMetaData.hpp"

ValueMetaData::ValueMetaData(const Value& value)
	: value(value)
	, rank_idx(-1) {}

void ValueMetaData::set(size_t index, Status status)
{
	round.push_back(Position(index, status));
}
