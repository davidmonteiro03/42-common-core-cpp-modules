/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:05:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 16:41:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : __name(""),
						   __hitPoints(10),
						   __energyPoints(10),
						   __attackDamage(0) { std::cout << "ClapTrap default constructor called" << std::endl; }

ClapTrap::ClapTrap(const std::string &name) : __name(name),
											  __hitPoints(10),
											  __energyPoints(10),
											  __attackDamage(0) { std::cout << "ClapTrap std::string constructor called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap &copy) : __name(copy.__name),
										   __hitPoints(copy.__hitPoints),
										   __energyPoints(copy.__energyPoints),
										   __attackDamage(copy.__attackDamage) { std::cout << "ClapTrap copy constructor called" << std::endl; }

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->__name = other.__name;
		this->__hitPoints = other.__hitPoints;
		this->__energyPoints = other.__energyPoints;
		this->__attackDamage = other.__attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor called" << std::endl; }

void ClapTrap::attack(const std::string &target)
{
	if (this->__hitPoints == 0 || this->__energyPoints == 0)
	{
		std::cout << "Claptrap " << this->__name << " has no hit points or energy points left." << std::endl;
		return;
	}
	this->__energyPoints--;
	std::cout << "ClapTrap " << this->__name << " attacks " << target << ", causing " << this->__attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->__hitPoints == 0 || this->__energyPoints == 0)
	{
		std::cout << "Claptrap " << this->__name << " has no hit points or energy points left." << std::endl;
		return;
	}
	this->__hitPoints -= amount > this->__hitPoints ? this->__hitPoints : amount;
	std::cout << "ClapTrap " << this->__name << " took " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->__hitPoints == 0 || this->__energyPoints == 0)
	{
		std::cout << "Claptrap " << this->__name << " has no hit points or energy points left." << std::endl;
		return;
	}
	this->__energyPoints--;
	this->__hitPoints += amount;
	std::cout << "ClapTrap " << this->__name << " repaired itself, regaining " << amount << " hit points!" << std::endl;
}
