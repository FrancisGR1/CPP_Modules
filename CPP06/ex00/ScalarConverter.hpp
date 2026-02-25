#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter 
{
	public:
		static void convert(const std::string&);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		// utils
		static std::string to_string(unsigned char value, double original_value);
		static std::string to_string(int value, double original_value);
		static std::string to_string(float value, double original_value);
		static std::string to_string(double value);
		static bool is_number(const std::string& literal);

};

#endif /*SCALARCONVERTER_HPP*/
