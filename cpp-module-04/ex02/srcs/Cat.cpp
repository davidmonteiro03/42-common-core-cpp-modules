/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:12:15 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 09:08:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal("Cat") { this->__brain = new Brain(); }

Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->__brain = new Brain();
	*this->__brain = *copy.__brain;
}

Cat &Cat::operator=(const Cat &other)
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

Cat::~Cat() { delete this->__brain; }

void Cat::makeSound(void) const { std::cout << "miau miau" << std::endl; }
