#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{

	public:

		AForm();
		explicit AForm(const std::string, const int, const int);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		virtual ~AForm();

		void beSigned(const Bureaucrat&);

		std::string getName() const;
		bool isSigned() const;
		int getGradeNeededToSign() const;
		int getGradeNeededToExec() const;

		virtual void execute(const Bureaucrat& executor) const = 0;
		bool hasRequiredGrades(const Bureaucrat& executor) const;

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


			class GradeNotSignedException: public std::runtime_error
		{
			public:
				explicit GradeNotSignedException()
					: std::runtime_error("form is not signed") {}
		};

	private:
		const std::string m_name;
		bool m_is_signed;
		const int m_grade_needed_to_sign;
		const int m_grade_needed_to_exec;
};

std::ostream& operator<<(std::ostream&, AForm&);

#endif /*AFORM_HPP*/
