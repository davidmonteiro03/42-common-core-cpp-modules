/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:39:09 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/24 08:28:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _status;
	const int _signGrade;
	const int _execGrade;

public:
	Form();
	Form(const std::string, const int, const int);
	Form(const Form &);
	Form &operator=(const Form &);
	virtual ~Form();
	const std::string getName(void) const;
	bool getStatus(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	virtual void execute(Bureaucrat const &) const = 0;
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
	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class UnsignedFormException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	void beSigned(Bureaucrat &);
};

std::ostream &operator<<(std::ostream &, const Form &);
