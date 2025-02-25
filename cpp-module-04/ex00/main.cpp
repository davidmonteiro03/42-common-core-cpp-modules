/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:25:24 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 23:24:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();

	delete cat;
	delete dog;
	delete animal;

	const WrongAnimal *wronganimal = new WrongAnimal();
	const WrongAnimal *wrongcat = new WrongCat();

	std::cout << wrongcat->getType() << std::endl;
	std::cout << wronganimal->getType() << std::endl;

	wrongcat->makeSound();
	wronganimal->makeSound();

	delete wrongcat;
	delete wronganimal;

	return 0;
}
