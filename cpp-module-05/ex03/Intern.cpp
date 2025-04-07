/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:33:59 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 10:01:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &) {}

Intern &Intern::operator=(const Intern &) { return *this; }

Intern::~Intern() {}

AForm *Intern::__newShrubberyCreationForm(const std::string &target) const { return new ShrubberyCreationForm(target); }

AForm *Intern::__newRobotomyRequestForm(const std::string &target) const { return new RobotomyRequestForm(target); }

AForm *Intern::__newPresidentialPardonForm(const std::string &target) const { return new PresidentialPardonForm(target); }

AForm *Intern::makeForm(const std::string &formName,
						const std::string &formTarget) const
{
	intern_form_t forms[3] = {(intern_form_t){.target = "shrubbery creation", .form = &Intern::__newShrubberyCreationForm},
							  (intern_form_t){.target = "robotomy request", .form = &Intern::__newRobotomyRequestForm},
							  (intern_form_t){.target = "presidential pardon", .form = &Intern::__newPresidentialPardonForm}};
	for (std::size_t i = 0; i < 3; i++)
		if (forms[i].target == formName)
			return (this->*forms[i].form)(formTarget);
	return NULL;
}
