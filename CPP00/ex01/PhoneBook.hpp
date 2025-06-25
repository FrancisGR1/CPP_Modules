#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

const size_t MAX = 8;

struct Info 
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phonenumber;
	std::string secret;
};


class PhoneBook
{
	public:
		PhoneBook();
		bool add();
		bool display() const;
	private:
		Info contacts[MAX];
		size_t idx;
};


//utils
bool is_num(const std::string& str);
bool get_num(Info& contact);
bool is_alpha(const std::string& str);
bool get_name(std::string& name, const std::string& prompt);
std::string to_string(size_t i);
int string_to_int(const std::string& str);
void print_format(const std::string& str);

#endif /*PHONEBOOK_HPP*/
