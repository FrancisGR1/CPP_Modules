#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "<Intern> constroyed" << std::endl;
};

Intern::~Intern()
{
	std::cout << "<Intern> destroyed" << std::endl;
};

AForm* Intern::makeForm(const std::string& form_type, const std::string& target)
{
	static const std::string form_types[] = {"presidentialpardon", "robotomyrequest", "shrubberycreation"}; 

	int idx = -1;
	for (int i = 0; i < 3; i++) {
		if (looselyMatches(form_types[i], form_type)){
			idx = i;
			break ;
		}
	};
	switch (idx) {
		case 0:
			return (new PresidentialPardonForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			throw WrongFormFormat();
	};
};

std::string Intern::normalize(const std::string& input)
{
	std::string normalized;

	for (char c : input) {
		unsigned char uc(static_cast<unsigned char>(c));
		if (!std::isspace(uc)) {
			normalized += std::tolower(uc);
		}
	}
	return (normalized);
};

bool Intern::looselyMatches(const std::string& s1, const std::string& s2)
{
	return (normalize(s1) == normalize(s2));
};
