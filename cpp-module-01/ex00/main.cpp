/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:40:37 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 21:52:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie stack_zombie("Stack Zombie");
	Zombie *heap_zombie = newZombie("Heap Zombie");

	randomChump("Random Chump Zombie");
	delete heap_zombie;
	return 0;
}
