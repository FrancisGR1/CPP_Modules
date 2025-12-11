#include "AForm.hpp"

AForm::AForm()
    	: m_name("default name")
	, m_is_signed(false)
	, m_grade_needed_to_sign(20)
	, m_grade_needed_to_exec(20) 
{}

AForm::AForm(std::string name, const int sign_required, const int exec_required)
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
	std::cout << "<AForm> " << m_name << " constroyed\n";
};

AForm::AForm(const AForm& other)
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
	std::cout << "<AForm> " << m_name << " copied\n";
};

AForm& AForm::operator=(const AForm& other)
{
	m_is_signed = other.m_is_signed;
	return *this;
}

AForm::~AForm()
{
  std::cout << "<AForm> " << m_name << " destroyed" << std::endl;
};

void AForm::beSigned(const Bureaucrat& b)
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

std::string AForm::getName() const { return m_name; };
bool AForm::isSigned() const { return m_is_signed; };
int AForm::getGradeNeededToSign() const { return m_grade_needed_to_sign; };
int AForm::getGradeNeededToExec() const { return m_grade_needed_to_exec; };

bool AForm::hasRequiredGrades(const Bureaucrat& executor) const 
{
	return (executor.getGrade() <= getGradeNeededToSign() &&
			executor.getGrade() <= getGradeNeededToExec());
};

std::ostream& operator<<(std::ostream& os, AForm& form) 
{
	os << "\n----------\nForm Info: " << std::endl
		<< form.getName() << " signed: " << std::boolalpha << form.isSigned()
		<< std::endl
		<< "Need " << form.getGradeNeededToSign() << " to sign" << std::endl
		<< "Need " << form.getGradeNeededToExec() << " to execute\n----------\n";
	return os;
};
