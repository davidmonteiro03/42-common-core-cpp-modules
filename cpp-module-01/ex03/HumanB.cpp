/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:50:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 09:14:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void) : __weapon(NULL),
					   __name("") {}

HumanB::HumanB(const std::string &name) : __weapon(NULL),
										  __name(name) {}

HumanB::HumanB(const HumanB &copy) : __weapon(copy.__weapon),
									 __name(copy.__name) {}

HumanB &HumanB::operator=(const HumanB &other)
{
	if (this != &other)
	{
		this->__weapon = other.__weapon;
		this->__name = other.__name;
	}
	return *this;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) { this->__weapon = &weapon; }

void HumanB::attack(void) const
{
	if (this->__weapon == NULL)
		return;
	std::cout << this->__name << " attacks with their " << this->__weapon->getType() << std::endl;
}
