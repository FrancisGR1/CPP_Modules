#ifndef PMERGME_HPP
#define PMERGME_HPP

#include "Group.hpp"

#include <vector>
#include <deque>
#include <sstream>

class PMergeMe
{
	public:
		typedef std::vector<Group> LeveledGroups;

		PMergeMe();
		PMergeMe(int argc, char **argv);
		PMergeMe(const PMergeMe& other);
		PMergeMe& operator=(const PMergeMe& other);
		~PMergeMe();

		void apply();
		void print() const;
		void print_groups() const;

	private:
		std::vector<LeveledGroups> m_groups;
		size_t m_lvl;
		//@TODO eliminar?
		size_t m_group_size; //@TODO: isto é confuso; pode confudir-se com m_groups.size()

		bool is_number(const std::string& s) const;

		void update_group_size();
};

#endif //PMERGME_HPP
