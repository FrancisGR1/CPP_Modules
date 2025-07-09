#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* Base::generate() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<> dist(0, 2);

  switch (dist(gen)) {
    case 0:
      return new A();
    case 1:
      return new B();
    default:
      return new C();
  }
}

void Base::identify(Base* p) {
  std::cout << "Base* p\n";
  if (dynamic_cast<A*>(p))
    std::cout << "A\n";
  else if (dynamic_cast<B*>(p))
    std::cout << "B\n";
  else if (dynamic_cast<C*>(p))
    std::cout << "C\n";
  else
    std::cout << "Unknown type\n";
};

void Base::identify(Base& p) {
  std::cout << "Base& p\n";
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A\n";
  } catch (...) {}

  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B\n";
  } catch (...) {}

  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C\n";
  } catch (...) {}
};
