#ifndef VALUE_HPP
# define VALUE_HPP

#include <cstddef>

class Value
{
	public:
		static size_t total_comparisons;

		Value(char* str_number, unsigned int id);
		Value(unsigned int number, unsigned int id);
		Value(const Value& value);

		bool operator>(const Value& other) const;
		bool operator==(const Value& other) const;

		long unsigned int number;
		long unsigned int unique_id;

	private:
		Value();
};

#endif // VALUE_HPP
