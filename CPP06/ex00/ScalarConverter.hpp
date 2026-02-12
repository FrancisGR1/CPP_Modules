#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter 
{
	public:
		static void convert(const std::string&);


	private:
		static double m_value;

		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		// utils
		static std::string to_string(unsigned char value, double original_value);
		static std::string to_string(int value, double original_value);
		static std::string to_string(float value, double original_value);
		static std::string to_string(double value);

};

#endif /*SCALARCONVERTER_HPP*/
