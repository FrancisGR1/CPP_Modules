#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  inline static constexpr int k_grade_to_sign = 25;
  inline static constexpr int k_grade_to_exec = 5;

  explicit PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm&) = default;
  PresidentialPardonForm& operator=(const PresidentialPardonForm&) = delete;
  ~PresidentialPardonForm();

  void execute(const Bureaucrat& executor) const override;

 private:
  const std::string m_target;
};

#endif /*PRESIDENTIALPARDONFORM_HPP*/
