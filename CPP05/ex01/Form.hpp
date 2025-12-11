#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		explicit Form(std::string, const int, const int);
		Form(Form& other);
		Form& operator=(Form& other);
		~Form();

		void beSigned(Bureaucrat& b);
		std::string getName() const;
		bool isSigned() const;
		int getGradeNeededToSign() const;
		int getGradeNeededToExec() const;

		class GradeTooHighException : public std::runtime_error
		{
			public:
				explicit GradeTooHighException(const std::string& msg)
					: std::runtime_error(msg) {}
				GradeTooHighException(const std::string& name, const std::string& msg)
					: std::runtime_error(name + " couldn't sign form because: " +  msg) {}
		};

		class GradeTooLowException : public std::runtime_error
		{
			public:
				explicit GradeTooLowException(const std::string& msg)
					: std::runtime_error(msg) {}
				GradeTooLowException(const std::string& name, const std::string& msg)
					: std::runtime_error(name + " couldn't sign form because: " +  msg) {}
		};

	private:
		const std::string m_name;
		bool m_is_signed;
		const int m_grade_needed_to_sign;
		const int m_grade_needed_to_exec;
};

std::ostream& operator<<(std::ostream&, Form&);

#endif /*FORM_HPP*/
