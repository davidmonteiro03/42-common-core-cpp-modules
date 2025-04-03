/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:05:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 08:05:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->__name = this->ClapTrap::_name;
	this->ClapTrap::_name = this->__name + "_clap_name";
	this->_hitPoints = FragTrap::_MAX_HIT_POINTS;
	this->_energyPoints = ScavTrap::_MAX_ENERGY_POINTS;
	this->_attackDamage = FragTrap::_MAX_ATTACK_DAMAGE;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap std::string constructor called" << std::endl;
	this->__name = this->ClapTrap::_name;
	this->ClapTrap::_name = this->__name + "_clap_name";
	this->_hitPoints = FragTrap::_MAX_HIT_POINTS;
	this->_energyPoints = ScavTrap::_MAX_ENERGY_POINTS;
	this->_attackDamage = FragTrap::_MAX_ATTACK_DAMAGE;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->__name = copy.__name;
	this->ClapTrap::_name = copy.ClapTrap::_name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->__name = other.__name;
		this->ClapTrap::_name = other.ClapTrap::_name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor called" << std::endl; }

void DiamondTrap::whoAmI(void) { std::cout << "DiamondTrap " << this->__name << " is also known as " << this->ClapTrap::_name << std::endl; }
