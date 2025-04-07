/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:08:08 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 17:12:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const unsigned int AForm::__HIGHEST_GRADE = 1;
const unsigned int AForm::__LOWEST_GRADE = 150;

AForm::AForm(void) : __name(""),
					 __isSigned(false),
					 __gradeToSign(AForm::__LOWEST_GRADE),
					 __gradeToExecute(AForm::__LOWEST_GRADE)
{
	AForm::__checkGrade(this->__gradeToSign);
	AForm::__checkGrade(this->__gradeToExecute);
}

AForm::AForm(const std::string &name,
			 const unsigned int &gradeToSign,
			 const unsigned int &gradeToExecute) : __name(name),
												   __isSigned(false),
												   __gradeToSign(gradeToSign),
												   __gradeToExecute(gradeToExecute)
{
	AForm::__checkGrade(this->__gradeToSign);
	AForm::__checkGrade(this->__gradeToExecute);
}

AForm::AForm(const AForm &copy) : __name(copy.__name),
								  __isSigned(false),
								  __gradeToSign(copy.__gradeToSign),
								  __gradeToExecute(copy.__gradeToExecute)
{
	AForm::__checkGrade(this->__gradeToSign);
	AForm::__checkGrade(this->__gradeToExecute);
}

AForm &AForm::operator=(const AForm &) { return *this; }

AForm::~AForm() {}

void AForm::__checkGrade(const unsigned int &grade)
{
	if (grade < AForm::__HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	if (grade > AForm::__LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

const std::string &AForm::getName(void) const { return this->__name; }

const bool &AForm::getIsSigned(void) const { return this->__isSigned; }

const unsigned int &AForm::getGradeToSign(void) const { return this->__gradeToSign; }

const unsigned int &AForm::getGradeToExecute(void) const { return this->__gradeToExecute; }

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->__gradeToSign)
		throw AForm::GradeTooLowException();
	this->__isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() { return "grade is too high"; }

const char *AForm::GradeTooLowException::what() const throw() { return "grade is too low"; }

const char *AForm::FormNotSignedException::what() const throw() { return "form is not signed"; }

std::ostream &operator<<(std::ostream &os, const AForm &f) { return os << f.getName()
																	   << " | grade to sign: " << f.getGradeToSign()
																	   << " | grade to execute: " << f.getGradeToExecute()
																	   << " | signed: " << (f.getIsSigned() == true ? "true" : "false") << "."; }
