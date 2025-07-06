#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

const int MAX_GRADE = 1;
const int MIN_GRADE = 150;

class AForm;

class Bureaucrat {
 public:
  Bureaucrat();
  Bureaucrat(const std::string name, int grade);
  Bureaucrat(Bureaucrat& other);
  Bureaucrat& operator=(Bureaucrat&) = delete;
  ~Bureaucrat();

  void signForm(AForm& document);
  void executeForm(const AForm& form);

  const std::string& getName() const { return m_name; }
  int getGrade() const { return m_grade; }

  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
   public:
    explicit GradeTooHighException() : m_msg("Grade Too High") {}

    const char* what() const noexcept override { return m_msg.c_str(); }

   private:
    const std::string m_msg;
  };

  class GradeTooLowException : public std::exception {
   public:
    explicit GradeTooLowException() : m_msg("Grade Too Low") {}

    const char* what() const noexcept override { return m_msg.c_str(); }

   private:
    const std::string m_msg;
  };

 private:
  const std::string m_name;
  int m_grade;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif /*BUREAUCRAT_HPP*/
