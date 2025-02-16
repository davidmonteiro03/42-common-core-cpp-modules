/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:52:44 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 23:13:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << std::endl
			  << "DiamondTrap default constructor for " << _name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref._name), ScavTrap(ref._name), FragTrap(ref._name)
{
	std::cout << std::endl
			  << "DiamondTrap copy constructor for " << _name << " called" << std::endl;
	*this = ref;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << std::endl
			  << "DiamondTrap assignment operator for " << _name << " called" << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << std::endl
			  << "DiamondTrap destructor for " << _name << " called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) { ScavTrap::attack(target); }

void DiamondTrap::whoAmI()
{
	std::string tmp = _name;
	// std::string tmp = ClapTrap::_name;
	if (_hitPoints <= 0)
	{
		std::cout << std::endl
				  << "DiamondTrap " << tmp << " is dead!" << std::endl;
		return;
	}
	std::cout << std::endl
			  << "DiamondTrap " << tmp << " is here" << std::endl;
}
