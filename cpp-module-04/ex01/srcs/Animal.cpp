/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:12:15 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 08:34:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(void) : _type("") {}

Animal::Animal(const std::string &type) : _type(type) {}

Animal::Animal(const Animal &copy) : _type(copy._type) {}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Animal::~Animal() {}

const std::string &Animal::getType(void) const { return this->_type; }

void Animal::setType(const std::string &type) { this->_type = type; }

void Animal::makeSound(void) const { std::cout << "sound of unknown Animal" << std::endl; }
