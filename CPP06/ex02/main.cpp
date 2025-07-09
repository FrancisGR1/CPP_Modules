#include "Base.hpp"

int main() {
  Base* random = Base::generate();
  Base::identify(random);
  Base* random2 = Base::generate();
  Base::identify(*random2);
  delete random;
  delete random2;
  return 0;
};
