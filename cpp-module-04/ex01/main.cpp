/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:27:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 09:16:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"

int main(void)
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;
	delete i;

	static const std::size_t nAnimals = 10;

	Animal **animals = new Animal *[nAnimals];
	for (std::size_t i = 0; i < nAnimals; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (std::size_t i = 0; i < nAnimals; i++)
		animals[i]->makeSound();

	for (std::size_t i = 0; i < nAnimals; i++)
		delete animals[i];

	delete[] animals;

	return 0;
}
