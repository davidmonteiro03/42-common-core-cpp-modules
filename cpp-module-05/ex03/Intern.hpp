/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:33:59 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 09:53:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern &);
	Intern &operator=(const Intern &);
	~Intern();

	AForm *makeForm(const std::string &,
					const std::string &) const;

private:
	AForm *__newShrubberyCreationForm(const std::string &) const;
	AForm *__newRobotomyRequestForm(const std::string &) const;
	AForm *__newPresidentialPardonForm(const std::string &) const;
};

typedef struct s_intern_form
{
	std::string target;
	AForm *(Intern::*form)(const std::string &) const;
} intern_form_t;
