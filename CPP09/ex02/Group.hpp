#ifndef GROUP_HPP
#define GROUP_HPP

#include <vector>
#include <ostream>

struct Group
{
	std::vector<int> nums;
	int largest;
	int smallest;

	Group();
	Group(int n1);
	Group(int n1, int n2);
	Group(const Group& g1);
	Group(const Group& g1, const Group& g2);
	Group& operator=(const Group& g1);
	bool operator<(const Group& g) const;
	~Group();

	void merge(const Group& larger, const Group& smaller);
};
std::ostream& operator<<(std::ostream& os, const Group& g);

#endif //GROUP_HPP
