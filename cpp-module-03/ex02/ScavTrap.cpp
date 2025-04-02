/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:05:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 16:18:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->__hitPoints = ScavTrap::_hitPoints;
	this->__energyPoints = ScavTrap::_energyPoints;
	this->__attackDamage = ScavTrap::_attackDamage;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap std::string constructor called" << std::endl;
	this->__hitPoints = ScavTrap::_hitPoints;
	this->__energyPoints = ScavTrap::_energyPoints;
	this->__attackDamage = ScavTrap::_attackDamage;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) { std::cout << "ScavTrap copy constructor called" << std::endl; }

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->__name = other.__name;
		this->__hitPoints = other.__hitPoints;
		this->__energyPoints = other.__energyPoints;
		this->__attackDamage = other.__attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

void ScavTrap::attack(const std::string &target)
{
	if (this->__hitPoints == 0 || this->__energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->__name << " has no hit points or energy points left." << std::endl;
		return;
	}
	this->__energyPoints--;
	std::cout << "ScavTrap " << this->__name << " attacks " << target << ", causing " << this->__attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) { std::cout << "ScavTrap " << this->__name << " is now in Gate keeper mode." << std::endl; }
