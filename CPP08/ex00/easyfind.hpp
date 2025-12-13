#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);

	if (it == container.end())
		throw std::out_of_range("Value not found");
	return it;
}
