#ifndef PMERGMEDEQUE_HPP
#define PMERGMEDEQUE_HPP

#include <cassert>
#include <cstdlib>
#include <deque>

#include "Value.hpp"
#include "Round.hpp"
#include "ValueMetaData.hpp"
#include "PmergeMeValidator.hpp"

//@ASSUMPTION container contains Value struct
class PmergeMeDeque
{
	public:
		PmergeMeDeque();
		PmergeMeDeque(const PmergeMeDeque& other);
		~PmergeMeDeque();

		void sort(int argc, char **argv);
		void info() const;

	private:
		std::deque<Value> m_final_rank;
		std::deque<Round<std::deque<Value>, std::deque<ValueMetaData> > > m_rounds;
		std::deque<ValueMetaData> m_values_info;
		PmergeMeValidator<std::deque<Value> > m_validator;

		// utils
		size_t get_max_bound(size_t index, const Round<std::deque<Value>, std::deque<ValueMetaData> >& current_round);
		int final_rank_binary_insertion(const Value& to_insert, int low, int high);
		void place_in_final_rank(const Value& to_insert, size_t index);
		std::deque<size_t> build_jacobsthal_order(size_t n);
		size_t jacobsthal(size_t n);

		// debuggers
		void print_meta_data() const;
		void print_final_rank() const;
		void print_rounds() const;

		// illegal
		PmergeMeDeque& operator=(const PmergeMeDeque& other);
};

#endif // PMERGMEDEQUE_HPP
