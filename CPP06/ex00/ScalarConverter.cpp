#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#include "ScalarConverter.hpp"

double ScalarConverter::m_value = 0.0;

void ScalarConverter::convert(const std::string& literal) 
{
	// parser number
	char *endptr = NULL;
	m_value = strtod(literal.c_str(), &endptr);

	std::cout << std::fixed << std::setprecision(1);

	// transform to string:
	std::cout << "char: "   << to_string(static_cast<unsigned char>(m_value), m_value) << "\n";

	std::cout << "int: "    << to_string(static_cast<int>(m_value), m_value) << "\n";

	std::cout << "float: "  << to_string(static_cast<float>(m_value), m_value) << "\n";

	std::cout << "double: " << to_string(m_value) << "\n";
};

std::string ScalarConverter::to_string(unsigned char value, double original_value = 0) 
{
	if (original_value > 255 || original_value < 0 || std::isnan(original_value) || std::isinf(original_value))
		return "impossible";
	else if (std::isprint(value))
		return std::string(1, value);
	else
		return "non displayable";
};

std::string ScalarConverter::to_string(int value, double original_value = 0) 
{
	if (std::isnan(original_value) || original_value < -std::numeric_limits<int>::max() ||
			original_value > std::numeric_limits<int>::max())
		return "impossible";

	std::stringstream ss;
	ss << value;
	return ss.str();
};

std::string ScalarConverter::to_string(float value, double original_value = 0) 
{
	if (std::isnan(value))
		return "nanf";
	else if (std::isinf(value))
		return (std::signbit(value) ? "-inff" : "+inff");
	else if (original_value <= -std::numeric_limits<float>::max() ||
			original_value >= std::numeric_limits<float>::max())
		return "impossible";
	else
	{
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(1) << value << "f";
		std::string result = oss.str();
		return result;
	}
};

std::string ScalarConverter::to_string(double value) 
{
	if (std::isnan(value))
		return "nan";
	else if (std::isinf(value))
		return (std::signbit(value) ? "-inf" : "+inf");
	else
	{
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(1) << value;
		std::string result = oss.str();
		return result;
	}
};
