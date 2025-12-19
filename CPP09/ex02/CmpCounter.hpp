#ifndef CMP_COUNTER_HPP
#define CMP_COUNTER_HPP

#include <cstddef>

struct CmpCounter
{
	static size_t comparisons;

	template <typename T>
	static bool less(T a, T b);
};

#endif //CMP_COUNTER_HPP
