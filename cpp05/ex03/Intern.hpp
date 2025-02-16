/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:25:57 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/16 08:48:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
public:
	Intern();
	Intern(const Intern &);
	Intern &operator=(const Intern &);
	~Intern();
	Form *makeForm(std::string, std::string);
	class ErrorCreatingFormException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
