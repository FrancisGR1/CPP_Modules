#include "CmpCounter.hpp"

size_t CmpCounter::comparisons = 0;

template <typename T>
bool CmpCounter::less(T a, T b)
{
	++comparisons;
	return a < b;
}
