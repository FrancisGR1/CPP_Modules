#include <algorithm>
#include <iostream>

#include "CmpCounter.hpp"
#include "Group.hpp"

Group::Group()
	: largest(0)
	, smallest(0) {}

Group::Group(int n1)
	: largest(n1)
	, smallest(n1) 
{
	nums.push_back(n1);
}

Group::Group(int n1, int n2)
{
	largest = CmpCounter::less(n1, n2) ? n2 : n1;
	smallest = CmpCounter::less(n2, n1) ? n2 : n1;
	if (CmpCounter::less(n1, n2))
	{
		nums.push_back(n1);
		nums.push_back(n2);
	}
	else
	{
		nums.push_back(n2);
		nums.push_back(n1);
	}
}

Group::Group(const Group& g1)
	: nums(g1.nums)
	, largest(g1.largest)
	, smallest(g1.smallest) {}

Group::Group(const Group& g1, const Group& g2)
{
	if (CmpCounter::less(g1, g2))
		merge(g1, g2);
	else
		merge(g2, g1);
}

Group& Group::operator=(const Group& g1)
{
	nums = g1.nums;
	largest = g1.largest;
	smallest = g1.smallest;
	return *this;
}

bool Group::operator<(const Group& g) const
{
	//@TODO: guardar número de comparações
	//posso fazer um template que inclua esta e a dos ints de modo a armazenar
	//o nº de cmp?
	return largest < g.largest;
}

std::ostream& operator<<(std::ostream& os, const Group& g)
{
	static const char GRN[] = "\033[1;32m"; // bold green
	static const char RED[] = "\033[1;31m"; // bold red
	static const char RST[] = "\033[0m";    // reset

	os << "[";
	for (size_t i = 0; i < g.nums.size(); ++i)
	{
		if (g.nums.at(i) == g.largest) os << GRN;
		if (g.nums.at(i) == g.smallest) os << RED;
		os << g.nums.at(i);
		if (g.nums.at(i) == g.largest) os << RST;
		if (g.nums.at(i) == g.smallest) os << RST;
		if (i + 1 < g.nums.size())
			os << ", ";
	}
	os << "]";

	return os;
}

Group::~Group() {}

void Group::merge(const Group& larger, const Group& smaller)
{
	nums.clear();
	nums.reserve(larger.nums.size() + smaller.nums.size());

	nums.insert(nums.end(), larger.nums.begin(), larger.nums.end());
	nums.insert(nums.end(), smaller.nums.begin(), smaller.nums.end());

	largest  = CmpCounter::less(larger.largest, smaller.largest) ? smaller.largest : larger.largest;
	smallest = CmpCounter::less(larger.largest, smaller.largest) ? larger.largest : smaller.largest;
}
