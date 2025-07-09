#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
  return std::bit_cast<uintptr_t>(ptr);
};

Data* Serializer::deserialize(uintptr_t raw) {
  return std::bit_cast<Data*>(raw);
};
