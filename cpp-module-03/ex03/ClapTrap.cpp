/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:05:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 07:59:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""),
						   _hitPoints(10),
						   _energyPoints(10),
						   _attackDamage(0) { std::cout << "ClapTrap default constructor called" << std::endl; }

ClapTrap::ClapTrap(const std::string &name) : _name(name),
											  _hitPoints(10),
											  _energyPoints(10),
											  _attackDamage(0) { std::cout << "ClapTrap std::string constructor called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name),
										   _hitPoints(copy._hitPoints),
										   _energyPoints(copy._energyPoints),
										   _attackDamage(copy._attackDamage) { std::cout << "ClapTrap copy constructor called" << std::endl; }

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor called" << std::endl; }

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout << "Claptrap " << this->_name << " has no hit points or energy points left." << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout << "Claptrap " << this->_name << " has no hit points or energy points left." << std::endl;
		return;
	}
	this->_hitPoints -= amount > this->_hitPoints ? this->_hitPoints : amount;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		std::cout << "Claptrap " << this->_name << " has no hit points or energy points left." << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " repaired itself, regaining " << amount << " hit points!" << std::endl;
}
