#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern&) = delete;
		Intern& operator=(const Intern&) = delete;
		~Intern();

		AForm* makeForm(const std::string& form_type, const std::string& target_name);
		class WrongFormFormat : public std::exception {
			public:
				const char* what() const noexcept override { return "Wrong form format"; }

		};

	private:
		std::string normalize(const std::string&);
		bool looselyMatches(const std::string&, const std::string&);
};

#endif /*INTERN_HPP*/
