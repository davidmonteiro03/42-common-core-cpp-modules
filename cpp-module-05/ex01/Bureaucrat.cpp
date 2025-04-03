/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:28:35 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 17:00:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const unsigned int Bureaucrat::__HIGHEST_GRADE = 1;
const unsigned int Bureaucrat::__LOWEST_GRADE = 150;

Bureaucrat::Bureaucrat(void) : __name(""),
							   __grade(Bureaucrat::__LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const std::string &name,
					   const unsigned int &grade) : __name(name),
													__grade(grade) { Bureaucrat::__checkGrade(this->__grade); }

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : __name(copy.__name),
												 __grade(copy.__grade) { Bureaucrat::__checkGrade(this->__grade); }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		Bureaucrat::__checkGrade(other.__grade);
		this->__grade = other.__grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::__checkGrade(const unsigned int &grade)
{
	if (grade < Bureaucrat::__HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > Bureaucrat::__LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

const std::string &Bureaucrat::getName(void) const { return this->__name; }

const unsigned int &Bureaucrat::getGrade(void) const { return this->__grade; }

void Bureaucrat::incrementGrade(void)
{
	Bureaucrat::__checkGrade(this->__grade - 1);
	this->__grade--;
}

void Bureaucrat::decrementGrade(void)
{
	Bureaucrat::__checkGrade(this->__grade + 1);
	this->__grade++;
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->__name << " signed " << f.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << this->__name << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "grade is too high"; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "grade is too low"; }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) { return os << b.getName() << ", bureaucrat grade "
																			<< b.getGrade() << "."; }
