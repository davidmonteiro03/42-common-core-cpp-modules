/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:28:15 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 23:25:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") { std::cout << this->_type << " created" << std::endl; }

WrongAnimal::WrongAnimal(std::string type) : _type(type) { std::cout << "Default WrongAnimal " << this->_type << " created" << std::endl; }

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal " << this->_type << " destroyed" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	std::cout << "WrongAnimal " << ref._type << " copied to a new animal" << std::endl;
	*this = ref;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "WrongAnimal " << rhs._type << " changed its value" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

void WrongAnimal::makeSound(void) const { std::cout << "What is WrongAnimal " << this->getType() << " saying??? (you're not even an animal)" << std::endl; }

std::string WrongAnimal::getType(void) const { return this->_type; }
