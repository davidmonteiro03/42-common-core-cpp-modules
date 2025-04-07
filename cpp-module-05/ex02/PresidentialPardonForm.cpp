/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:38:03 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 08:58:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const unsigned int PresidentialPardonForm::__GRADE_TO_SIGN = 25;
const unsigned int PresidentialPardonForm::__GRADE_TO_EXECUTE = 5;

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("",
															 PresidentialPardonForm::__GRADE_TO_SIGN,
															 PresidentialPardonForm::__GRADE_TO_EXECUTE),
													   __target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target,
																				  PresidentialPardonForm::__GRADE_TO_SIGN,
																				  PresidentialPardonForm::__GRADE_TO_EXECUTE),
																			__target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy),
																					 __target(copy.__target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		this->__target = other.__target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToSign() || executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->__target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
