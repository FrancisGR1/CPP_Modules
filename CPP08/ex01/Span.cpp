#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <vector>
#include "Span.hpp"

Span::Span()
{
	m_data.reserve(10);
}

Span::Span(unsigned int N)
{
	m_data.reserve(N);
}

Span::Span(const Span& other)
	: m_data(other.m_data)
{}

Span& Span::operator=(const Span& other)
{
	m_data = other.m_data;
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int num)
{
	if (m_data.size() >= m_data.capacity())
		throw std::out_of_range("Span is full");
	m_data.push_back(num);
}

void Span::setNumberAt(int num, size_t idx)
{
	if (idx >= m_data.capacity())
		throw std::out_of_range("Can't add number");
	m_data.at(idx) = num;
}

void Span::fillRandom(int modulus)
{
	srand(time(0));

	for (size_t i = 0; i < m_data.capacity(); ++i)
	{
		m_data.push_back(rand() % modulus);
	}
}

int  Span::shortestSpan() const
{
	if (m_data.size() < 2)
		throw std::logic_error("Less than 2 elements");

	std::vector<int> copy(m_data);
	std::sort(copy.begin(), copy.end());

	int min = std::numeric_limits<int>::max();
	for (size_t i = 1; i < copy.size(); ++i)
	{
		int diff = copy.at(i) - copy.at(i - 1);
		if (diff < min)
			min = diff;
	}

	return min;
}

int  Span::longestSpan() const
{
	if (m_data.size() < 2)
		throw std::logic_error("Less than 2 elements");

	int min = m_data[0];
	int max = m_data[0];

	for (size_t i = 0; i < m_data.size(); ++i)
	{
		if (min > m_data.at(i))
			min = m_data.at(i);
		if (max < m_data.at(i))
			max = m_data.at(i);
	}

	return max - min;
}

void Span::print() const
{
	for (size_t i = 0; i < m_data.size(); ++i)
	{
		std::cout << m_data.at(i);
		if (i < m_data.size() - 1)
			std::cout << ", ";
		else
			std::cout << "\n";
	}
}
