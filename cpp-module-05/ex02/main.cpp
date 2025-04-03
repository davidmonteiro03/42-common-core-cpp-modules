/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 18:17:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int main(void)
{
	AForm *scf = new ShrubberyCreationForm("home");

	Bureaucrat ___b1("___b1", 1);
	___b1.signForm(*scf);
	___b1.executeForm(*scf);

	delete scf;

	return 0;
}
