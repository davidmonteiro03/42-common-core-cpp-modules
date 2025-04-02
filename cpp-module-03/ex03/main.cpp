/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 16:25:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	{
		DiamondTrap unknown;
		DiamondTrap test("test");
		DiamondTrap copy(unknown);
		std::cout << std::endl;

		copy = test;
		std::cout << std::endl;

		test.attack("clap");
		std::cout << std::endl;

		test.takeDamage(5);
		std::cout << std::endl;

		test.beRepaired(5);
		std::cout << std::endl;

		test.guardGate();
		std::cout << std::endl;

		test.highFivesGuys();
		std::cout << std::endl;

		unknown.whoAmI();
		std::cout << std::endl;

		copy.whoAmI();
		std::cout << std::endl;

		test.whoAmI();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// Do whatever you want ...

	return 0;
}
