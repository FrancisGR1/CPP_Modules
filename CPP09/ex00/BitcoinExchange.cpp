#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <limits>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
	: m_exchange_rate_db_path("data.csv")
{
	load_database();
};

BitcoinExchange::BitcoinExchange(const char *prices_database_path) 
	: m_exchange_rate_db_path(prices_database_path)
{
	load_database();
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
	: m_exchange_rate_db_path(other.m_exchange_rate_db_path)
	, m_database(other.m_database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) 
{
	m_exchange_rate_db_path = other.m_exchange_rate_db_path;
	m_database = other.m_database;
	return *this;
};

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::evaluate(const std::string& evaluation_path) 
{
	std::cout << "Evaluating file: " << evaluation_path << "\n";
	std::ifstream file(evaluation_path.c_str());
	if (!file)
	{
		throw std::runtime_error("Error: Can't open: " + evaluation_path);
	}

	std::string line;
	//@NOTE:skip first line
	std::getline(file, line);
	while (std::getline(file, line))
	{
		try
		{
			size_t idx = 0;
			skip_whitespaces(line, idx);
			size_t date_str_start = idx;
			Date date = to_date(line, idx);
			size_t date_str_end = idx;
			skip_whitespaces(line, idx);
			expect("|", line, idx);
			skip_whitespaces(line, idx);
			Quantity quantity = to_quantity(line, idx);
			if (quantity < 0.0 || quantity > 1000.0)
				throw std::runtime_error("Error: quantity must be between 0 and 1000");
			skip_whitespaces(line, idx);
			if (idx != line.size())
				throw std::runtime_error("Error: expected end of line after quantity: '" + line + "'");

			std::map<Date, ExchangeRate>::iterator it = m_database.upper_bound(date);
			// find exchange rate date
			if (it->first == date) // exists
				;
			else if (it->first > date && it != m_database.begin()) // previous
				--it;
			else
				throw std::runtime_error("Error: No earlier date exists");
			std::string date_str = line.substr(date_str_start, date_str_end - date_str_start);
			std::cout << quantity << " * " << it->second << "\n";
			std::cout << date_str << " => " << quantity << " = " << quantity * it->second << "\n";

		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n";
		}
	};
};

// loads a .csv file
void BitcoinExchange::load_database()
{
	std::cout << "Loading database: " << m_exchange_rate_db_path << "\n";
	std::ifstream file(m_exchange_rate_db_path.c_str());
	if (!file)
	{
		throw std::runtime_error("Error: Can't open: " + m_exchange_rate_db_path);
	}

	std::string line;
	//@NOTE:skip first line
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t idx = 0;
		skip_whitespaces(line, idx);
		Date date = to_date(line, idx);
		skip_whitespaces(line, idx);
		expect(",", line, idx);
		skip_whitespaces(line, idx);
		ExchangeRate er = to_quantity(line, idx);
		skip_whitespaces(line, idx);
		if (idx != line.size())
			throw std::runtime_error("Error: expected end of line after exchange rate: " + line);
		m_database[date] = er;
	};
};

void BitcoinExchange::skip_whitespaces(const std::string& line, size_t& idx)
{
	while (idx < line.size() && std::isspace(line.at(idx)))
		++idx;
};

// YYYY-MM-DD
BitcoinExchange::Date BitcoinExchange::to_date(const std::string& line, size_t& idx)
{
	Date date;

	if (idx >= line.size())
	{
		throw std::runtime_error("Error: bad input => " + line);
	}
	// YYYY
	std::string year_str = "";
	for (; idx < line.size(); ++idx)
	{
		char c = line.at(idx);

		if (!(std::isdigit(c)))
			break;
		year_str += c;
	}
	if (year_str.size() < 4)
		throw std::runtime_error("Error: invalid year format: " + line);

	int year = std::atoi(year_str.c_str());
	if (year < 0)
		throw std::runtime_error("Error: Impossible year: " + year_str);
	date = year;

	skip_whitespaces(line, idx);
	expect("-", line, idx);
	skip_whitespaces(line, idx);

	// MM
	std::string month_str = "";
	for (; idx < line.size(); ++idx)
	{
		char c = line.at(idx);

		if (!(std::isdigit(c)))
			break;
		month_str += c;
	}
	if (month_str.size() < 2)
		throw std::runtime_error("Error: invalid month format: " + line);

	int month = std::atoi(month_str.c_str());
	if (month < 0 || month > 12)
		throw std::runtime_error("Error: invalid month number: " + month_str);
	date =  date * 100 + month;

	skip_whitespaces(line, idx);
	expect("-", line, idx);
	skip_whitespaces(line, idx);

	// DD
	std::string day_str = "";
	for (; idx < line.size(); ++idx)
	{
		char c = line.at(idx);

		if (!(std::isdigit(c)))
			break;
		day_str += c;
	}
	if (day_str.size() < 2)
		throw std::runtime_error("Error: invalid day format: " + line);

	int day = std::atoi(day_str.c_str());
	if (day < 0 || day > 31)
		throw std::runtime_error("Error: invalid day number: " + day_str);
	date =  date * 100 + day;

	return date;
};

BitcoinExchange::Quantity BitcoinExchange::to_quantity(const std::string& line, size_t& idx)
{
	if (idx >= line.size())
	{
		throw std::runtime_error("Error: bad input => " + line);
	}

	std::string er_str = line.substr(idx);
	char *end = NULL;
	double er = std::strtod(er_str.c_str(), &end);
	if (end == er_str.c_str())
		throw std::runtime_error("Error: couldn't convert quantity => " + line);
	if (er > std::numeric_limits<Quantity>::max())
		throw std::runtime_error("Error: quantity too large => " + er_str);
	if (er < 0.0)
		throw std::runtime_error("Error: negative quantity => " + er_str);

	size_t increment = end - er_str.c_str();
	idx += increment;

	return static_cast<Quantity>(er);
};

void BitcoinExchange::expect(const std::string& str, const std::string& line, size_t& idx)
{
	if (idx + str.size() >= line.size() || str != line.substr(idx, str.size()))
	{
		const std::string error_msg = 
			"Error: expected '" + str + 
			"'. Got: '" + line.substr(idx, str.size()) +
			"'. In line: '" + line + "'";
		throw std::runtime_error(error_msg);
	}
	++idx;
};
