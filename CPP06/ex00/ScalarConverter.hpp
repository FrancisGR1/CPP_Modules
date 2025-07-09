#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <optional>

class ScalarConverter {
 public:
  static void convert(const std::string&);
  static std::string print_value(unsigned char);
  static std::string print_value(int);
  static std::string print_value(double);
  static std::string print_value(float);
  static std::optional<std::string> invalid_int(double input);
  static std::optional<std::string> invalid_float(double input);
  static std::optional<std::string> invalid_double(double input);

  ScalarConverter() = delete;
  ScalarConverter(const ScalarConverter&) = delete;
  ScalarConverter& operator=(const ScalarConverter&) = delete;
  ~ScalarConverter() = delete;

 private:
  static double m_value;
};

#endif /*SCALARCONVERTER_HPP*/
