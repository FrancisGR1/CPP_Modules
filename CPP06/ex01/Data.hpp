#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data 
{
  std::string name;
  std::string location;

  void set_name(const std::string& str);
  void set_location(const std::string& str);
};

#endif /*DATA_HPP*/
