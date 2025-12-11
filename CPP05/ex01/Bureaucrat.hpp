#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <sstream>

#include "Form.hpp"

const int MAX_GRADE = 1;
const int MIN_GRADE = 150;

class Form;

class Bureaucrat
{
	public: 
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(Form& f);

		class GradeTooHighException : public std::runtime_error
		{
			public:
				explicit GradeTooHighException(const std::string& name, const std::string& msg)
					: std::runtime_error(name + " couldn't sign form because: " +  msg) {}
		};

		class GradeTooLowException : public std::runtime_error
		{
			public:
				explicit GradeTooLowException(const std::string& name, const std::string& msg)
					: std::runtime_error(name + " couldn't sign form because: " +  msg) {}
		};


	private:
		const std::string m_name;
		int m_grade;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif /*BUREAUCRAT_HPP*/
