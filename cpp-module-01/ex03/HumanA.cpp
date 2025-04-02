/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:50:25 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 09:14:26 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon &weapon) : __weapon(weapon),
								 __name("") {}

HumanA::HumanA(const std::string &name,
			   Weapon &weapon) : __weapon(weapon),
								 __name(name) {}

HumanA::HumanA(const HumanA &copy) : __weapon(copy.__weapon),
									 __name(copy.__name) {}

HumanA &HumanA::operator=(const HumanA &other)
{
	if (this != &other)
	{
		this->__weapon = other.__weapon;
		this->__name = other.__name;
	}
	return *this;
}

HumanA::~HumanA() {}

void HumanA::attack(void) const { std::cout << this->__name << " attacks with their " << this->__weapon.getType() << std::endl; }
