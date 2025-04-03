/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:12:15 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 09:08:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void) : Animal("Dog") { this->__brain = new Brain(); }

Dog::Dog(const Dog &copy) : Animal(copy)
{
	this->__brain = new Brain();
	*this->__brain = *copy.__brain;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		delete this->__brain;
		this->__brain = new Brain();
		*this->__brain = *other.__brain;
	}
	return *this;
}

Dog::~Dog() { delete this->__brain; }

void Dog::makeSound(void) const { std::cout << "woof woof" << std::endl; }
