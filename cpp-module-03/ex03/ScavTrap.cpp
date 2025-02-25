/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:07:54 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 23:18:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << std::endl
			  << "ScavTrap default constructor for " << _name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref._name)
{
	std::cout << std::endl
			  << "ScavTrap copy constructor for " << _name << " called" << std::endl;
	*this = ref;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << std::endl
			  << "ScavTrap assignment operator for " << _name << " called" << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << std::endl
			  << "ScavTrap destructor for " << _name << " called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energyPoints <= 0)
	{
		std::cout << std::endl
				  << "ScavTrap " << _name << " has no energy points!" << std::endl;
		return;
	}
	if (_hitPoints <= 0)
	{
		std::cout << std::endl
				  << "ScavTrap " << _name << " is dead!" << std::endl;
		return;
	}
	std::cout << std::endl
			  << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << std::endl
			  << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
	_energyPoints = 50;
}
