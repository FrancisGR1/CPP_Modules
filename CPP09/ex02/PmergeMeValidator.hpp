#ifndef PMERGMEVALIDATOR_HPP
#define PMERGMEVALIDATOR_HPP

#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>

#include "Time.hpp"
#include "Value.hpp"

template <typename Container>
class PmergeMeValidator
{
	public:
		PmergeMeValidator(const char* container_type, const Container& container);
		void start(int argc, char** argv) const;
		void end() const;
		void info() const;

	private:
		const std::string m_type;
		const Container& m_container;

		// utils
		bool is_sorted() const;
		// illegal
		PmergeMeValidator();
};

template <typename Container>
PmergeMeValidator<Container>::PmergeMeValidator(const char* container_type, const Container& container)
	: m_type(container_type)
	, m_container(container) {}

//@ASSUMPTION container contains Value struct
template <typename Container>
void PmergeMeValidator<Container>::start(int argc, char** argv) const
{
	// log unsorted sequence
	std::cout << "Original: ";
	for (int i = 1; i < argc; ++i)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << "\n";

	// start timer
	Time::start();

	// reset number of cmp
	Value::total_comparisons = 0;
}

template <typename Container>
void PmergeMeValidator<Container>::end() const
{
	Time::stop();

	// log final sequence
	std::cout << "Sorted: ";
	for (size_t i = 0; i < m_container.size(); ++i)
	{
		std::cout << m_container[i].number << " ";
	}
	std::cout << "\n";
}

template <typename Container>
void PmergeMeValidator<Container>::info() const
{
	std::cout << "Elements: " << m_container.size() 
		<< std::fixed << std::setprecision(6) 
		<< " | Time Elapsed: " << Time::elapsed() << "us"
		<< std::boolalpha 
		<< " | Comparisons: " << Value::total_comparisons 
		<< " | Sorted: " << is_sorted() 
		<< " | Container: " << m_type 
		<< "\n";
}

template <typename Container>
bool PmergeMeValidator<Container>::is_sorted() const
{
	Container sorted = m_container;
	// @NOTE: std::sort needs comparison operator
	// for Value but its comparisons don't count
	size_t original = Value::total_comparisons;
	std::sort(sorted.begin(), sorted.end());
	Value::total_comparisons = original;

	if (sorted.size() != m_container.size())
		return false;

	for (size_t i = 0; i < sorted.size(); ++i)
	{
		if (sorted[i].number != m_container[i].number)
			return false;
	}

	return true;
}

#endif // PMERGMEVALIDATOR_HPP
