/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:08:08 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 17:00:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const unsigned int Form::__HIGHEST_GRADE = 1;
const unsigned int Form::__LOWEST_GRADE = 150;

Form::Form(void) : __name(""),
				   __isSigned(false),
				   __gradeToSign(Form::__LOWEST_GRADE),
				   __gradeToExecute(Form::__LOWEST_GRADE)
{
	Form::__checkGrade(this->__gradeToSign);
	Form::__checkGrade(this->__gradeToExecute);
}

Form::Form(const std::string &name,
		   const unsigned int &gradeToSign,
		   const unsigned int &gradeToExecute) : __name(name),
												 __isSigned(false),
												 __gradeToSign(gradeToSign),
												 __gradeToExecute(gradeToExecute)
{
	Form::__checkGrade(this->__gradeToSign);
	Form::__checkGrade(this->__gradeToExecute);
}

Form::Form(const Form &copy) : __name(copy.__name),
							   __isSigned(false),
							   __gradeToSign(copy.__gradeToSign),
							   __gradeToExecute(copy.__gradeToExecute)
{
	Form::__checkGrade(this->__gradeToSign);
	Form::__checkGrade(this->__gradeToExecute);
}

Form &Form::operator=(const Form &) { return *this; }

Form::~Form() {}

void Form::__checkGrade(const unsigned int &grade)
{
	if (grade < Form::__HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (grade > Form::__LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

const std::string &Form::getName(void) const { return this->__name; }

const bool &Form::getIsSigned(void) const { return this->__isSigned; }

const unsigned int &Form::getGradeToSign(void) const { return this->__gradeToSign; }

const unsigned int &Form::getGradeToExecute(void) const { return this->__gradeToExecute; }

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->__gradeToSign)
		throw Form::GradeTooLowException();
	this->__isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() { return "grade is too high"; }

const char *Form::GradeTooLowException::what() const throw() { return "grade is too low"; }

std::ostream &operator<<(std::ostream &os, const Form &f) { return os << f.getName()
																	  << " | grade to sign: " << f.getGradeToSign()
																	  << " | grade to execute: " << f.getGradeToExecute()
																	  << " | signed: " << (f.getIsSigned() == true ? "true" : "false") << "."; }
