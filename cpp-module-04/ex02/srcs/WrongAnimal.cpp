/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:12:15 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 08:36:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("") {}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {}

const std::string &WrongAnimal::getType(void) const { return this->_type; }

void WrongAnimal::setType(const std::string &type) { this->_type = type; }

void WrongAnimal::makeSound(void) const { std::cout << "sound of unknown WrongAnimal" << std::endl; }
