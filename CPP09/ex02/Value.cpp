#include <sstream>

#include "Value.hpp"

size_t Value::total_comparisons = 0;

Value::Value(char* str_number, unsigned int uid)
	: number(0)
	, unique_id(uid)
{
	// @ASSUMPTION: str is a valid unsigned integer
	std::stringstream ss;
	ss << str_number;
	ss >> number;
}

Value::Value(unsigned int number, unsigned int uid)
	: number(number)
	, unique_id(uid) {}

Value::Value(const Value& other)
	: number(other.number)
	, unique_id(other.unique_id) {}

bool Value::operator>(const Value& other) const
{ 
	total_comparisons++;
	return number > other.number;
}
