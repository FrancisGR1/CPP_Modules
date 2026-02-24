#include "Serializer.hpp"

int main() 
{
	// allocate
	Data* person = new Data;
	person->set_name("Raul");
	person->set_location("Siberia");

	std::cout << "========= BEFORE ==========" << std::endl;
	std::cout << "Data:\n" << "\tname: " << person->name << std::endl
		<< "\tlocation: " << person->location << std::endl;

	std::cout << "\n========= SERIALIZATION ==========" << std::endl;
	uintptr_t serialized = Serializer::serialize(person);
	std::cout << "Adress of original   data: " << person << std::endl;
	std::cout << "Adress of serialized data: " << serialized << std::endl;
	std::cout << "Adress of serialized data: " << std::hex << "0x" << serialized
		<< std::endl;

	std::cout << "\n========= AFTER ==========" << std::endl;
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Data:\n" << "\tname: " << deserialized->name << std::endl
		<< "\tlocation: " << deserialized->location << std::endl;

	delete person;
	return 0;
};
