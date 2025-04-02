/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 15:46:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	{
		ClapTrap unknown;
		ClapTrap test("test");
		ClapTrap copy(unknown);
		std::cout << std::endl;

		copy = test;
		std::cout << std::endl;

		test.attack("clap");
		std::cout << std::endl;

		test.takeDamage(5);
		std::cout << std::endl;

		test.beRepaired(5);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// Do whatever you want ...

	return 0;
}
