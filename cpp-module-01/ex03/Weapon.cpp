/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:47:09 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 09:14:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : __type("") {}

Weapon::Weapon(const std::string &type) : __type(type) {}

Weapon::Weapon(const Weapon &copy) : __type(copy.__type) {}

Weapon &Weapon::operator=(const Weapon &other)
{
	if (this != &other)
		this->__type = other.__type;
	return *this;
}

Weapon::~Weapon() {}

const std::string &Weapon::getType(void) const { return this->__type; }

void Weapon::setType(const std::string &type) { this->__type = type; }
