/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:05:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 16:41:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->__name = this->ClapTrap::__name;
	this->ClapTrap::__name = this->__name + "_clap_name";
	this->__hitPoints = FragTrap::_hitPoints;
	this->__energyPoints = ScavTrap::_energyPoints;
	this->__attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap std::string constructor called" << std::endl;
	this->__name = this->ClapTrap::__name;
	this->ClapTrap::__name = this->__name + "_clap_name";
	this->__hitPoints = FragTrap::_hitPoints;
	this->__energyPoints = ScavTrap::_energyPoints;
	this->__attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->__name = copy.__name;
	this->ClapTrap::__name = copy.ClapTrap::__name;
	this->__hitPoints = copy.__hitPoints;
	this->__energyPoints = copy.__energyPoints;
	this->__attackDamage = copy.__attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->__name = other.__name;
		this->ClapTrap::__name = other.ClapTrap::__name;
		this->__hitPoints = other.__hitPoints;
		this->__energyPoints = other.__energyPoints;
		this->__attackDamage = other.__attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor called" << std::endl; }

void DiamondTrap::whoAmI(void) { std::cout << "DiamondTrap " << this->__name << " is also known as " << this->ClapTrap::__name << std::endl; }
