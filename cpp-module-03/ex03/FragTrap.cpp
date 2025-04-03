/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:05:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/03 08:01:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitPoints = FragTrap::_MAX_HIT_POINTS;
	this->_energyPoints = FragTrap::_MAX_ENERGY_POINTS;
	this->_attackDamage = FragTrap::_MAX_ATTACK_DAMAGE;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap std::string constructor called" << std::endl;
	this->_hitPoints = FragTrap::_MAX_HIT_POINTS;
	this->_energyPoints = FragTrap::_MAX_ENERGY_POINTS;
	this->_attackDamage = FragTrap::_MAX_ATTACK_DAMAGE;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) { std::cout << "FragTrap copy constructor called" << std::endl; }

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

void FragTrap::highFivesGuys(void) { std::cout << "FragTrap " << this->_name << " requests a positive high-fives." << std::endl; }
