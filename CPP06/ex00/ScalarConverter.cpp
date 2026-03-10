#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) 
{
	double value = 0;

	// check for specific strings
	if (literal == "nan" || literal == "nanf")
	{
		value = std::numeric_limits<double>::quiet_NaN();
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		value = std::numeric_limits<double>::infinity();
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		value = -std::numeric_limits<double>::infinity();
	}
	else if (literal.size() == 1)
	{
		value = static_cast<double>(literal[0]);
	}
	else if (is_number(literal))
	{
		char *endptr = NULL;
		value = strtod(literal.c_str(), &endptr);
	}
	else
	{
		std::cout << "Not a number\n";
		return;
	}


	std::cout << std::fixed << std::setprecision(6);

	// transform to string:
	std::cout << "char: "   << to_string(static_cast<unsigned char>(value), value) << "\n";

	std::cout << "int: "    << to_string(static_cast<int>(value), value) << "\n";

	std::cout << "float: "  << to_string(static_cast<float>(value), value) << "\n";

	std::cout << "double: " << to_string(value) << "\n";
};

bool ScalarConverter::is_number(const std::string& literal)
{
	bool parsed_dot = false;

	for (size_t i = 0; i < literal.size(); ++i)
	{
		if (!std::isdigit(literal[i]))
		{
			if (i == 0 && literal[i] == '-')
			{
				;
			}
			else if (literal[i] == '.' && !parsed_dot && i != 0)
			{
				parsed_dot = true;
			}
			else if (literal[i] == 'f' && !literal.empty() && i == literal.size() - 1)
			{
				if (literal[i - 1] == '.' || literal[i - 1] == '-')
					return false;
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

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
		oss << std::fixed << std::setprecision(6) << value << "f";
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
		oss << std::fixed << std::setprecision(6) << value;
		std::string result = oss.str();
		return result;
	}
};
