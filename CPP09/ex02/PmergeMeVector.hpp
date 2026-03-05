#ifndef PMERGMEVECTOR_HPP
#define PMERGMEVECTOR_HPP

#include <cassert>
#include <cstdlib>
#include <cctype>
#include <vector>

#include "Value.hpp"
#include "Round.hpp"
#include "ValueMetaData.hpp"
#include "PmergeMeValidator.hpp"

//@ASSUMPTION container contains Value struct
class PmergeMeVector
{
	public:
		PmergeMeVector();
		PmergeMeVector(const PmergeMeVector& other);
		~PmergeMeVector();

		void sort(int argc, char **argv);
		size_t size() const;

	private:
		std::vector<Value> m_final_rank;
		std::vector<Round<std::vector<Value>, std::vector<ValueMetaData> > > m_rounds;
		std::vector<ValueMetaData> m_values_info;
		PmergeMeValidator<std::vector<Value> > m_validator;

		// utils
		size_t get_max_bound(size_t index, const Round<std::vector<Value>, std::vector<ValueMetaData> >& current_round);
		int final_rank_binary_insertion(const Value& to_insert, int low, int high);
		void place_in_final_rank(const Value& to_insert, size_t index);
		std::vector<size_t> build_jacobsthal_order(size_t n);
		size_t jacobsthal(size_t n);

		// debuggers
		void print_meta_data() const;
		void print_final_rank() const;
		void print_rounds() const;

		// illegal
		PmergeMeVector& operator=(const PmergeMeVector& other);
};

#endif // PMERGMEVECTOR_HPP
