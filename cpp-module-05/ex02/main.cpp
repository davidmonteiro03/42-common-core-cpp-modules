/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 10:10:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <sstream>

static void checkSigningAndExecuting(const unsigned int &grade)
{
	std::cout << "===== CHECK SIGN AND EXECUTE FOR " << grade << " =====" << std::endl;

	std::stringstream gradeSs;
	gradeSs << grade;
	std::string gradeStr = gradeSs.str();

	Bureaucrat ___b("___b" + gradeStr, grade);

	AForm *___scf = new ShrubberyCreationForm("___scf" + gradeStr);
	AForm *___rrf = new RobotomyRequestForm("___rrf" + gradeStr);
	AForm *___ppf = new PresidentialPardonForm("___ppf" + gradeStr);

	std::cout << "Bureaucrat: " << ___b << std::endl
			  << "ShrubberyCreationForm: " << *___scf << std::endl
			  << "RobotomyRequestForm: " << *___rrf << std::endl
			  << "PresidentialPardonForm: " << *___ppf << std::endl
			  << std::endl;

	___b.executeForm(*___scf);
	___b.executeForm(*___rrf);
	___b.executeForm(*___ppf);
	std::cout << std::endl;

	___b.signForm(*___scf);
	___b.signForm(*___rrf);
	___b.signForm(*___ppf);
	std::cout << std::endl;

	___b.executeForm(*___scf);
	___b.executeForm(*___rrf);
	___b.executeForm(*___ppf);
	std::cout << std::endl;

	delete ___ppf;
	delete ___rrf;
	delete ___scf;
}

int main(void)
{
	unsigned int start = 150;
	while (true)
	{
		try
		{
			checkSigningAndExecuting(start--);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
			break;
		}
	}
	std::cout << std::endl;
	return 0;
}
