#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();

		AForm* makeForm(const std::string& form_type, const std::string& target_name);
		class WrongFormFormat : public std::runtime_error 
		{
			public:
				explicit WrongFormFormat()
					: std::runtime_error("Wrong form format") {}
		};

	private:
		std::string normalize(const std::string&);
		bool looselyMatches(const std::string&, const std::string&);
};

#endif /*INTERN_HPP*/
