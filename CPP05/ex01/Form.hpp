#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form() = delete;
		explicit Form(std::string, const int, const int);
		Form(Form&);
		Form& operator=(Form&) = delete;
		~Form();

		void beSigned(Bureaucrat&);

		std::string getName() const { return m_name; }
		bool isSigned() const { return m_is_signed; }
		int getGradeNeededToSign() const { return m_grade_needed_to_sign; }
		int getGradeNeededToExec() const { return m_grade_needed_to_exec; }

		class GradeTooHighException : public std::exception
		{
			public:
				explicit GradeTooHighException()
					: m_msg("Grade Too High") {}
				const char* what() const noexcept override { return m_msg.c_str(); }
			private:
				const std::string m_msg;

		};

		class GradeTooLowException : public std::exception
		{
			public:
				explicit GradeTooLowException()
					: m_msg("Grade Too Low") {}
				const char* what() const noexcept override { return m_msg.c_str(); }
			private:
				const std::string m_msg;

		};

	private:
		const std::string m_name;
		bool m_is_signed;
		const int m_grade_needed_to_sign;
		const int m_grade_needed_to_exec;
};

std::ostream& operator<<(std::ostream&, Form&);

#endif /*FORM_HPP*/
