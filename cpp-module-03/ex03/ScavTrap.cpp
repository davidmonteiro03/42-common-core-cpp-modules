/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:05:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 08:03:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitPoints = ScavTrap::_MAX_HIT_POINTS;
	this->_energyPoints = ScavTrap::_MAX_ENERGY_POINTS;
	this->_attackDamage = ScavTrap::_MAX_ATTACK_DAMAGE;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap std::string constructor called" << std::endl;
	this->_hitPoints = ScavTrap::_MAX_HIT_POINTS;
	this->_energyPoints = ScavTrap::_MAX_ENERGY_POINTS;
	this->_attackDamage = ScavTrap::_MAX_ATTACK_DAMAGE;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) { std::cout << "ScavTrap copy constructor called" << std::endl; }

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no hit points or energy points left." << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) { std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl; }
