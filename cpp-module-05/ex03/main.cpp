/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/07 10:13:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

static void checkMakingForm(const std::string &formName,
							const std::string &formTarget)
{
	std::cout << "===== CHECK MAKE FORM FOR FORM NAME " << formName << " AND FORM TARGET " << formTarget << " =====" << std::endl;

	Intern ___i;

	AForm *___f = ___i.makeForm(formName, formTarget);

	std::cout << "Form PTR: " << ___f << std::endl
			  << std::endl;

	if (___f == NULL)
	{
		std::cerr << "Unknown form" << std::endl
				  << std::endl;
		return;
	}

	std::cout << "Form: " << *___f << std::endl
			  << std::endl;

	delete ___f;
}

int main(void)
{
	checkMakingForm("shrubbery creation", "___scf");
	checkMakingForm("robotomy request", "___rrf");
	checkMakingForm("presidential pardon", "___ppf");
	checkMakingForm("unknown", "___unknown");
	return 0;
}
