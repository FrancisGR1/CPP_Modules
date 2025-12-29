#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <algorithm>
#include <iostream>

#include "Player.hpp"

namespace utils
{
	bool is_valid_number(const std::string& s);
	void print_argv(int argc, char **argv);
	size_t num_width(int n);
	bool player_less(const Player* a, const Player* b);

	template<typename Container>
	int binary_search(const Container& data, int target, int low, int high)
	{
		if (high <= low)
			return (target > data.at(low)->value) ? (low + 1) : low;

		int mid = (low + high) / 2;

		if (target == data.at(mid)->value)
			return mid + 1;
		if (target > data.at(mid)->value)
			return binary_search(data, target, mid + 1, high);
		return binary_search(data, target, low, mid - 1);
	};


	template<typename Container>
	bool is_sorted(const Container& data)
	{
		Container sorted = data;

		std::sort(sorted.begin(), sorted.end(), player_less);

		for (size_t i = 0; i < sorted.size(); ++i)
		{
			if (sorted[i]->value != data[i]->value)
			{
				std::cerr << i << ": Not equal: " << sorted[i]->value << " != " << data[i]->value << "\n";
				return false;
			}
		}
		return true;
	}
}

#endif //UTILS_HPP
