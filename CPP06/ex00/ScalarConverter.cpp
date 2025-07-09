#include "ScalarConverter.hpp"

double ScalarConverter::m_value = 0.0;

void ScalarConverter::convert(const std::string& literal) {
  try {
    m_value = literal.length() == 1 && !isdigit(literal.at(0))
                  ? static_cast<double>(literal.at(0))
                  : std::stod(literal);

    std::cout << std::fixed << std::setprecision(1);
    auto error = ScalarConverter::invalid_int(m_value);
    std::cout << "char: "
              << (error ? error.value()
                        : print_value(static_cast<unsigned char>(m_value)))
              << std::endl;
    std::cout << "int: "
              << (error ? error.value()
                        : print_value(static_cast<int>(m_value)))
              << std::endl;
    error = ScalarConverter::invalid_float(m_value);
    std::cout << "float: "
              << (error ? error.value()
                        : print_value(static_cast<float>(m_value)))
              << std::endl;
    error = ScalarConverter::invalid_double(m_value);
    std::cout << "double: " << (error ? error.value() : print_value(m_value))
              << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Invalid input: '" << literal << "' is not a number."
              << std::endl;
  } catch (const std::out_of_range& e) {
    std::cerr << "Out of range: '" << literal
              << "' is too large or small to convert." << std::endl;
  }
};

std::string ScalarConverter::print_value(unsigned char value) {
  std::string result = "non displayable";

  if (std::isprint(value))
    result = std::string(1, static_cast<unsigned char>(value));

  return result;
};

std::string ScalarConverter::print_value(int value) {
  std::string result = std::to_string(value);

  return result;
};

std::string ScalarConverter::print_value(float value) {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(1) << value << "f";
  std::string result = oss.str();

  return result;
};

std::string ScalarConverter::print_value(double value) {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(1) << value;
  std::string result = oss.str();

  return result;
};

std::optional<std::string> ScalarConverter::invalid_float(double input) {
  float finput = static_cast<float>(input);
  if (std::isnan(finput))
    return "nanf";
  if (std::isinf(finput))
    return (std::signbit(finput) ? "-inf" : "+inf");

  return std::nullopt;
};

std::optional<std::string> ScalarConverter::invalid_double(double input) {
  if (std::isnan(input))
    return "nan";
  if (std::isinf(input))
    return (std::signbit(input) ? "-inf" : "+inf");

  return std::nullopt;
};

std::optional<std::string> ScalarConverter::invalid_int(double input) {
  if (input < static_cast<double>(std::numeric_limits<int>::min()) ||
      input > static_cast<double>(std::numeric_limits<int>::max()))
    return "overflow";

  return std::nullopt;
};
