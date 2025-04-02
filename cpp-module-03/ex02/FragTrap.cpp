/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:05:12 by dcaetano          #+#    #+#             */
/*   Updated: 2025/04/02 16:18:09 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->__hitPoints = FragTrap::_hitPoints;
	this->__energyPoints = FragTrap::_energyPoints;
	this->__attackDamage = FragTrap::_attackDamage;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap std::string constructor called" << std::endl;
	this->__hitPoints = FragTrap::_hitPoints;
	this->__energyPoints = FragTrap::_energyPoints;
	this->__attackDamage = FragTrap::_attackDamage;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) { std::cout << "FragTrap copy constructor called" << std::endl; }

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->__name = other.__name;
		this->__hitPoints = other.__hitPoints;
		this->__energyPoints = other.__energyPoints;
		this->__attackDamage = other.__attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

void FragTrap::highFivesGuys(void) { std::cout << "FragTrap " << this->__name << " requests a positive high-fives." << std::endl; }
