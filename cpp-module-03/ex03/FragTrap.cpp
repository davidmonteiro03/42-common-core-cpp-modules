/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:07:54 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/15 23:15:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << std::endl
			  << "FragTrap default constructor for " << _name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref._name)
{
	std::cout << std::endl
			  << "FragTrap copy constructor for " << _name << " called" << std::endl;
	*this = ref;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << std::endl
			  << "FragTrap assignment operator for " << _name << " called" << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << std::endl
			  << "FragTrap destructor for " << _name << " called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_energyPoints <= 0)
	{
		std::cout << std::endl
				  << "FragTrap " << _name << " has no energy points!" << std::endl;
		return;
	}
	if (_hitPoints <= 0)
	{
		std::cout << std::endl
				  << "FragTrap " << _name << " is dead!" << std::endl;
		return;
	}
	std::cout << std::endl
			  << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void FragTrap::highFivesGuys()
{
	if (_hitPoints <= 0)
	{
		std::cout << std::endl
				  << "FragTrap " << _name << " is dead!" << std::endl;
		return;
	}
	std::cout << std::endl
			  << "FragTrap " << _name << " high fives guys." << std::endl;
}
