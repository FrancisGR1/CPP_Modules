#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <random>

class Base {
 public:
  virtual ~Base() = default;
  static Base* generate();
  static void identify(Base* p);
  static void identify(Base& p);

 private:
};

#endif /*BASE_HPP*/
