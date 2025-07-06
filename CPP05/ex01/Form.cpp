#include "Form.hpp"

Form::Form(std::string name, const int sign_required, const int exec_required)
	: m_name(name)
	, m_is_signed(false)
	, m_grade_needed_to_sign(sign_required)
	  , m_grade_needed_to_exec(exec_required)
{
	if (m_grade_needed_to_sign < MAX_GRADE || m_grade_needed_to_exec < MAX_GRADE)
	{
		throw(GradeTooHighException());
	}
	if (m_grade_needed_to_sign > MIN_GRADE || m_grade_needed_to_exec > MIN_GRADE)
	{
		throw(GradeTooLowException());
	}
	std::cout << "<Form> " << m_name << " constroyed" << std::endl;
};

Form::Form(Form& other)
	: m_name(other.m_name)
	, m_is_signed(other.m_is_signed)
	, m_grade_needed_to_sign(other.m_grade_needed_to_sign)
	  , m_grade_needed_to_exec(other.m_grade_needed_to_exec)
{
	if (m_grade_needed_to_sign < MAX_GRADE || m_grade_needed_to_exec < MAX_GRADE)
	{
		throw(GradeTooHighException());
	}
	if (m_grade_needed_to_sign > MIN_GRADE || m_grade_needed_to_exec > MIN_GRADE)
	{
		throw(GradeTooLowException());
	}
	std::cout << "<Form> " << m_name << " copied" << std::endl;
};

Form::~Form()
{
	std::cout << "<Form> " << m_name << " destroyed" << std::endl;
};

void Form::beSigned(Bureaucrat& b)
{
	int sign_req = m_grade_needed_to_sign;
	int grade = b.getGrade();

	if (grade > sign_req)
	{
		throw(GradeTooLowException());
	}
	if (grade < MAX_GRADE)
	{
		throw(GradeTooHighException());
	}
	m_is_signed = true;

};

std::ostream& operator<<(std::ostream& os, Form& form)
{
	os << "form info: "
		<< std::endl 
		<< form.getName() << " signed: " <<  std::boolalpha << form.isSigned()
		<< std::endl << "Need " << form.getGradeNeededToSign() << " to sign"
		<< std::endl << "Need " << form.getGradeNeededToExec() << " to execute";
	return os;
};
