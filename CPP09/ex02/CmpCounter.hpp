#ifndef CMP_COUNTER_HPP
#define CMP_COUNTER_HPP

#include <cstddef>

struct CmpCounter
{
	static size_t comparisons;

	template <typename T>
	static bool less(const T& a, const T& b)
	{
		++comparisons;
		return a < b;
	};

	template <typename T>
	static bool greater(const T& a, const T& b)
	{
		++comparisons;
		return a > b;
	};

	template <typename T>
	static bool eq(const T& a, const T& b)
	{
		++comparisons;
		return a == b;
	};

	template <typename T>
	static bool geq(const T& a, const T& b)
	{
		++comparisons;
		return a >= b;
	};

	template <typename T>
	static bool leq(const T& a, const T& b)
	{
		++comparisons;
		return a <= b;
	};
};

#endif //CMP_COUNTER_HPP
