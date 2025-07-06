#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:

  inline static constexpr int k_grade_to_sign = 72;
  inline static constexpr int k_grade_to_exec = 45;

  explicit RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm&) = default;
  RobotomyRequestForm& operator=(const RobotomyRequestForm&) = delete;
  ~RobotomyRequestForm();

  void execute(const Bureaucrat& executor) const override;

 private:
  const std::string m_target;
};

#endif /*ROBOTOMYREQUESTFORM_HPP*/
