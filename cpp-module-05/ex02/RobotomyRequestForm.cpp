/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:38:03 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 08:56:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const unsigned int RobotomyRequestForm::__GRADE_TO_SIGN = 72;
const unsigned int RobotomyRequestForm::__GRADE_TO_EXECUTE = 45;

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("",
													   RobotomyRequestForm::__GRADE_TO_SIGN,
													   RobotomyRequestForm::__GRADE_TO_EXECUTE),
												 __target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target,
																			RobotomyRequestForm::__GRADE_TO_SIGN,
																			RobotomyRequestForm::__GRADE_TO_EXECUTE),
																	  __target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy),
																			__target(copy.__target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->__target = other.__target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	std::srand(std::time(NULL));
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToSign() || executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->__target << (std::rand() % 2 == true ? " has been robotomized" : " robotomy failed") << std::endl;
}
