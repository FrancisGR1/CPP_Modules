#include "Serializer.hpp"

int main() {
  Data* person = new Data;
  set_data(person, "Raul", "Siberia");
  std::cout << "========= BEFORE ==========" << std::endl;
  std::cout << "Data: " << "name: " << person->name << std::endl
            << "location: " << person->location << std::endl;
  std::cout << "\n========= SERIALIZATION ==========" << std::endl;
  uintptr_t serialized = Serializer::serialize(person);
  std::cout << "Adress of original   data: " << person << std::endl;
  std::cout << "Adress of serialized data: " << serialized << std::endl;
  std::cout << "Adress of serialized data: " << std::hex << "0x" << serialized
            << std::endl;
  std::cout << "\n========= AFTER ==========" << std::endl;
  Data* deserialized = Serializer::deserialize(serialized);
  std::cout << "Data: " << "name: " << deserialized->name << std::endl
            << "location: " << deserialized->location << std::endl;
  delete person;
  return 0;
};
