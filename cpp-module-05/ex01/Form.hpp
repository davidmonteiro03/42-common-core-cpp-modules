/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:59:18 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 17:00:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(const std::string &,
		 const unsigned int &,
		 const unsigned int &);
	Form(const Form &);
	Form &operator=(const Form &);
	~Form();

	const std::string &getName(void) const;
	const bool &getIsSigned(void) const;
	const unsigned int &getGradeToSign(void) const;
	const unsigned int &getGradeToExecute(void) const;

	void beSigned(Bureaucrat &);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	static const unsigned int __HIGHEST_GRADE;
	static const unsigned int __LOWEST_GRADE;
	const std::string __name;
	bool __isSigned;
	const unsigned int __gradeToSign;
	const unsigned int __gradeToExecute;

	static void __checkGrade(const unsigned int &);
};

std::ostream &operator<<(std::ostream &, const Form &);
