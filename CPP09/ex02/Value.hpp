#ifndef VALUE_HPP
# define VALUE_HPP

struct Value
{
	Value(char* str_number, unsigned int id);
	Value(unsigned int number, unsigned int id);
	Value(const Value& value);

	unsigned int number;
	const unsigned int unique_id;
};

#endif // VALUE_HPP
