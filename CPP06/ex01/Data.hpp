#ifndef DATA_HPP
#define DATA_HPP

#include <cstdint>
#include <iostream>

struct Data {
  std::string name;
  std::string location;
};

inline void set_data(Data* d, const std::string& name,
                     const std::string& location) {
  if (!d)
    return;
  d->name = name;
  d->location = location;
};

#endif /*DATA_HPP*/
