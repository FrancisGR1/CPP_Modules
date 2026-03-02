#ifndef PMERGME_HPP
#define PMERGME_HPP

#include <cassert>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

#include "Value.hpp"
#include "Round.hpp"
#include "ValueMetaData.hpp"

//@ASSUMPTION container contains Value struct
class PmergeMeVector
{
	public:
		PmergeMeVector();
		PmergeMeVector(const PmergeMeVector& other);
		~PmergeMeVector();

		void sort(int argc, char **argv);
		void sort();
		size_t size() const;

	private:
		std::vector<Value> m_final_rank;
		std::vector<Round<std::vector<Value> > > m_rounds;
		std::vector<ValueMetaData> m_values_info;

		// debuggers
		void print_rounds() const;

		// illegal
		PmergeMeVector& operator=(const PmergeMeVector& other);
};

#endif // PMERGME_HPP
