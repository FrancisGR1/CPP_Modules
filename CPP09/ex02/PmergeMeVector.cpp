#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cctype>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

#include "Value.hpp"
#include "Round.hpp"
#include "PmergeMeVector.hpp"

//@ASSUMPTION container contains Value struct
PmergeMeVector::PmergeMeVector()
	: m_validator("std::vector", m_final_rank)
{
	// initialize first round
	m_rounds.push_back(Round<std::vector<Value>, std::vector<ValueMetaData> >());
}

PmergeMeVector::PmergeMeVector(const PmergeMeVector& other)
	: m_final_rank(other.m_final_rank)
	, m_rounds(other.m_rounds)
	, m_values_info(other.m_values_info)
	, m_validator("std::vector", m_final_rank) {}

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
	m_validator.start(argc, argv);

	// alloc space for array of meta data
	// @ASSUMPTION: meta data size = number of numbers
	m_values_info.reserve(argc);

	// parse and start matching values
	for (int i = 0; i + 1 < argc; ++i)
	{
		int av_idx = i + 1;
		expect_unsigned_int(argv[av_idx]);
		unsigned int unique_id = i;
		Value value1(argv[av_idx], unique_id);
		m_values_info.push_back(ValueMetaData(value1));

		if (av_idx + 1 < argc)
		{
			expect_unsigned_int(argv[av_idx + 1]);
			Value value2(argv[av_idx + 1], unique_id + 1);
			m_values_info.push_back(ValueMetaData(value2));
			m_rounds[0].match_and_save(value1, value2);
			++i;
		}
		else
		{
			m_rounds[0].add_and_save(value1);
		}
	}

	// in case there's only one number
	if (argc == 2)
	{
		m_validator.end();
		m_final_rank.push_back(m_rounds[0].losers[0]);
		return;
	}

	// set winner/loser pairs recursively until there's one single winner
	while (true)
	{
		// is there a final winner?
		Round<std::vector<Value>, std::vector<ValueMetaData> > last_round = m_rounds.back();
		if (last_round.winners.size() == 1)
		{
			break;
		}

		// initialize new round
		m_rounds.push_back(Round<std::vector<Value>, std::vector<ValueMetaData>  >());
		Round<std::vector<Value>, std::vector<ValueMetaData> >& current_round = m_rounds.back();
		for (size_t i = 0; i < last_round.winners.size(); ++i)
		{
			// match or push to losers 
			// and then save meta data
			Value value1(last_round.winners[i]);
			if (i + 1 < last_round.winners.size())
			{
				// match and save data
				Value value2(last_round.winners[i + 1]);
				current_round.match_and_save(value1, value2);
				++i;
			}
			else
			{
				// if doesn't have a pair = then it's loser
				current_round.add_and_save(value1);
			}
		}
	}

	// initialize the final rank with winner
	const Round<std::vector<Value>, std::vector<ValueMetaData> >& last_round = m_rounds.back();
	place_in_final_rank(last_round.winners[0], 0);

	// fill out the rank recursively until every loser is inserted in final rank
	for (std::vector<Round<std::vector<Value>, std::vector<ValueMetaData> > >::reverse_iterator rit = m_rounds.rbegin(); rit != m_rounds.rend(); ++rit)
	{
		const Round<std::vector<Value>, std::vector<ValueMetaData> >& round = *rit;
		std::vector<size_t> order_idx = build_jacobsthal_order(round.losers.size());
		for (size_t i = 0; i < round.losers.size(); ++i)
		{
			const Value& to_insert = round.losers[order_idx[i]];
			size_t upper_idx = get_max_bound(order_idx[i], round);
			size_t insertion_idx = final_rank_binary_insertion(to_insert, 0, upper_idx);
			place_in_final_rank(to_insert, insertion_idx);
		}
	}

	m_validator.end();
}

size_t PmergeMeVector::get_max_bound(size_t index, const Round<std::vector<Value>, std::vector<ValueMetaData> >& current_round)
{
	if (m_final_rank.size() == 0)
		return 0;

	if (current_round.winners.size() > index)
	{
		// find respective winner's id
		unsigned int winner_id = current_round.winners[index].unique_id;
		// now use id to find its position in final rank
		long result = m_values_info[winner_id].rank_idx;
		if (result >= 0) // check if rank_idx was set
			return static_cast<size_t>(result);
	}

	// default to last index
	return m_final_rank.size() - 1;
}

int PmergeMeVector::final_rank_binary_insertion(const Value& to_insert, int low, int high)
{
	if (high <= low)
		return (to_insert > m_final_rank[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (to_insert > m_final_rank[mid])
		return final_rank_binary_insertion(to_insert, mid + 1, high);

	return final_rank_binary_insertion(to_insert, low, mid - 1);
}

void PmergeMeVector::place_in_final_rank(const Value& to_insert, size_t index)
{
	if (index == m_final_rank.size()) 
	{
		m_final_rank.push_back(to_insert);
		m_values_info[to_insert.unique_id].rank_idx = m_final_rank.size() - 1;
	}
	else
	{
		m_final_rank.insert(m_final_rank.begin() + index, to_insert);
		m_values_info[to_insert.unique_id].rank_idx = index;
	}

	// update every rank position
	for (size_t i = 0; i < m_final_rank.size(); ++i)
	{
		m_values_info[m_final_rank[i].unique_id].rank_idx = i;
	}
}

std::vector<size_t> PmergeMeVector::build_jacobsthal_order(size_t n)
{
	std::vector<size_t> order;
	size_t prev = 0;
	size_t k = 1;

	while (true)
	{
		size_t J = jacobsthal(k);
		if (J > n)
			J = n;

		for (size_t i = J; i > prev; --i)
			order.push_back(i - 1);

		if (J == n)
			break;

		prev = J;
		++k;
	}
	return order;
}

size_t PmergeMeVector::jacobsthal(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMeVector::print_final_rank() const
{
	std::cout << "Final Rank (" << m_final_rank.size() << "): \n";
	for (size_t i = 0; i < m_final_rank.size(); ++i)
	{
		std::cout << m_final_rank[i].number << " ";
	}
	std::cout << "\n";
}

void PmergeMeVector::print_meta_data() const
{
	std::cout << "Meta data:\n";
	for (size_t i = 0; i < m_values_info.size(); ++i)
	{
		std::cout << m_values_info[i].value.number << "[" << m_values_info[i].rank_idx << "] ";
	}
	std::cout << "\n";
}

void PmergeMeVector::print_rounds() const
{
	std::cout << "\n=====\n";
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
