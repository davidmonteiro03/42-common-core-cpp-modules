/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:30:49 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/16 08:47:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy) { (void)copy; }

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

static Form *new_shrubbery(std::string target) { return new ShrubberyCreationForm(target); }

static Form *new_robotmy(std::string target) { return new RobotomyRequestForm(target); }

static Form *new_presidential(std::string target) { return new PresidentialPardonForm(target); }

Form *Intern::makeForm(std::string form_name, std::string form_target)
{
	Form *(*func[3])(std::string target) = {new_shrubbery, new_robotmy, new_presidential};
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *ret = NULL;
	int i;
	for (i = 0; i < 3; i++)
		if (form_name == names[i])
			ret = func[i](form_target);
	if (ret)
		std::cout << "Intern creates " << *ret;
	else
		throw ErrorCreatingFormException();
	return ret;
}

const char *Intern::ErrorCreatingFormException::what() const throw() { return "Intern: ErrorCreatingFormException"; }
