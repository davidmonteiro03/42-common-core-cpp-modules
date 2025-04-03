/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:31:11 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 11:46:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/interface.hpp"

Character::Character(void) { std::memset(this->__inventory, 0, sizeof(this->__inventory)); }

Character::Character(const std::string &name) : __name(name) { std::memset(this->__inventory, 0, sizeof(this->__inventory)); }

Character::Character(const Character &copy) : __name(copy.__name) { std::memcpy(this->__inventory, copy.__inventory, sizeof(this->__inventory)); }

Character &Character::operator=(const Character &) { return *this; }

Character::~Character()
{
	for (std::size_t i = 0; i < Character::__MAX_SLOTS; i++)
		if (this->__inventory[i] != NULL)
			delete this->__inventory[i];
}

const std::string &Character::getName(void) const { return this->__name; }

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return;
	for (std::size_t i = 0; i < Character::__MAX_SLOTS; i++)
	{
		if (this->__inventory[i] == NULL)
		{
			this->__inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > static_cast<int>(Character::__MAX_SLOTS))
		return;
	if (this->__inventory[idx] != NULL)
		this->__inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > static_cast<int>(Character::__MAX_SLOTS))
		return;
	if (this->__inventory[idx] == NULL)
		return;
	this->__inventory[idx]->use(target);
}
