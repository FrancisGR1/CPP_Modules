#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
	: m_prices_database_path("data.csv")
{
	load_database(m_prices_database_path);
};

BitcoinExchange::BitcoinExchange(const char *prices_database_path) 
	: m_prices_database_path(prices_database_path)
{
	load_database(m_prices_database_path);
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
	: m_prices_database_path(other.m_prices_database_path)
	, m_database(other.m_database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) 
{
	m_prices_database_path = other.m_prices_database_path;
	m_database = other.m_database;
	return *this;
};

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::evaluate(const char *evaluation_path) {};

void BitcoinExchange::load_database(const std::string& m_prices_database_path)
{
	std::ifstream file(m_prices_database_path.c_str());
	if (!file)
	{
		throw std::runtime_error("Error: Can't open: " + m_prices_database_path);
	}

	std::string line;
	//@NOTE:skip first line
	std::getline(file, line);
	while (std::getline(file, line))
	{
		for (size_t idx = 0; idx < line.size(); ++idx)
		{
			skip_whitespaces(line, idx);
			Date date = str_to_date(line, idx);
			skip_whitespaces(line, idx);
			expect(",", line, idx);
			skip_whitespaces(line, idx);
			ExchangeRate er = str_to_exchange_rate(line, idx);
		}
	};

};

void BitcoinExchange::skip_whitespaces(const std::string& line, size_t& idx)
{
	while (idx < line.size() && std::isspace(line.at(idx)))
		++idx;
};

BitcoinExchange::Date BitcoinExchange::str_to_date(const std::string& line, size_t& idx)
{
	if (idx >= line.size())
	{
		throw std::runtime_error("Error: bad input => " + line);
	}

	return 1;
};

BitcoinExchange::ExchangeRate BitcoinExchange::str_to_exchange_rate(const std::string& line, size_t& idx)
{
	if (idx >= line.size())
	{
		throw std::runtime_error("Error: bad input => " + line);
	}
	return 1;
};

void BitcoinExchange::expect(const std::string& str, const std::string& line, size_t& idx)
{
	if (
};
