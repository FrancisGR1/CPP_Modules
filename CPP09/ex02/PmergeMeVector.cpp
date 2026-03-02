#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cctype>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

#include "PmergeMeVector.hpp"

//@ASSUMPTION container contains Value struct
PmergeMeVector::PmergeMeVector()
{
	// initialize first round
	m_rounds.push_back(Round<std::vector<Value> >());
}

PmergeMeVector::PmergeMeVector(const PmergeMeVector& other)
	: m_final_rank(other.m_final_rank)
	, m_rounds(other.m_rounds)
	, m_values_info(other.m_values_info) {}

PmergeMeVector::~PmergeMeVector() {}

static void expect_unsigned_int(char *number_str)
{
	std::stringstream ss;
	ss << number_str;

	const std::string& number = ss.str();
	for (size_t i = 0; i < number.size(); ++i)
	{
		if (!std::isdigit(number[i]))
		{
			// @TODO substituir por exception própria
			std::string not_a_number_msg  = "Error: " + std::string(number_str) + "is not a valid unsigned integer";
			throw std::invalid_argument(not_a_number_msg);
		}
	}

	double tmp_long;
	ss >> tmp_long;
	if (tmp_long > std::numeric_limits<int>::max())
	{
		std::string not_a_number_msg  = "Error: " + std::string(number_str) + "is not a valid unsigned integer";
		throw std::invalid_argument(not_a_number_msg);
	}

}

void PmergeMeVector::sort(int argc, char **argv)
{
	// alloc space for array of meta data
	m_values_info.reserve(argc);

	// parse and start matching values
	for (int i = 1; i < argc; ++i)
	{
		expect_unsigned_int(argv[i]);
		unsigned int unique_id = i;
		Value value1(argv[i], unique_id);
		m_values_info.push_back(ValueMetaData(value1));

		if (i + 1 < argc)
		{
			expect_unsigned_int(argv[i + 1]);
			Value value2(argv[i + 1], unique_id + 1);
			m_values_info.push_back(ValueMetaData(value2));
			std::cout << "matching\n";
			m_rounds[0].match_and_save(value1, i, value2, i + 1, m_values_info);
			++i;
		}
		else
		{
			m_rounds[0].add_and_save(value1, i, m_values_info);
		}
	}

	// set winner/loser pairs recursively until one having one winner only
	while (true)
	{
		std::cout << "\n\n=========\n";
		print_rounds();
		// is there a final winner?
		Round<std::vector<Value> > last_round = m_rounds.back();
		std::cout << "last rd winners: " << last_round.winners.size()  << "\n";
		if (last_round.winners.size() == 1)
		{
			std::cout << "Winner: " << last_round.winners[0].number << "\n";
			break;
		}

		// initialize new round
		m_rounds.push_back(Round<std::vector<Value> >());
		Round<std::vector<Value> >& current_round = m_rounds.back();
		for (size_t i = 0; i < last_round.winners.size(); ++i)
		{
			// match or push to losers 
			// and then save meta data
			Value value1(last_round.winners[i]);
			if (i + 1 < last_round.winners.size())
			{
				std::cout << i + 1;
				// match and save data
				Value value2(last_round.winners[i + 1]);
				current_round.match_and_save(value1, i, value2, i + 1, m_values_info);
				++i;
			}
			else
			{
				// if doesn't have a pair = then it's loser
				m_rounds[0].add_and_save(value1, i, m_values_info);
			}
			std::cout << "\n";
		}
	}

	// fill out the rank recursively until every loser is inserted in final rank
}

void PmergeMeVector::print_rounds() const
{
	for (size_t i = 0; i < m_rounds.size(); ++i)
	{
		std::cout << "Round: " << i << "\n";

		std::cout << "\tWinners:\n\t";
		for (size_t j = 0; j < m_rounds[i].winners.size(); ++j)
		{
			std::cout << m_rounds[i].winners[j].number << " ";
		}
		std::cout << "\n";

		std::cout << "\tLosers:\n\t";
		for (size_t j = 0; j < m_rounds[i].losers.size(); ++j)
		{
			std::cout << m_rounds[i].losers[j].number << " ";
		}

		std::cout << "\n";
	}
}
