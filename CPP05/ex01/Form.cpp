#include "Form.hpp"

Form::Form(std::string name, const int sign_required, const int exec_required)
	: m_name(name)
	, m_is_signed(false)
	, m_grade_needed_to_sign(sign_required)
	, m_grade_needed_to_exec(exec_required)
{
	if (m_grade_needed_to_sign < MAX_GRADE)
	{
		throw(GradeTooHighException("Signature requirement too high"));
	}
	if (m_grade_needed_to_exec < MAX_GRADE)
	{
		throw(GradeTooHighException("Execution requirement too high"));
	}
	if (m_grade_needed_to_sign > MIN_GRADE)
	{
		throw(GradeTooLowException("Signature requirement too low"));
	}
	if (m_grade_needed_to_exec > MIN_GRADE)
	{
		throw(GradeTooLowException("Execution requirement too high"));
	}
	std::cout << "<Form> " << m_name << " constroyed" << std::endl;
};

Form::Form(Form& other)
	: m_name(other.m_name)
	, m_is_signed(other.m_is_signed)
	, m_grade_needed_to_sign(other.m_grade_needed_to_sign)
	, m_grade_needed_to_exec(other.m_grade_needed_to_exec)
{
	if (m_grade_needed_to_sign < MAX_GRADE)
	{
		throw(GradeTooHighException("Signature requirement too high"));
	}
	if (m_grade_needed_to_exec < MAX_GRADE)
	{
		throw(GradeTooHighException("Execution requirement too high"));
	}
	if (m_grade_needed_to_sign > MIN_GRADE)
	{
		throw(GradeTooLowException("Signature requirement too low"));
	}
	if (m_grade_needed_to_exec > MIN_GRADE)
	{
		throw(GradeTooLowException("Execution requirement too high"));
	}
	std::cout << "<Form> " << m_name << " copied" << std::endl;
};

Form& Form::operator=(Form& other)
{
	m_is_signed = other.m_is_signed;
	return *this;
}

Form::~Form()
{
	std::cout << "<Form> " << m_name << " destroyed" << std::endl;
};

std::string Form::getName() const { return m_name; }
bool Form::isSigned() const { return m_is_signed; }
int Form::getGradeNeededToSign() const { return m_grade_needed_to_sign; }
int Form::getGradeNeededToExec() const { return m_grade_needed_to_exec; }

void Form::beSigned(Bureaucrat& b)
{
	int sign_req = m_grade_needed_to_sign;
	int grade = b.getGrade();

	if (grade > sign_req)
	{
		throw(GradeTooLowException(b.getName(), "Grade too low"));
	}
	if (grade < MAX_GRADE)
	{
		throw(GradeTooHighException(b.getName(), "Grade too high"));
	}

	m_is_signed = true;
	std::cout << b.getName() << " signed " << m_name << "\n";
};

std::ostream& operator<<(std::ostream& os, Form& form)
{
	os << "form info: "
		<< "\n\t" << form.getName() << " signed: " <<  std::boolalpha << form.isSigned()
		<< "\n\t" << "Need " << form.getGradeNeededToSign() << " to sign"
		<< "\n\t" << "Need " << form.getGradeNeededToExec() << " to execute";
	return os;
};
