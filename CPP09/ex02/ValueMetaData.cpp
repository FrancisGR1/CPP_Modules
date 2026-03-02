#include "ValueMetaData.hpp"

ValueMetaData::ValueMetaData(const Value& value)
	: m_value(value) {};

void ValueMetaData::set(size_t index, Status status)
{
	round.push_back(Position(index, status));
}
