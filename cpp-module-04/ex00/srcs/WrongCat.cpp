/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:12:15 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 08:41:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

WrongCat::~WrongCat() {}

void WrongCat::makeSound(void) const { std::cout << "meow meow" << std::endl; }
