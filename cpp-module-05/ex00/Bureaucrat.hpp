/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:28:35 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 16:59:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(const std::string &,
			   const unsigned int &);
	Bureaucrat(const Bureaucrat &);
	Bureaucrat &operator=(const Bureaucrat &);
	~Bureaucrat();

	const std::string &getName(void) const;
	const unsigned int &getGrade(void) const;

	void incrementGrade(void);
	void decrementGrade(void);

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
	unsigned int __grade;

	static void __checkGrade(const unsigned int &);
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);
