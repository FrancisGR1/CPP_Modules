#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cassert>

#include "Group.hpp"
#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
	: m_lvl(0)
	, m_group_size(2) {}

PMergeMe::PMergeMe(int argc, char **argv)
	: m_lvl(0)
	, m_group_size(2)
{
	if (argc < 2)
		throw std::runtime_error("./PMergeMe <nums>");

	LeveledGroups v;
	for (int i = 1; i < argc; i+= 2)
	{
		int n1;
		int n2;
		if (i < argc && is_number(argv[i]))
		{
			n1 = atoi(argv[i]);
		}
		else
		{
			throw std::runtime_error("Error: Not a number: " + std::string(argv[i]));
		}
		if (i + 1 < argc)
		{
			if (is_number(argv[i + 1]))
			{
				n2 = atoi(argv[i + 1]);
			}
			else
			{
				throw std::runtime_error("Error: Not a number: " + std::string(argv[i + 1]));
			}
			v.push_back(Group(n1, n2));
			std::cout << "push back: " << Group(n1, n2) << "\n";
		}
		else
		{
			v.push_back(Group(n1));
			std::cout << "push back: " << Group(n1) << "\n";
		}
	}
	m_groups.push_back(v);
	print_groups();
	++m_lvl;
}

PMergeMe::PMergeMe(const PMergeMe& other)
	: m_lvl(other.m_lvl)
	, m_group_size(other.m_group_size) {}

PMergeMe& PMergeMe::operator=(const PMergeMe& other)
{ 
	m_lvl = other.m_lvl;
	m_group_size = other.m_group_size;
	m_groups = other.m_groups;
	return *this;
}

PMergeMe::~PMergeMe(){}

void PMergeMe::apply()
{
	assert(m_lvl > 0);
	print_groups();
	while (true)
	{
		LeveledGroups prev = m_groups.back();
		LeveledGroups curr;
		bool new_merge = false;
		for (size_t i = 0; i < prev.size(); ++i)
		{
			Group g1 = prev.at(i);
			if (i + 1 < prev.size())
			{
				Group g2 = prev.at(i + 1);
				if (g1.nums.size() == g2.nums.size())
				{
					new_merge = true;
					curr.push_back(Group(g1, g2));
					++i;
					std::cout << "Pushed: " << g1 << "\n" << g2 << "\n";
				}
				else
				{
					curr.push_back(Group(g1));
					std::cout << "Pushed: " << g1 << "\n";
				}
			}
			else
			{
				curr.push_back(Group(g1));
				std::cout << "Pushed: " << g1 << "\n";
			}
		}

		if (!new_merge) 
			break;
		else
			m_groups.push_back(curr);

		std::cout << "N Groups: " << m_groups.back().size() << "\n";

	}
	print_groups();
}

void PMergeMe::print() const
{

}

void PMergeMe::print_groups() const
{
	std::cout << "\nGroups:\n";
	for (size_t i = 0; i < m_groups.size(); ++i)
	{
		std::cout << "Level: " << i << " ";
		for (size_t j = 0; j < m_groups.at(i).size(); ++j)
		{
			Group g = m_groups.at(i).at(j);
			std::cout << g << " ";
		}
		std::cout << "\n";
	}
}

void PMergeMe::update_group_size()
{
	m_group_size *= 2;
}

bool PMergeMe::is_number(const std::string& s) const
{
	std::istringstream iss(s);
	double d;
	return iss >> std::noskipws >> d && iss.eof();
}
