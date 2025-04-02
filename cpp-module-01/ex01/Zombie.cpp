/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 07:51:01 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 08:21:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : __name("") {}

Zombie::Zombie(const std::string &name) : __name(name) {}

Zombie::Zombie(const Zombie &copy) : __name(copy.__name) {}

Zombie &Zombie::operator=(const Zombie &other)
{
	if (this != &other)
		this->__name = other.__name;
	return *this;
}

Zombie::~Zombie() { std::cout << "Zombie '" << this->__name << "' destroyed." << std::endl; }

const std::string &Zombie::getName(void) const { return this->__name; }

void Zombie::setName(const std::string &name) { this->__name = name; }

void Zombie::announce(void) { std::cout << this->__name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
