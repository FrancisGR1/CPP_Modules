#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

namespace utils
{
	bool is_valid_number(const std::string& s);
	void print_argv(int argc, char **argv);
	size_t num_width(int n);

	template<typename T>
	int binary_search(const T& data, int target, int low, int high)
	{

		if (high <= low)
			return (target > data[low]->value) ? (low + 1) : low;

		int mid = (low + high) / 2;

		if (target == data[mid]->value)
			return mid + 1;
		if (target > data[mid]->value)
			return binary_search(data, target, mid + 1, high);
		return binary_search(data, target, low, mid - 1);
	};

}

#endif //UTILS_HPP
