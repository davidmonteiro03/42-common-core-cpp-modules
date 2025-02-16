/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:10:50 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 23:11:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << std::endl
			  << "ClapTrap default constructor for " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	std::cout << std::endl
			  << "ClapTrap copy constructor for " << _name << " called" << std::endl;
	*this = ref;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << std::endl
			  << "ClapTrap assignment operator for " << _name << " called" << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << std::endl
			  << "ClapTrap destructor for " << _name << " called" << std::endl;
}

std::string ClapTrap::getName(void) const { return _name; }

int ClapTrap::getHitPoints(void) const { return _hitPoints; }

int ClapTrap::getEnergyPoints(void) const { return _energyPoints; }

int ClapTrap::getAttackDamage(void) const { return _attackDamage; }

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << std::endl
				  << "ClapTrap " << _name << " is dead!" << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << std::endl
				  << "ClapTrap " << _name << " has no energy points!" << std::endl;
		return;
	}
	std::cout << std::endl
			  << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << std::endl
				  << "ClapTrap " << _name << " is dead!" << std::endl;
		return;
	}
	std::cout << std::endl
			  << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " died!" << std::endl;
		_hitPoints = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
	{
		std::cout << std::endl
				  << "ClapTrap " << _name << " has no energy points!" << std::endl;
		return;
	}
	std::cout << std::endl
			  << "ClapTrap " << _name << " repaired " << amount << " points for itself!" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}
