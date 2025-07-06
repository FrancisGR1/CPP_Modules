#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

 public:
	 inline static constexpr std::string k_default_name = "form";

  AForm() = delete;
  explicit AForm(const std::string, const int, const int);
  AForm(const AForm&);
  AForm& operator=(const AForm&) = delete;
  virtual ~AForm();

  void beSigned(const Bureaucrat&);

  std::string getName() const { return m_name; }
  bool isSigned() const { return m_is_signed; }
  int getGradeNeededToSign() const { return m_grade_needed_to_sign; }
  int getGradeNeededToExec() const { return m_grade_needed_to_exec; }

  virtual void execute(const Bureaucrat& executor) const = 0;
  bool hasRequiredGrades(const Bureaucrat& executor) const;

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const noexcept override { return "Grade too high"; }
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const noexcept override { return "Grade too Low"; }
  };

  class GradeNotSignedException : public std::exception {
   public:
    const char* what() const noexcept override { return "Form not Signed"; }
  };

 private:
  const std::string m_name;
  bool m_is_signed;
  const int m_grade_needed_to_sign;
  const int m_grade_needed_to_exec;
};

std::ostream& operator<<(std::ostream&, AForm&);

#endif /*AFORM_HPP*/
