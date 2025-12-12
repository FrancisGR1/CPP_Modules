#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data 
{
  std::string name;
  std::string location;
};

void set_data(Data* d, const std::string& name, const std::string& location);

#endif /*DATA_HPP*/
